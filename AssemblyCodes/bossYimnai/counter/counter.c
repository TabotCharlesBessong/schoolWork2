


void main() {
int first, second,decimal;


  TRISC = 0;
  TRISA = 0;
  TRISB =0;
  TRISD = 255;
  PORTC = 0;
  PORTA=0;
  PORTB=0;




  while(1){

         for(first =1; first<10; first ++){

                   for(second =1; second <=10; second++){

                              for(decimal = 0; decimal<=9; decimal ++){
                                          
                                          
                                          PORTB = decimal;
                                          delay_ms(100);
                              }


                              PORTB=0;
                              PORTC = second;

                              }


                              PORTC=0;
                              PORTA = first;

                   }
  PORTC = 0;
  PORTA=0;
  PORTB=0;
  }

  
}