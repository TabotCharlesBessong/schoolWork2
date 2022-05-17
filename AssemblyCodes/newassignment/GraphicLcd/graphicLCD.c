

const code char truck_bmp[1024];

char GLCD_DataPort at PORTD;
sbit GLCD_CS1 at RB0_bit;
sbit GLCD_CS2 at RB1_bit;
sbit GLCD_RS at RB2_bit;
sbit GLCD_RW at RB3_bit;
sbit GLCD_EN at RB4_bit;
sbit GLCD_RST at RB5_bit;
sbit GLCD_CS1_Direction at TRISB0_bit;
sbit GLCD_CS2_Direction at TRISB1_bit;
sbit GLCD_RS_Direction at TRISB2_bit;
sbit GLCD_RW_Direction at TRISB3_bit;
sbit GLCD_EN_Direction at TRISB4_bit;
sbit GLCD_RST_Direction at TRISB5_bit;
// End Glcd module connections
void delay2S(){ // 2 seconds delay function
Delay_ms(2000);
}
void main() {
unsigned short ii;
char *someText;
#define COMPLETE_EXAMPLE // comment this line to make
//
ANSEL = 0; // Configure AN pins as digital
ANSELH = 0;
C1ON_bit = 0; // Disable comparators
C2ON_bit = 0;
Glcd_Init(); // Initialize GLCD
Glcd_Fill(0x00); // Clear GLCD
while(1) {
#ifdef COMPLETE_EXAMPLE
Glcd_Image(truck_bmp); // Draw image
delay2S(); delay2S();
#endif
Glcd_Fill(0x00); // Clear GLCD
Glcd_Box(62,40,124,56,1); // Draw box
Glcd_Rectangle(5,5,84,35,1); // Draw rectangle
Glcd_Line(0, 0, 127, 63, 1); // Draw line
delay2S();
for(ii = 5; ii < 60; ii+=5 ){ // Draw horizontal and vertical lines
Delay_ms(250);
Glcd_V_Line(2, 54, ii, 1);
Glcd_H_Line(2, 120, ii, 1);
}
delay2S();
Glcd_Fill(0x00); // Clear GLCD
#ifdef COMPLETE_EXAMPLE
Glcd_Set_Font(Character8x7, 8, 7, 32);// Choose font, see

#endif
Glcd_Write_Text("mikroE", 1, 7, 2); // Write string
for (ii = 1; ii <= 10; ii++) // Draw circles
Glcd_Circle(63,32, 3*ii, 1);
delay2S();
Glcd_Box(12,20, 70,57, 2); // Draw box
delay2S();
#ifdef COMPLETE_EXAMPLE
Glcd_Fill(0xFF); // Fill GLCD
Glcd_Set_Font(Character8x7, 8, 7, 32);// Change font
someText = "8x7 Font";
Glcd_Write_Text(someText, 5, 0, 2); // Write string
delay2S();
Glcd_Set_Font(System3x5, 3, 5, 32); // Change font
someText = "3X5 CAPITALS ONLY";
Glcd_Write_Text(someText, 60, 2, 2); // Write string
delay2S();
Glcd_Set_Font(font5x7, 5, 7, 32); // Change font
someText = "5x7 Font";
Glcd_Write_Text(someText, 5, 4, 2); // Write string
delay2S();
Glcd_Set_Font(FontSystem5x7_v2, 5, 7, 32); // Change font
someText = "5x7 Font (v2)";
Glcd_Write_Text(someText, 5, 6, 2); // Write string
delay2S();
#endif
}
}