
void main() {
   int sec1[10] = {0X7E, 0X30, 0X6D, 0X79, 0X33, 0X5B, 0X5F, 0X70, 0X7F, 0X7D};
   int sec2[10] = {0X7E, 0X30, 0X6D, 0X79, 0X33, 0X5B, 0X5F, 0X70, 0X7F, 0X7D};
   int count = 0;
   int i = 0;
   int j = 0;
   int rev;
   int rev1;
  TRISB = 0x00;
  PORTB =  0x00;
  TRISA = 0x00; //all port b is output
  PORTA = 0x00;
 while(1){
    for(j=0; j<6; j++)
    {
             PORTA = 0x00 +j ;

      for(i = 0; i < 4; i++)
      {

             if(PORTB.F7 == 0X01)  {
             PORTB = 0x00 + i ;
              Delay_ms(50);
            }
            
            else{
              i = PORTB;
              rev = i;
              PORTB = rev;
            }

      }   //end of for loop
        PORTB = 0X00;
        Delay_ms(50);




     }
      PORTA = 0X00;
      Delay_ms(50);

   }

   //end of while loop

}