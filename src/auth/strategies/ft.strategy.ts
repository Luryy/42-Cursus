import { Injectable } from '@nestjs/common';
import { PassportStrategy } from '@nestjs/passport';
import { Strategy } from 'passport-42';
import { AuthDto } from '../dto/auth.dto';
import { UserService } from '../../user/service/user.service';
import { AvatarService } from '../../avatar/service/avatar.service';

@Injectable()
export class FtStrategy extends PassportStrategy(Strategy) {
  constructor(
    private readonly userService: UserService,
    private readonly avatarService: AvatarService,
  ) {
    super({
      clientID: process.env.FORTYTWO_CLIENT_ID,
      clientSecret: process.env.FORTYTWO_CLIENT_SECRET,
      callbackURL: process.env.AUTH_CALLBACK,
    });
  }

  async validate(accessToken: string, refreshToken: string, profile) {
    const { login, image } = profile._json;
    const authDto: AuthDto = AuthDto.fromJSON(profile._json);

    if (!(await this.userService.userExists(login))) {
      console.log(image.link);
      authDto.image = await this.avatarService.downloadImageFromUrl(image.link);
      await this.userService.createUser(authDto);
    }
    return {
      username: login,
      image: image.link,
      accessToken,
    };
  }
}
