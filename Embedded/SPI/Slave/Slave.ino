#define SCK_Slave 5
#define	MOSI_Slave 3
#define MISO_Slave 4
#define SS_Slave 2

#define SCK_OUTPUT DDRB &= ~(1 << DDB5)     //pinMode(SCK_Slave, OUTPUT);
#define MOSI_OUTPUT DDRB &= ~(1 << DDD3)    //pinMode(MOSI_Slave, OUTPUT);
#define SS_OUTPUT DDRB &= ~(1 << DDB2)      //pinMode(SS_Slave, OUTPUT);
#define MISO_INPUT DDRB |= (1 << DDB4)    //pinMode(MISO_Slave, INPUT);

#define read_SCK() ((PINB & (1 << PINB5)) ? HIGH:LOW)
#define read_MOSI() ((PINB & (1 << PINB3)) ? HIGH:LOW)
#define read_SS() ((PINB & (1 << PINB2)) ? HIGH:LOW)

#define write_MISO(x) PORTB = ((x) ? (PORTB | 1 << PB4) : (PORTB & (~(1 << PB4))) )


void setup() {
  Slave_setup();
  Serial.begin(115200);

}

void loop() {
  
  uint8_t receive;
  receive = Slave_transfer(255);
  Serial.println(receive);
  

}

/*
* Function: Slave_setup
* Description: Setting up initial conditons for Slave
* Input:
*  uint8_t: data_out
* Output:
*   return: None
*/
void Slave_setup(void){
  SCK_OUTPUT;
  MOSI_OUTPUT;
  SS_OUTPUT;
  MISO_INPUT;
}

/*
* Function: Slave_transfer
* Description: Stop transferring data process
* Input:
*  uint8_t: data_out
* Output:
*   return: None
*/

uint8_t Slave_transfer(uint8_t data_out){
  uint8_t data_in = 0;
  uint8_t ibit, result;

  for(ibit = 0x80; ibit > 0; ibit = ibit >> 1){
    
    result = data_out & ibit;
    write_MISO(result);

    while(read_MOSI() == LOW){}
    if(read_MOSI() == HIGH)
        data_in = data_in | ibit;
      
    while (read_SCK() == HIGH)


     return data_in;
  }
  
}
 

