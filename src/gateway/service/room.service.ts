import { RoomInterface } from '../interface/room.interface';
import { Socket } from 'socket.io';
import { GameService } from '../../game/service/game.service';
import { PongService } from './pong.service';
import { MatchStatus } from '../../game/enum/MatchStatus';

export class RoomService {
  waitingUsers: Array<Socket> = [];
  rooms: Map<string, RoomInterface> = new Map();
  pongGames: Map<string, PongService> = new Map();
  roomFromPlayer: Map<string, string> = new Map();

  constructor(private readonly gameService: GameService) {}

  async joinWaitingRoom(client: Socket, server: any) {
    if (this.waitingUsers.includes(client)) {
      return;
    }

    if (await this.gameService.isMatchHistoryExist(client.id)) {
      console.log('match already exists');
      server.to(client.id).emit('message', 'match already exists');
      return;
    }

    this.waitingUsers.push(client);
    if (this.waitingUsers.length > 1) {
      await this.createRoom(client, server);
      return;
    }
  }

  async createRoom(client: Socket, server: any) {
    const namePlayer1 = client.id;
    const socketPlayer2 = this.waitingUsers.find(
      (user) => user.id !== namePlayer1,
    );
    const namePlayer2 = socketPlayer2.id;

    const roomName: string = this.createRoomName(namePlayer1, namePlayer2);
    const room: RoomInterface = {
      player1: namePlayer1,
      player2: namePlayer2,
      roomName: roomName,
    };

    this.rooms.set(roomName, room);

    client.join(roomName);
    socketPlayer2.join(roomName);

    // add users to roomFromPlayer
    this.roomFromPlayer.set(namePlayer1, roomName);
    this.roomFromPlayer.set(namePlayer2, roomName);

    // add users to MatchHistoryEntity
    await this.gameService.createMatchHistory(
      namePlayer1,
      namePlayer2,
      roomName,
    );

    // create pong game
    const pongGame = new PongService(
      this.gameService,
      namePlayer1,
      namePlayer2,
    );

    // asign pong game to room
    this.pongGames.set(roomName, pongGame);

    // get pong game state
    const pongGameState = pongGame.getGameState();

    // emit game state to all users in room
    this.emitToRoom(server, roomName, 'toGame', pongGameState);

    // remove users from waiting room
    this.waitingUsers = this.waitingUsers.filter(
      (user) => user.id !== namePlayer1 && user.id !== namePlayer2,
    );

    // debug
    server.to(client.id).emit('message', 'partida encontrada');
  }

  async startGame(client: Socket, server: any) {
    if (await this.gameService.isMatchHistoryExist(client.id)) {
      const roomName = await this.gameService.getRoomId(client.id);
      const match = await this.gameService.getByRoomName(roomName);

      // ready player client
      match.readyPlayer(client.id);
      this.emitToRoom(
        server,
        roomName,
        'message',
        'player ' + client.id + ' ready',
      );

      // update match
      await this.gameService.updateMatch(match);

      if (match.isReady() && match.status === MatchStatus.IS_WAITING) {
        // start game
        const pongGame = this.pongGames.get(roomName);
        pongGame.startGameLoop(roomName, server);

        // update match
        match.status = MatchStatus.IS_PLAYING;
        await this.gameService.updateMatch(match);

        // emit game state to all users in room
        this.emitToRoom(server, roomName, 'message', 'game started');
        return;
      }
    }
  }

  async moveUp(client: Socket) {
    const roomName = this.roomNameFromClient(client);
    const pongGame = this.pongGames.get(roomName);

    pongGame.moveUp(client.id);
  }

  async moveDown(client: Socket) {
    const roomName = this.roomNameFromClient(client);
    const pongGame = this.pongGames.get(roomName);

    pongGame.moveDown(client.id);
  }

  async endGame(client: Socket, server: any) {
    const roomName = this.roomNameFromClient(client);
    const pongGame = this.pongGames.get(roomName);

    await pongGame.stopGameLoop();

    // emit game state to all users in room
    this.emitToRoom(
      server,
      roomName,
      'message',
      'user ' + client.id + ' give up',
    );

    // remove room
    this.rooms.delete(roomName);

    // remove pong game
    this.pongGames.delete(roomName);

    // remove room from roomFromPlayer
    this.roomFromPlayer.delete(client.id);
    this.roomFromPlayer.delete(pongGame.getOpponentName(client.id));
  }

  private roomNameFromClient(client: Socket): string {
    return this.roomFromPlayer.get(client.id);
  }

  private emitToRoom(server: any, roomName: string, event: string, data: any) {
    const room = this.rooms.get(roomName);

    server.to(room.player2).emit(event, data);
    server.to(room.player1).emit(event, data);
  }

  private createRoomName(user1: string, user2: string): string {
    return `${user1}-${user2}-${Date.now()}`;
  }
}
