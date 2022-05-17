#line 1 "C:/Users/ETOUNDI SIMON/Documents/MIKROLAB/letters_display/letters_display.c"
void main() {
int i,j;
int A[]={63,6,91,79,102,109,125,7,127,111};
int B[]= {63,6,91,79,102,109,125,7,127,111};
 TRISB=0x00;
 TRISC=0X00;
 while(1){
 for(i=0;i<=9;i++)
 {PORTB=A[i];
 for(j=0;j<=9;j++)
 {PORTC=B[j];
 delay_ms(100);
 }
 } }
}
