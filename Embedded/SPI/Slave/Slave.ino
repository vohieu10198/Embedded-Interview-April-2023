#define SCK_PIN 4
#define MOSI_PIN 5
#define MISO_PIN 6
#define SS_PIN 7

#define SCK_INPUT  DDRD |= ~(1 << DDD4)
#define MOSI_INPUT  DDRD |= ~(1 << DDD5)
#define SS_INPUT  DDRD |= ~(1 << DDD7)
#define MISO_OUTPUT  DDRD |= (1 << DDD6)

#define read_SCK() ((PIND & (1 << PIND4)) ? HIGH:LOW )
#define read_MOSI() ((PIND & (1 << PIND5)) ? HIGH:LOW )
#define read_SS() ((PIND & (1 << PIND7)) ? HIGH:LOW )

#define write_MISO(x)   PORTD = ((x) ? (PORTD | 1 << PD6) : (PORTD & (~(1 << PD6))) )




void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void SPI_setup(void){
  SCK_INPUT;
  MOSI_INPUT;
  SS_INPUT;
  MISO_OUTPUT;
}

uint8_t SPI_transfer(uint8_t byte_out){
  uint8_t byte_in = 0;
  uint8_t ibit, res;

  while (read_SS() == HIGH);

  for(ibit = 0x80; ibit > 0; ibit = ibit >> 1 ){
    res = byte_out & ibit;
    write_MISO(res);

    while( read_SCK() == LOW);

    if(read_MOSI() == HIGH);
      byte_in = byte_in | ibit;

    while( read_SCK() == HIGH);

  }
  return byte_out;

}

