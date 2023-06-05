import {
  Text,
  HStack,
  VStack,
  Stack,
  RadioGroup,
  Radio,
  Button,
} from "@chakra-ui/react";
import { useState } from "react";
import './Pong.css'
import { useNavigate, useLocation } from "react-router-dom";

export default function Me(){
  const [selectedField, setSelectedField] = useState('Classico')
  const [selectedMode, setSelectedMode] = useState('Online')
  const [selectedNumberPlayers, setSelectedNumberPlayers] = useState('1')
  const navigate = useNavigate();
  const { state } = useLocation();

  const getFields = (type: string) =>{
    if(type == "Tenis" || type == "Basquete" || type == "Futebol") return type;
    else return "Classico"
  }

  const fieldsPath = {
    Classico: "",
    Basquete: "../../../docs/images/basquete2.png",
    Futebol: "../../../docs/images/campo.jpg",
    Tenis: "../../../docs/images/tenis1.jpg",
  }

  const ballsPath = {
    Classico: "",
    Basquete: "../../../docs/images/bolabasquete4.png",
    Futebol: "../../../docs/images/bolaFutebol1.png",
    Tenis: "../../../docs/images/bolaTenis3.png",
  }

  const fields = {
    Classico: "",
    Basquete: "BasketeBackground",
    Futebol: "SoccerBackground",
    Tenis: "TenisBackground",
  }


  return  (
    <>
      <VStack className={fields[getFields(selectedField)]} h="100%" w={"100%"} borderRadius={"20px"} align={"center"} background={getFields(selectedField) == "Classico" ? "black" : ""}>
        <Text
          fontSize={"70px"}
          fontWeight={"bold"}
          textColor={selectedField == "Classico" ? "white" : "black"}
          textAlign="center"
        >
            Pong
        </Text>
        <HStack w={"100%"} h={"50%"} justify={"center"} >
          <VStack background={"white"} border={"8px"} borderColor={"#805AD5"} borderTopRadius={"20px"} borderBottomRadius={"20px"}>
            <Text
              fontSize={"20px"}
              fontWeight={"bold"}
              textColor="black"
              textAlign="center"
            >
              Modo
            </Text>
            <RadioGroup onChange={setSelectedMode} value={selectedMode}>
              <Stack spacing={5}>
                <Radio value='Online' size={"lg"}>Online</Radio>
                <Radio value='Offline' size={"lg"}>Offline</Radio>
              </Stack>
            </RadioGroup>
          </VStack>
          {selectedMode == "Offline" ? (
            <VStack background={"white"} border={"8px"} borderColor={"#805AD5"} borderTopRadius={"20px"} borderBottomRadius={"20px"}>
              <Text
                fontSize={"20px"}
                fontWeight={"bold"}
                textColor="black"
                textAlign="center"
              >
                {"Player(s)"}
              </Text>
              <RadioGroup onChange={setSelectedNumberPlayers} value={selectedNumberPlayers}>
                <Stack spacing={5}>
                  <Radio value='1' size={"lg"}>1 Player</Radio>
                  <Radio value='2' size={"lg"}>2 Players</Radio>
                </Stack>
              </RadioGroup>
            </VStack>) : null}
          <VStack background={"white"} border={"8px"} borderColor={"#805AD5"} borderTopRadius={"20px"} borderBottomRadius={"20px"}>
            <Text
              fontSize={"20px"}
              fontWeight={"bold"}
              textColor="black"
              textAlign="center"
            >
              Campo
            </Text>
            <RadioGroup onChange={setSelectedField} value={selectedField}>
              <Stack spacing={5}>
                <Radio value='Classico' size={"lg"} fontWeight={"bold"}>Clássico</Radio>
                <Radio value='Futebol' size={"lg"}>Futebol</Radio>
                <Radio value='Basquete' size={"lg"}>Basquete</Radio>
                <Radio value='Tenis' size={"lg"}>Tenis</Radio>
              </Stack>
            </RadioGroup>
          </VStack>
        </HStack>
        <Button
        colorScheme={"purple"}
        marginLeft="20px"
        paddingLeft="70px"
        paddingRight="70px"
        onClick={() => {
          const pathGame = selectedMode == "Online" ? "/home/pong/game" : "/home/pong/gameoffline"
          navigate(pathGame, {
            state: {
              field: fieldsPath[getFields(selectedField)],
              ball: ballsPath[getFields(selectedField)],
              fromInvite: state?.fromInvite,
            },
          });
        }}
        >
        {selectedMode == "Online" ? "Pesquisar" : "Jogar"}
        </Button>
      </VStack>
    </>
  );
}