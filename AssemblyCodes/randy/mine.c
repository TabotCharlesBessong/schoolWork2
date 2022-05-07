int i;
void main() {
// We need to create a counter from 0 to 5 and back using RB0, RB1 and RB2
      TRISB = 0x00;    // all of PORT B is output
      TRISA=0x00;
      PORTB = 0x00; //LOW SIGNAL ON all pins
      PORTA=0x00;

      // we will adopt 20% of duty time
      while(1){//endless loop

      if(PORTA.F0==0X01)   {
           for(i=0x07;i>=0x00;i=i-1){
         PORTB = i; //Alternates from 7 t0 0
         Delay_ms(200);}  }
         
         else{
         for(i=0x00;i<=0x07;i++){
                PORTB = i; //Alternates from 0 t0 7
         Delay_ms(200);
                }
                }
                    }
}