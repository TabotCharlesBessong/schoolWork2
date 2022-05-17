// LCD module connections
sbit LCD_RS at LATB5_bit;
sbit LCD_EN at LATB4_bit;
sbit LCD_D4 at LATB0_bit;
sbit LCD_D5 at LATB1_bit;
sbit LCD_D6 at LATB2_bit;
sbit LCD_D7 at LATB3_bit;

sbit LCD_RS_Direction at TRISB5_bit;
sbit LCD_EN_Direction at TRISB4_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;
// End LCD module connections

unsigned int temperature = 0;
float mV;
unsigned char txt[15];


void main() {
      ADCON1 = 0x0E;
      TRISA.RA0 = 1;
      OSCCON = 0x76;

      ADC_Init();
      lcd_Init();
      lcd_Cmd(_LCD_CLEAR);
      Lcd_Cmd(_LCD_CURSOR_OFF);
      Lcd_Cmd(_LCD_CLEAR);

      Lcd_Out(1, 1, "Current Temp:");
      Lcd_Chr(2,8,223);
      Lcd_Chr(2,9,'C');

      temperature = 0;
      do {
      temperature = ADC_Read(0);
      mV = temperature * 5000.0 /1024.0;
      mV = mV/10.0;
      FloatToStr(mV, txt);
      txt[4] = 0;
      Lcd_Out(2,3,txt);
      Delay_ms(300);
      } while(1);
}