#define TFull 50
#define THalf TFull/2

#define SCK_Master 5
#define	MOSI_Master 3
#define MISO_Master 4
#define SS_Master 2

#define SCK_OUTPUT DDRB |= (1 << DDB5)     //pinMode(SCK_Master, OUTPUT);
#define MOSI_OUTPUT DDRB |= (1 << DDB3)    //pinMode(MOSI_Master, OUTPUT);
#define SS_OUTPUT DDRB |= (1 << DDB2)      //pinMode(SS_Master, OUTPUT);
#define MISO_INPUT DDRB &= ~(1 << DDB4)    //pinMode(MISO_Master, INPUT);

// #define MOSI_HIGH PORTD |= (1 << PD11)      //digitalWrite(MOSI_Master, HIGH);
// #define MOSI_LOW PORTD &= ~(1 << PD11)      //digitalWrite(MOSI_Master, LOW);

#define write_MOSI(x) PORTB = ((x) ? (PORTB | 1 << PB3) : (PORTB & (~(1 << PB3))) )
#define write_SS(x) PORTB = ((x) ? (PORTB | 1 << PB2) : (PORTB & (~(1 << PB2))) )
#define write_SCK(x) PORTB = ((x) ? (PORTB | 1 << PB5) : (PORTB & (~(1 << PB5))) )

#define read_MISO() ((PINB & (1 << PINB4)) ? HIGH:LOW)

void setup(){
  Master_setup();
  Serial.begin(115200);
}

void loop(){
  uint8_t receive;
  Master_start();
  receive = Master_Transfer(128);
  Master_end();
  Serial.println(receive);
  // Serial.println(String(receive));
  
}


/*
* Function: SPI_setup
* Description: Setting initial status
* Input:
*  None
* Output:
*   return: None
*/
void Master_setup(void){
  MOSI_OUTPUT;
  MISO_INPUT;
  write_SCK(LOW);
  SCK_OUTPUT;
  write_SS(HIGH);
  SS_OUTPUT;
  delay(1);
}

/*
* Function: SPI_start
* Description: starting to transfer data
* Input:
*  None
* Output:
*   return: None
*/
void Master_start(void) {
  write_SS(LOW);
}

/*
* Function: SPI_end
* Description: Stop transferring data process
* Input:
*  None
* Output:
*   return: None
*/
void Master_end(void){
  write_SCK(LOW);
  write_SS(HIGH);
}

/*
* Function: SPI_Transfer
* Description: Stop transferring data process
* Input:
*  uint8_t: data_out
* Output:
*   return: None
*/
uint8_t Master_Transfer(uint8_t data_out){
  uint8_t data_in = 0;
  uint8_t ibit, result;

  for(ibit = 0x80;  ibit > 0; ibit = ibit >> 1 ){ //ibit = 1000 0000
    result  = data_out & ibit;
    write_MOSI(result);

    delayMicroseconds(25);
    write_SCK(HIGH);

    if(read_MISO() == HIGH)
      data_in = data_in | ibit; // 0000 0000 | 1000 0000 = 1000 0000
      delayMicroseconds(25);
      write_SCK(LOW); //end 1 clock cycle
    
  }

   return data_in;

}




