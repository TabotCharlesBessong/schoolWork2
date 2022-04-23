
//LCD module connections
  sbit LCD_RS at RB0_bit;
  sbit LCD_EN at RB1_bit;
  sbit LCD_D4 at RB2_bit;
  sbit LCD_D5 at RB3_bit;
  sbit LCD_D6 at RB4_bit;
  sbit LCD_D7 at RB5_bit;

  sbit LCD_RS_Direction at TRISB0_bit;
  sbit LCD_EN_Direction at TRISB1_bit;
  sbit LCD_D4_Direction at TRISB2_bit;
  sbit LCD_D5_Direction at TRISB3_bit;
  sbit LCD_D6_Direction at TRISB4_bit;
  sbit LCD_D7_Direction at TRISB5_bit;

  // End LCD module connections
           char txt[11];
          float voltage;

void main() {

 TRISB = 0;
PORTB = 0xFF;
TRISB = 0xff;

 Lcd_Init();                        // Initialize LCD

  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
 // Lcd_Cmd(_LCD_CLEAR);               // Clear display
 // Lcd_Out(1,1,"ADC Value");
               ADC_Init();
                TRISB = 0x00;
                PORTA = 0x00;
                TRISA = 0xFF;

  // PORTB=0x00;

   Lcd_Out(1,1,"ADC Value");

   while(1){

  voltage= ADC_Read(1);
     // adcvalue= ADC_Read(0);
     voltage=(voltage*5*10)/1024;
     IntToStr(voltage,txt);
     Lcd_Out(2,1,txt);
        Delay_ms(1000);

//   Lcd_Out(1,1,"My name is");                 // Write text in first row
//   Lcd_Out(2,3,"BEBONGNCHU YANNICK NKWETTA");                 // Write text in second row
//   Delay_ms(1000);
//   Lcd_Cmd(_LCD_CLEAR);

}
}