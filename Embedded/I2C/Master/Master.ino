/*
  File: Master.ino
  Author: Vo MINH HIEU
  Date: 20/06/2023
  Description: Simulation I2C protocol
*/

#define MASTER_SDA 4
#define MASTER_SCL 5

#define MASTER_SDA_OUTPUT DDRC |= (1 << DDC4) 
#define MASTER_SCL_OUTPUT DDRC |= (1 << DDC5)

#define MASTER_SDA_INPUT DDRC &= ~(1 << DDC4)
#define MASTER_SCL_INPUT DDRC &= ~(1 << DDC5)

#define MASTER_SDA_HIGH PORTC |= (1 << PC4) //SDA = 1
#define MASTER_SCL_HIGH PORTC |= (1 << PC5) //SCL =1

#define MASTER_SDA_LOW PORTC &= ~(1 << PC4) // SDA = 0
#define MASTER_SCL_LOW PORTC &= ~(1 << PC5) // SCL = 0

#define MASTER_SDA_READ (PINC & (1 << PINC4)) >> PINC4
#define MASTER_SCL_READ (PINC & (1 << PINC5)) >> PINC5


#define FULL 50
#define HALF 25

void setup() {

  delay(100);
  Serial.begin(96000);

}

void loop() {
  byte receive[10] = {0};
  int8_t result1;
  result1 = Master_ReadData(0x18, receive, 6);
  if (result1 == 1){
    Serial.print("Read successfully");
    Serial.println(String((char*)receive));
  }else if(result1 == -1){
    Serial.print("Read fail");
  }
  delay(1000);

  int8_t result2 = Master_WriteData(0x55,"Master");
  Serial.println(result2);
  delay(1000);
  
}

int8_t Master_ReadData(byte address, byte *data, byte count){
 
  uint8_t ACK,i;
  Master_StartConditions();
  address = (address << 1) + 1;
  Master_WriteOneByte(address);
  ACK = Master_ReadACK();
  if(ACK == 1){
    Master_StopConditions();
    return -1;
  }

  for(i = 0; i < count; i++){
    *data = Master_ReadOneByte();
    data++;
    Master_SendACK();
  }

  Master_StopConditions();
  return 1;

}

int8_t Master_WriteData(byte address, char *data){

  int8_t ACK;
  Master_StartConditions();

  address = address << 1;
  Master_WriteOneByte(address);

  ACK = Master_ReadACK();
  if(ACK == 1){
    Master_StopConditions();
    return -1;
  }
  
  while(*data != '\0'){
    Master_WriteOneByte(*data);
    ACK = Master_ReadACK();
    if(ACK == 1){
    Master_StopConditions();
    return -1;
    }
    data++;
  }

  Master_StopConditions();

  return 1;

}

void Master_StartConditions(void){

  MASTER_SDA_HIGH;
  MASTER_SCL_HIGH;
  MASTER_SDA_OUTPUT;
  MASTER_SCL_OUTPUT;
  delayMicroseconds(FULL);

  MASTER_SDA_LOW;  delayMicroseconds(HALF);
  MASTER_SCL_LOW;  delayMicroseconds(HALF);

}

uint8_t Master_ReadACK(void){
  
  uint8_t ACK;
  MASTER_SDA_INPUT;
  delayMicroseconds(HALF);
  MASTER_SCL_HIGH;
  ACK = MASTER_SDA_READ;
  delayMicroseconds(HALF);  
  MASTER_SCL_LOW;
  delayMicroseconds(HALF);
  
  return ACK;

}

void Master_WriteOneByte(byte data){
  int i;
  MASTER_SDA_OUTPUT;
  for(i = 0; i < 8; i ++){
  if ((data & 0x80) != 0){
    MASTER_SDA_HIGH;
  }else{
    MASTER_SDA_LOW;
  }
  data = data << 1;
  delayMicroseconds(HALF);
  MASTER_SCL_HIGH;
  delayMicroseconds(HALF);
  MASTER_SCL_LOW;
  }
}

byte Master_ReadOneByte(void){

  byte data = 0;
  uint8_t i;
  MASTER_SDA_INPUT;
  MASTER_SCL_OUTPUT;
  MASTER_SCL_LOW;
  delayMicroseconds(HALF);
  // MASTER_SCL_HIGH;
  for(i =0; i < 8; i++){
    delayMicroseconds(HALF);
    MASTER_SCL_HIGH;
    data = (data << 1) | MASTER_SDA_READ;
    delayMicroseconds(HALF);
    MASTER_SCL_LOW;
  }

  return data;

}

void Master_SendACK(void){

  MASTER_SCL_LOW;
  MASTER_SDA_OUTPUT;
  MASTER_SDA_LOW;
  delayMicroseconds(HALF);
  MASTER_SCL_HIGH;
  delayMicroseconds(HALF);
  MASTER_SCL_LOW;
  MASTER_SDA_INPUT;
  delayMicroseconds(HALF);

}

void Master_StopConditions(void){

  MASTER_SCL_LOW;
  MASTER_SDA_OUTPUT;
  MASTER_SDA_LOW; 
  delayMicroseconds(HALF);
  MASTER_SCL_HIGH; 
  delayMicroseconds(HALF);
  MASTER_SDA_HIGH; 

}