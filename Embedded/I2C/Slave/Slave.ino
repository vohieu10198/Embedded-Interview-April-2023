#define SLAVE_SDA 4
#define SLAVE_SCL 5

#define SLAVE_SDA_OUTPUT DDRC |= (1 << DDC4) 
#define SLAVE_SCL_OUTPUT DDRC |= (1 << DDC5)

#define SLAVE_SDA_INPUT DDRC &= ~(1 << DDC4)
#define SLAVE_SCL_INPUT DDRC &= ~(1 << DDC5)

#define SLAVE_SDA_HIGH PORTC |= (1 << PC4) //SDA = 1
#define SLAVE_SCL_HIGH PORTC |= (1 << PC5) //SCL =1

#define SLAVE_SDA_LOW PORTC &= ~(1 << PC4) // SDA = 0
#define SLAVE_SCL_LOW PORTC &= ~(1 << PC5) // SCL = 0

#define SLAVE_SDA_READ (PINC & (1 << PINC4)) >> PINC4
#define SLAVE_SCL_READ (PINC & (1 << PINC5)) >> PINC5

#define FULL 50
#define HALF 25


void setup() {
  
  Serial.begin(9600);
  delay(100);
  
}

void loop() {

  byte receive[10] = {0};
  uint8_t slave_begin;
  uint8_t check;
  
  slave_begin = slaveBegin(0x18);
  if(slave_begin == 0){
    slaveReadBytes(receive,6);
    Serial.println("Master wants to write data");
    Serial.println(String((char*)receive));
  }else if(slave_begin == 1){
    check = slaveWrite("Slave");
    Serial.println("Master wants to read data");
    if (check == 1){
      Serial.println("Write successfully");
    }else if (check == -1){
      Serial.println("Write successfully");
    }else{
      Serial.println("Something Wrong");
    }
  }else if(slave_begin == 2){
    Serial.println("This is not my address, bruhhhh");
  }else{
    Serial.println("Uncontrolled case!!!");
  }

  //delay(1000);
}

int8_t slaveBegin(byte address){
  uint8_t data = 0, i;
  uint8_t readWrite = 0;

  while(true){

    SLAVE_SDA_INPUT;
    SLAVE_SCL_INPUT;
  
    while(SLAVE_SDA_READ != 1 || SLAVE_SCL_READ != 1 );

    while(SLAVE_SDA_READ == 1);

    delayMicroseconds(HALF/2);

    if(SLAVE_SCL_READ == 1){

      while (SLAVE_SDA_READ == 1);

        for(i = 0; i < 8; i++){

          while(SLAVE_SDA_READ == 0)
          data = (data << 1)  | SLAVE_SDA_READ;
          while (SLAVE_SDA_READ == 1);
         } 
        
        readWrite = data & 1;
        data = data >> 1;

        if (data = address){
          slaveSendACK();
          return readWrite;
        }else{
          return 2;
        }
    }else{}
  }
}

int8_t slaveReadOneByte(void){

  SLAVE_SDA_INPUT;
  SLAVE_SCL_INPUT;

  uint8_t data, i;

  for(i = 0; i < 8; i++){

    while(SLAVE_SDA_READ == 0)
      data = (data << 1)  | SLAVE_SDA_READ;
      while (SLAVE_SDA_READ == 1);
    } 
    slaveSendACK();

    return data;

}

void slaveReadBytes(byte *data, int8_t count){
  uint8_t i;
  for(i = 0; i < count; i++){
    *data = slaveReadOneByte();
    data++;
  }
}

void slaveWriteByte(byte data){

  uint8_t i;
  SLAVE_SDA_OUTPUT;
  for (i = 0; i < 8; i++){
    if((data & 0x80) == 0x80){
    SLAVE_SDA_HIGH;
    }else{
      SLAVE_SDA_LOW;
    }
    data = data << 1;
    while(SLAVE_SCL_READ == 0);
    while(SLAVE_SCL_READ == 1);
  }
  //SLAVE_SDA_INPUT;
}

byte slaveWrite(char *data){

  uint8_t ack;
  while(*data != '\0'){
    slaveWriteByte(*data);
    ack = slaveReadACK();
    if(ack == 1){
      SLAVE_SDA_INPUT;
      return -1;
    }
  }
  SLAVE_SDA_INPUT;
  return 1;
}

uint8_t slaveReadACK(void){
  uint8_t ACK;
  SLAVE_SDA_INPUT;
  while(SLAVE_SCL_READ == 0);
  ACK = SLAVE_SDA_READ;
  while(SLAVE_SCL_READ == 1);
  return ACK;
}

void slaveSendACK(void){

  SLAVE_SDA_OUTPUT;
  SLAVE_SDA_LOW;
  while(SLAVE_SCL_READ == 0);
  while(SLAVE_SCL_READ == 1);
  SLAVE_SDA_INPUT;
  
}