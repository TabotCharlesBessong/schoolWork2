                   int i;
int ssdvec[]={119,31,78,61,79,71,118,111,3,14,56}  ;
void main() {

    TRISB=0;
    PORTB=0x00;
    i=0;
    while(1){
    for(i=0;i<6;i++)  {
    PORTB=ssdvec[i];
    Delay_ms(1000);
    }
     PORTB=0x00;
     Delay_ms(1000);
     i++;


    }
}