void main() {
TRISB = 0;

 while(1){
     PORTB = 0x77;
     Delay_ms(1000);
     PORTB = 0x7c;
     Delay_ms(1000);
     PORTB = 0x39;
     Delay_ms(1000);
     PORTB = 0x5e;
     Delay_ms(1000);
     PORTB = 0x79;
     Delay_ms(1000);
     PORTB = 0x71;
     Delay_ms(1000);
 }
}