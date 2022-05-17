void main() {
 int i;
          int ssDev[10] = {0X7E, 0X06, 0X6D, 0X79, 0X33, 0X5B, 0X5F, 0X70, 0X7F, 0X7B};
          TRISB = 0X00;
          PORTB = 0X00;
          while(1){

          int i =0;
          while(i < 10){
                  PORTB = ssDev[i];
                  Delay_ms(1000);
                  i++;
          }
}
}