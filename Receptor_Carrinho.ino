#include <VirtualWire.h>
#include <SoftwareServo.h> //Inclui a biblioteca SoftwareServo.h

SoftwareServo servo1;
SoftwareServo servo2;
void setup()
{   
    Serial.begin(9600);	// Velocidade do Monitor Serial
    Serial.println("Esperando conectar o DATA no Pin 11");

    pinMode(13,OUTPUT);
    servo1.attach(9);
    servo1.setMaximumPulse(2200);
    servo2.attach(10);
    servo2.setMaximumPulse(2200);
    Serial.begin(9600);
    Serial.print("Ready");
  
    // Initialise the IO and ISR
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);	 // Bits per sec

    vw_rx_start();       // Start the receiver PLL running
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
	int i;

        digitalWrite(13, true); // Flash a light to show received good message
	// Message with a good checksum received, dump it.
	//Serial.print("Got: ");
	
	//Serial.print(buf[i], HEX);
	//Serial.println("");
        //Serial.print(buf[i]);

              if(buf[i]==82)
              {
               
              
                for (i = 0; i < 100; i++)
               { 
                 Serial.print(" Recebeu sinal ");                
                servo1.write(180);
                servo2.write(89);
                SoftwareServo::refresh();
               }
              } 
              
              else if(buf[i]==76)
              {
               
              
                for (i = 0; i < 100; i++)
               { Serial.print(" Recebeu sinal ");
                servo1.write(180);
                servo2.write(0);
                SoftwareServo::refresh();
               }
              } 
              
              else if(buf[i]==70)
              {
               
              
                for (i = 0; i < 100; i++)
               { Serial.print(" Recebeu sinal ");
                servo1.write(180);
                servo2.write(0);
                SoftwareServo::refresh();
               }
              } 
              
              else if(buf[i]==66)
              {
               
              
                for (i = 0; i < 100; i++)
               { //Serial.print(" Recebeu sinal ");
               delay(50);
                servo1.write(180);
                servo2.write(0);
                SoftwareServo::refresh();
               }
              }
             
               
               }

             
                                   
	}       


