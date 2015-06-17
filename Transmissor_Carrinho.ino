#include <VirtualWire.h> //Inclui a biblioteca VirtualWire.h
 
char *letra = "S"; //Cria a variável letra com o valor "S"
 
void setup()
{
  Serial.begin(9600);	// Debugging only
  Serial.println("setup");

  //++++++++++++++Inicializa o módulo transmissor+++++++++++++++++++
  vw_set_ptt_inverted(true); //Configuração da Biblioteca
  vw_setup(2000); //Configuração da Biblioteca
  //vw_set_tx_pin(3);
  //Configura o pino D3 para a leitura dos dados
  //================================================================

  //Configura os pinos 1, 6, 7, e 12 como entrada
  //e resistor de pullup ativo
  pinMode(1,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  //======================================

}

void loop()
{
  //Verifica se tem algum botão pressionado para enviar a seu respectivo comando (letra)
  if(!digitalRead(9)) letra = "F"; //Envia "F" se D12 = LOW (Bottão Pressionado)
  else if(!digitalRead(1)) letra = "B"; //Envia "B" se D1 = LOW (Bottão Pressionado)
  else if(!digitalRead(6)) letra = "R"; //Envia "R" se D6 = LOW (Bottão Pressionado)
  else if(!digitalRead(7)) letra = "L"; //Envia "L" se D7 = LOW (Bottão Pressionado)
  //=======================================================================
  
  //Senão, se nenhum botão for pressionado, enviar "S"
  else 
  {
  Serial.println("Não encontrou nada");  //Envia "S" se nenhum botão for pressionado
  letra= "S";
  }
  //==================================================
  
  //Transmiste a variável letra 3 vezes
  for(int i=0 ; i<3 ; i++)
  {
  vw_send((uint8_t *)letra, strlen(letra)); //Envia a variável letra
  vw_wait_tx(); //Aguarda o fim de transmissão
  Serial.println(letra);
  delay(200); //Aguarda 10 milissegundos
  }
  //===================================
}

