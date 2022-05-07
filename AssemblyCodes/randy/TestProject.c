void main() {
// We need to turn RB0 on and make sure we delay with it
      TRISB = 0;    //PORT B is output
      PORTB = 0x00; //LOW SIGNAL ON RB0
      
      // we will adopt 60% of duty time
      do {
         PORTB = 0x00; //LOw
         Delay_ms(400);
         PORTB= 0x01; //HIGH on RB0
         Delay_ms(600);
         }
         while(1);//endless loop
}