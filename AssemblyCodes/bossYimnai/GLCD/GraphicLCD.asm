
_delay2S:

;GraphicLCD.c,20 :: 		void delay2S(){ // 2 seconds delay function
;GraphicLCD.c,21 :: 		Delay_ms(2000);
	MOVLW      21
	MOVWF      R11+0
	MOVLW      75
	MOVWF      R12+0
	MOVLW      190
	MOVWF      R13+0
L_delay2S0:
	DECFSZ     R13+0, 1
	GOTO       L_delay2S0
	DECFSZ     R12+0, 1
	GOTO       L_delay2S0
	DECFSZ     R11+0, 1
	GOTO       L_delay2S0
	NOP
;GraphicLCD.c,22 :: 		}
L_end_delay2S:
	RETURN
; end of _delay2S

_main:

;GraphicLCD.c,23 :: 		void main() {
;GraphicLCD.c,28 :: 		ANSEL = 0; // Configure AN pins as digital
	CLRF       ANSEL+0
;GraphicLCD.c,29 :: 		ANSELH = 0;
	CLRF       ANSELH+0
;GraphicLCD.c,30 :: 		C1ON_bit = 0; // Disable comparators
	BCF        C1ON_bit+0, BitPos(C1ON_bit+0)
;GraphicLCD.c,31 :: 		C2ON_bit = 0;
	BCF        C2ON_bit+0, BitPos(C2ON_bit+0)
;GraphicLCD.c,32 :: 		Glcd_Init(); // Initialize GLCD
	CALL       _Glcd_Init+0
;GraphicLCD.c,33 :: 		Glcd_Fill(0x00); // Clear GLCD
	CLRF       FARG_Glcd_Fill_pattern+0
	CALL       _Glcd_Fill+0
;GraphicLCD.c,34 :: 		while(1) {
L_main1:
;GraphicLCD.c,36 :: 		Glcd_Image(truck_bmp); // Draw image
	MOVLW      _truck_bmp+0
	MOVWF      FARG_Glcd_Image_image+0
	MOVLW      hi_addr(_truck_bmp+0)
	MOVWF      FARG_Glcd_Image_image+1
	CALL       _Glcd_Image+0
;GraphicLCD.c,37 :: 		delay2S(); delay2S();
	CALL       _delay2S+0
	CALL       _delay2S+0
;GraphicLCD.c,39 :: 		Glcd_Fill(0x00); // Clear GLCD
	CLRF       FARG_Glcd_Fill_pattern+0
	CALL       _Glcd_Fill+0
;GraphicLCD.c,40 :: 		Glcd_Box(62,40,124,56,1); // Draw box
	MOVLW      62
	MOVWF      FARG_Glcd_Box_x_upper_left+0
	MOVLW      40
	MOVWF      FARG_Glcd_Box_y_upper_left+0
	MOVLW      124
	MOVWF      FARG_Glcd_Box_x_bottom_right+0
	MOVLW      56
	MOVWF      FARG_Glcd_Box_y_bottom_right+0
	MOVLW      1
	MOVWF      FARG_Glcd_Box_color+0
	CALL       _Glcd_Box+0
;GraphicLCD.c,41 :: 		Glcd_Rectangle(5,5,84,35,1); // Draw rectangle
	MOVLW      5
	MOVWF      FARG_Glcd_Rectangle_x_upper_left+0
	MOVLW      5
	MOVWF      FARG_Glcd_Rectangle_y_upper_left+0
	MOVLW      84
	MOVWF      FARG_Glcd_Rectangle_x_bottom_right+0
	MOVLW      35
	MOVWF      FARG_Glcd_Rectangle_y_bottom_right+0
	MOVLW      1
	MOVWF      FARG_Glcd_Rectangle_color+0
	CALL       _Glcd_Rectangle+0
;GraphicLCD.c,42 :: 		Glcd_Line(0, 0, 127, 63, 1); // Draw line
	CLRF       FARG_Glcd_Line_x_start+0
	CLRF       FARG_Glcd_Line_x_start+1
	CLRF       FARG_Glcd_Line_y_start+0
	CLRF       FARG_Glcd_Line_y_start+1
	MOVLW      127
	MOVWF      FARG_Glcd_Line_x_end+0
	MOVLW      0
	MOVWF      FARG_Glcd_Line_x_end+1
	MOVLW      63
	MOVWF      FARG_Glcd_Line_y_end+0
	MOVLW      0
	MOVWF      FARG_Glcd_Line_y_end+1
	MOVLW      1
	MOVWF      FARG_Glcd_Line_color+0
	CALL       _Glcd_Line+0
;GraphicLCD.c,43 :: 		delay2S();
	CALL       _delay2S+0
;GraphicLCD.c,44 :: 		for(ii = 5; ii < 60; ii+=5 ){ // Draw horizontal and vertical lines
	MOVLW      5
	MOVWF      main_ii_L0+0
L_main3:
	MOVLW      60
	SUBWF      main_ii_L0+0, 0
	BTFSC      STATUS+0, 0
	GOTO       L_main4
;GraphicLCD.c,45 :: 		Delay_ms(250);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      138
	MOVWF      R12+0
	MOVLW      85
	MOVWF      R13+0
L_main6:
	DECFSZ     R13+0, 1
	GOTO       L_main6
	DECFSZ     R12+0, 1
	GOTO       L_main6
	DECFSZ     R11+0, 1
	GOTO       L_main6
	NOP
	NOP
;GraphicLCD.c,46 :: 		Glcd_V_Line(2, 54, ii, 1);
	MOVLW      2
	MOVWF      FARG_Glcd_V_Line_y_start+0
	MOVLW      54
	MOVWF      FARG_Glcd_V_Line_y_end+0
	MOVF       main_ii_L0+0, 0
	MOVWF      FARG_Glcd_V_Line_x_pos+0
	MOVLW      1
	MOVWF      FARG_Glcd_V_Line_color+0
	CALL       _Glcd_V_Line+0
;GraphicLCD.c,47 :: 		Glcd_H_Line(2, 120, ii, 1);
	MOVLW      2
	MOVWF      FARG_Glcd_H_Line_x_start+0
	MOVLW      120
	MOVWF      FARG_Glcd_H_Line_x_end+0
	MOVF       main_ii_L0+0, 0
	MOVWF      FARG_Glcd_H_Line_y_pos+0
	MOVLW      1
	MOVWF      FARG_Glcd_H_Line_color+0
	CALL       _Glcd_H_Line+0
;GraphicLCD.c,44 :: 		for(ii = 5; ii < 60; ii+=5 ){ // Draw horizontal and vertical lines
	MOVLW      5
	ADDWF      main_ii_L0+0, 1
;GraphicLCD.c,48 :: 		}
	GOTO       L_main3
L_main4:
;GraphicLCD.c,49 :: 		delay2S();
	CALL       _delay2S+0
;GraphicLCD.c,50 :: 		Glcd_Fill(0x00); // Clear GLCD
	CLRF       FARG_Glcd_Fill_pattern+0
	CALL       _Glcd_Fill+0
;GraphicLCD.c,52 :: 		Glcd_Set_Font(Character8x7, 8, 7, 32);// Choose font, see
	MOVLW      _Character8x7+0
	MOVWF      FARG_Glcd_Set_Font_activeFont+0
	MOVLW      hi_addr(_Character8x7+0)
	MOVWF      FARG_Glcd_Set_Font_activeFont+1
	MOVLW      8
	MOVWF      FARG_Glcd_Set_Font_aFontWidth+0
	MOVLW      7
	MOVWF      FARG_Glcd_Set_Font_aFontHeight+0
	MOVLW      32
	MOVWF      FARG_Glcd_Set_Font_aFontOffs+0
	MOVLW      0
	MOVWF      FARG_Glcd_Set_Font_aFontOffs+1
	CALL       _Glcd_Set_Font+0
;GraphicLCD.c,55 :: 		Glcd_Write_Text("mikroE", 1, 7, 2); // Write string
	MOVLW      ?lstr1_GraphicLCD+0
	MOVWF      FARG_Glcd_Write_Text_text+0
	MOVLW      1
	MOVWF      FARG_Glcd_Write_Text_x_pos+0
	MOVLW      7
	MOVWF      FARG_Glcd_Write_Text_page_num+0
	MOVLW      2
	MOVWF      FARG_Glcd_Write_Text_color+0
	CALL       _Glcd_Write_Text+0
;GraphicLCD.c,56 :: 		for (ii = 1; ii <= 10; ii++) // Draw circles
	MOVLW      1
	MOVWF      main_ii_L0+0
L_main7:
	MOVF       main_ii_L0+0, 0
	SUBLW      10
	BTFSS      STATUS+0, 0
	GOTO       L_main8
;GraphicLCD.c,57 :: 		Glcd_Circle(63,32, 3*ii, 1);
	MOVLW      63
	MOVWF      FARG_Glcd_Circle_x_center+0
	MOVLW      0
	MOVWF      FARG_Glcd_Circle_x_center+1
	MOVLW      32
	MOVWF      FARG_Glcd_Circle_y_center+0
	MOVLW      0
	MOVWF      FARG_Glcd_Circle_y_center+1
	MOVLW      3
	MOVWF      R0+0
	MOVF       main_ii_L0+0, 0
	MOVWF      R4+0
	CALL       _Mul_8X8_U+0
	MOVF       R0+0, 0
	MOVWF      FARG_Glcd_Circle_radius+0
	MOVF       R0+1, 0
	MOVWF      FARG_Glcd_Circle_radius+1
	MOVLW      1
	MOVWF      FARG_Glcd_Circle_color+0
	CALL       _Glcd_Circle+0
;GraphicLCD.c,56 :: 		for (ii = 1; ii <= 10; ii++) // Draw circles
	INCF       main_ii_L0+0, 1
;GraphicLCD.c,57 :: 		Glcd_Circle(63,32, 3*ii, 1);
	GOTO       L_main7
L_main8:
;GraphicLCD.c,58 :: 		delay2S();
	CALL       _delay2S+0
;GraphicLCD.c,59 :: 		Glcd_Box(12,20, 70,57, 2); // Draw box
	MOVLW      12
	MOVWF      FARG_Glcd_Box_x_upper_left+0
	MOVLW      20
	MOVWF      FARG_Glcd_Box_y_upper_left+0
	MOVLW      70
	MOVWF      FARG_Glcd_Box_x_bottom_right+0
	MOVLW      57
	MOVWF      FARG_Glcd_Box_y_bottom_right+0
	MOVLW      2
	MOVWF      FARG_Glcd_Box_color+0
	CALL       _Glcd_Box+0
;GraphicLCD.c,60 :: 		delay2S();
	CALL       _delay2S+0
;GraphicLCD.c,62 :: 		Glcd_Fill(0xFF); // Fill GLCD
	MOVLW      255
	MOVWF      FARG_Glcd_Fill_pattern+0
	CALL       _Glcd_Fill+0
;GraphicLCD.c,63 :: 		Glcd_Set_Font(Character8x7, 8, 7, 32);// Change font
	MOVLW      _Character8x7+0
	MOVWF      FARG_Glcd_Set_Font_activeFont+0
	MOVLW      hi_addr(_Character8x7+0)
	MOVWF      FARG_Glcd_Set_Font_activeFont+1
	MOVLW      8
	MOVWF      FARG_Glcd_Set_Font_aFontWidth+0
	MOVLW      7
	MOVWF      FARG_Glcd_Set_Font_aFontHeight+0
	MOVLW      32
	MOVWF      FARG_Glcd_Set_Font_aFontOffs+0
	MOVLW      0
	MOVWF      FARG_Glcd_Set_Font_aFontOffs+1
	CALL       _Glcd_Set_Font+0
;GraphicLCD.c,64 :: 		someText = "8x7 Font";
	MOVLW      ?lstr2_GraphicLCD+0
	MOVWF      main_someText_L0+0
;GraphicLCD.c,65 :: 		Glcd_Write_Text(someText, 5, 0, 2); // Write string
	MOVF       main_someText_L0+0, 0
	MOVWF      FARG_Glcd_Write_Text_text+0
	MOVLW      5
	MOVWF      FARG_Glcd_Write_Text_x_pos+0
	CLRF       FARG_Glcd_Write_Text_page_num+0
	MOVLW      2
	MOVWF      FARG_Glcd_Write_Text_color+0
	CALL       _Glcd_Write_Text+0
;GraphicLCD.c,66 :: 		delay2S();
	CALL       _delay2S+0
;GraphicLCD.c,67 :: 		Glcd_Set_Font(System3x5, 3, 5, 32); // Change font
	MOVLW      _System3x5+0
	MOVWF      FARG_Glcd_Set_Font_activeFont+0
	MOVLW      hi_addr(_System3x5+0)
	MOVWF      FARG_Glcd_Set_Font_activeFont+1
	MOVLW      3
	MOVWF      FARG_Glcd_Set_Font_aFontWidth+0
	MOVLW      5
	MOVWF      FARG_Glcd_Set_Font_aFontHeight+0
	MOVLW      32
	MOVWF      FARG_Glcd_Set_Font_aFontOffs+0
	MOVLW      0
	MOVWF      FARG_Glcd_Set_Font_aFontOffs+1
	CALL       _Glcd_Set_Font+0
;GraphicLCD.c,68 :: 		someText = "3X5 CAPITALS ONLY";
	MOVLW      ?lstr3_GraphicLCD+0
	MOVWF      main_someText_L0+0
;GraphicLCD.c,69 :: 		Glcd_Write_Text(someText, 60, 2, 2); // Write string
	MOVF       main_someText_L0+0, 0
	MOVWF      FARG_Glcd_Write_Text_text+0
	MOVLW      60
	MOVWF      FARG_Glcd_Write_Text_x_pos+0
	MOVLW      2
	MOVWF      FARG_Glcd_Write_Text_page_num+0
	MOVLW      2
	MOVWF      FARG_Glcd_Write_Text_color+0
	CALL       _Glcd_Write_Text+0
;GraphicLCD.c,70 :: 		delay2S();
	CALL       _delay2S+0
;GraphicLCD.c,71 :: 		Glcd_Set_Font(font5x7, 5, 7, 32); // Change font
	MOVLW      _font5x7+0
	MOVWF      FARG_Glcd_Set_Font_activeFont+0
	MOVLW      hi_addr(_font5x7+0)
	MOVWF      FARG_Glcd_Set_Font_activeFont+1
	MOVLW      5
	MOVWF      FARG_Glcd_Set_Font_aFontWidth+0
	MOVLW      7
	MOVWF      FARG_Glcd_Set_Font_aFontHeight+0
	MOVLW      32
	MOVWF      FARG_Glcd_Set_Font_aFontOffs+0
	MOVLW      0
	MOVWF      FARG_Glcd_Set_Font_aFontOffs+1
	CALL       _Glcd_Set_Font+0
;GraphicLCD.c,72 :: 		someText = "5x7 Font";
	MOVLW      ?lstr4_GraphicLCD+0
	MOVWF      main_someText_L0+0
;GraphicLCD.c,73 :: 		Glcd_Write_Text(someText, 5, 4, 2); // Write string
	MOVF       main_someText_L0+0, 0
	MOVWF      FARG_Glcd_Write_Text_text+0
	MOVLW      5
	MOVWF      FARG_Glcd_Write_Text_x_pos+0
	MOVLW      4
	MOVWF      FARG_Glcd_Write_Text_page_num+0
	MOVLW      2
	MOVWF      FARG_Glcd_Write_Text_color+0
	CALL       _Glcd_Write_Text+0
;GraphicLCD.c,74 :: 		delay2S();
	CALL       _delay2S+0
;GraphicLCD.c,75 :: 		Glcd_Set_Font(FontSystem5x7_v2, 5, 7, 32); // Change font
	MOVLW      _FontSystem5x7_v2+0
	MOVWF      FARG_Glcd_Set_Font_activeFont+0
	MOVLW      hi_addr(_FontSystem5x7_v2+0)
	MOVWF      FARG_Glcd_Set_Font_activeFont+1
	MOVLW      5
	MOVWF      FARG_Glcd_Set_Font_aFontWidth+0
	MOVLW      7
	MOVWF      FARG_Glcd_Set_Font_aFontHeight+0
	MOVLW      32
	MOVWF      FARG_Glcd_Set_Font_aFontOffs+0
	MOVLW      0
	MOVWF      FARG_Glcd_Set_Font_aFontOffs+1
	CALL       _Glcd_Set_Font+0
;GraphicLCD.c,76 :: 		someText = "5x7 Font (v2)";
	MOVLW      ?lstr5_GraphicLCD+0
	MOVWF      main_someText_L0+0
;GraphicLCD.c,77 :: 		Glcd_Write_Text(someText, 5, 6, 2); // Write string
	MOVF       main_someText_L0+0, 0
	MOVWF      FARG_Glcd_Write_Text_text+0
	MOVLW      5
	MOVWF      FARG_Glcd_Write_Text_x_pos+0
	MOVLW      6
	MOVWF      FARG_Glcd_Write_Text_page_num+0
	MOVLW      2
	MOVWF      FARG_Glcd_Write_Text_color+0
	CALL       _Glcd_Write_Text+0
;GraphicLCD.c,78 :: 		delay2S();
	CALL       _delay2S+0
;GraphicLCD.c,80 :: 		}
	GOTO       L_main1
;GraphicLCD.c,81 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
