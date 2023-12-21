
/*

ESBOÇO DO PROJETO MAQUINA BRAILE (Parte Funcional do Teclado) - Braile Machine Project Outline (Keyboard Fuctional System)

AUTOR: Isac Eugenio da Silva Santos 

PLACA USADA: ARDUINO UNO R3


Data: 21/12/2023 (DD/MM/YYYY)

Versão 1.0

*/

//------ARRAY BINARIO DO ALFABETO EM BRAILE-----

const String Letras_Bit[26]=
{"100000",//A
 "110000",//B
 "100100",//C
 "100110",//D
 "100010",//E
 "110100",//F
 "110110",//G
 "110010",//H
 "010100",//I
 "010110",//J
 "101000",//K
 "111000",//L
 "101100",//M
 "101110",//N
 "101010",//O
 "111100",//P
 "111110",//Q
 "111010",//R
 "011100",//S
 "011110",//T
 "101001",//U
 "111001",//V
 "010111",//W
 "101101",//X
 "101111",//Y
 "101011" //Z
 };

//------ FIM ARRAY BINARIO DO ALFABETO EM BRAILE -----

//-------ARRAY DOS CARACTERES DO ALFABETO------------

const String Letras_Char[26] = 
{
 "A",
 "B",
 "C",
 "D",
 "E", 
 "F", 
 "G", 
 "H", 
 "I", 
 "J", 
 "K", 
 "L", 
 "M", 
 "N", 
 "O", 
 "P", 
 "Q", 
 "R", 
 "S", 
 "T", 
 "U", 
 "V", 
 "W", 
 "X", 
 "Y", 
 "Z"
};

//-------FIM ARRAY DOS CARACTERES DO ALFABETO------------

//--------------VARIAVEIS GLOBAIS--------------------

const int Botao[7]={2,3,4,5,6,7,8};      // ENDERAÇAMENTO DOS PINOS DOS BOTÕES NA CELA

const int Botao_OK = Botao[6];         //   DESTAQUE NO ENDEREÇO DO BOTAO DE CONFIRMAÇÃO

static int Estados_Botao[6];         //     ARRAY PARA ARMAZENAR OS DADOS DOS BOTÕES

int Leitura[6];                    //       ARRAY PARA ARMAZENAR A LEITURA DOS BOTÕES

String Leitura_Total = "";       //         STRING PARA ARMAZENAR        

bool OK = 0;                   //           VARIAVEL PARA LEITURA DO BOTAO DE CONFIRMAÇÃO


//-----------FIM VARIAVEIS GLOBAIS--------------------

//--------------SETUP---------------------------------

void setup() {


     Serial.begin(115200);  //INICIALIZAR A SERIAL PARA USO COMO INTERFACE TESTE

     for(int i = 0; i <= 6; i++)pinMode(Botao[i],INPUT); //DEFINIÇÃO DOS BOTOES COMO LEITURA INCLUSIVE O BOTAO DE CONFIMAÇÃO


}

//--------------FIM SETUP---------------------------------

//------------------ LOOP --------------------------------

void loop() {
     
     OK = digitalRead(Botao_OK);                 // LEITURA DO BOTÃO DE CONFIRMAÇÃO 

     for(int i = 0; i <= 5; i++){

         Leitura[i] = digitalRead(Botao[i]);   // LEITURA DOS BOTOES DA CELA

        if(Leitura[i] == 1)Estados_Botao[i]++;  // LOGICA PARA GUARDAR A INFORMAÇÃO DA QUANTIDADES DE VEZES O BOTAO FOI  PRESSIONADO

        if(Estados_Botao[i] >= 2) Estados_Botao[i] = 0;  // LIMITADOR DA QUANTIDADES DE VEZES O BOTAO POSSA PRESSIONADO
     
     }


     // VARIAVEL COLETA OS DADOS DOS BOTOES E ARMAZENA EM UMA STRING UNICA 

     Leitura_Total = String(Estados_Botao[0])+String(Estados_Botao[1])+String(Estados_Botao[2])+String(Estados_Botao[3])+String(Estados_Botao[4])+String(Estados_Botao[5]);
     
     
     if(OK == 1){ // QUANDO O BOTAO DE CONFIRMAÇÃO FOR PRESSIONADO

         for(int i = 0; i <= 25; i++){

          if(Leitura_Total == Letras_Bit[i]) Serial.print(Letras_Char[i]); // VERIFICAÇÃO DA SEQUENCIA PRESSIONADA 

          else if(Leitura_Total != Letras_Bit[i]) for(int i = 0; i <= 5; i++)Estados_Botao[i] = 0; // RESETA OS BOTOES 
          
         }

     }

     delay(100); // DELAY PARA ESTABILIZAR O CODIGO 

}

//----------------- FIM LOOP --------------------------------


