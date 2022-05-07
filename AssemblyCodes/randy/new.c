int i;
void main() {
// We need to turn RB0 on and make sure we delay with it
      TRISB = 0x00;    //PORT B is output
      PORTB = 0x00; //LOW SIGNAL ON portB

      // we will adopt 60% of duty time
      while(1){//endless loop
       for(i=0x00;i<=0x07;i++){
       PORTB = i; //Alternates from 7 t0 0
         Delay_ms(200);
                }

                }

}