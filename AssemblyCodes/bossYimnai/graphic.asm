
_delay2S:

;graphic.c,23 :: 		void delay2S(){ // 2 seconds delay function
;graphic.c,24 :: 		Delay_ms(1000);
	MOVLW      11
	MOVWF      R11+0
	MOVLW      38
	MOVWF      R12+0
	MOVLW      93
	MOVWF      R13+0
L_delay2S0:
	DECFSZ     R13+0, 1
	GOTO       L_delay2S0
	DECFSZ     R12+0, 1
	GOTO       L_delay2S0
	DECFSZ     R11+0, 1
	GOTO       L_delay2S0
	NOP
	NOP
;graphic.c,25 :: 		}
L_end_delay2S:
	RETURN
; end of _delay2S

_main:

;graphic.c,26 :: 		void main() {
;graphic.c,31 :: 		ANSEL = 0; // Configure AN pins as digital
	CLRF       ANSEL+0
;graphic.c,32 :: 		ANSELH = 0;
	CLRF       ANSELH+0
;graphic.c,33 :: 		C1ON_bit = 0; // Disable comparators
	BCF        C1ON_bit+0, BitPos(C1ON_bit+0)
;graphic.c,34 :: 		C2ON_bit = 0;
	BCF        C2ON_bit+0, BitPos(C2ON_bit+0)
;graphic.c,35 :: 		Glcd_Init(); // Initialize GLCD
	CALL       _Glcd_Init+0
;graphic.c,36 :: 		Glcd_Fill(0x00); // Clear GLCD
	CLRF       FARG_Glcd_Fill_pattern+0
	CALL       _Glcd_Fill+0
;graphic.c,37 :: 		while(1) {
L_main1:
;graphic.c,39 :: 		Glcd_Image(assign); // Draw image
	MOVLW      _assign+0
	MOVWF      FARG_Glcd_Image_image+0
	MOVLW      hi_addr(_assign+0)
	MOVWF      FARG_Glcd_Image_image+1
	CALL       _Glcd_Image+0
;graphic.c,40 :: 		delay2S();
	CALL       _delay2S+0
;graphic.c,41 :: 		Glcd_Image(house);
	MOVLW      _house+0
	MOVWF      FARG_Glcd_Image_image+0
	MOVLW      hi_addr(_house+0)
	MOVWF      FARG_Glcd_Image_image+1
	CALL       _Glcd_Image+0
;graphic.c,42 :: 		delay2S();
	CALL       _delay2S+0
;graphic.c,46 :: 		Glcd_Fill(0x00); // Clear GLCD
	CLRF       FARG_Glcd_Fill_pattern+0
	CALL       _Glcd_Fill+0
;graphic.c,47 :: 		Glcd_Box(62,40,124,56,1); // Draw box
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
;graphic.c,48 :: 		Glcd_Rectangle(5,5,84,35,1); // Draw rectangle
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
;graphic.c,49 :: 		Glcd_Line(0, 0, 127, 63, 1); // Draw line
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
;graphic.c,50 :: 		delay2S();
	CALL       _delay2S+0
;graphic.c,51 :: 		for(ii = 5; ii < 60; ii+=5 ){ // Draw horizontal and vertical lines
	MOVLW      5
	MOVWF      main_ii_L0+0
L_main3:
	MOVLW      60
	SUBWF      main_ii_L0+0, 0
	BTFSC      STATUS+0, 0
	GOTO       L_main4
;graphic.c,52 :: 		Delay_ms(250);
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
;graphic.c,53 :: 		Glcd_V_Line(2, 54, ii, 1);
	MOVLW      2
	MOVWF      FARG_Glcd_V_Line_y_start+0
	MOVLW      54
	MOVWF      FARG_Glcd_V_Line_y_end+0
	MOVF       main_ii_L0+0, 0
	MOVWF      FARG_Glcd_V_Line_x_pos+0
	MOVLW      1
	MOVWF      FARG_Glcd_V_Line_color+0
	CALL       _Glcd_V_Line+0
;graphic.c,54 :: 		Glcd_H_Line(2, 120, ii, 1);
	MOVLW      2
	MOVWF      FARG_Glcd_H_Line_x_start+0
	MOVLW      120
	MOVWF      FARG_Glcd_H_Line_x_end+0
	MOVF       main_ii_L0+0, 0
	MOVWF      FARG_Glcd_H_Line_y_pos+0
	MOVLW      1
	MOVWF      FARG_Glcd_H_Line_color+0
	CALL       _Glcd_H_Line+0
;graphic.c,51 :: 		for(ii = 5; ii < 60; ii+=5 ){ // Draw horizontal and vertical lines
	MOVLW      5
	ADDWF      main_ii_L0+0, 1
;graphic.c,55 :: 		}
	GOTO       L_main3
L_main4:
;graphic.c,56 :: 		delay2S();
	CALL       _delay2S+0
;graphic.c,57 :: 		Glcd_Fill(0x00); // Clear GLCD
	CLRF       FARG_Glcd_Fill_pattern+0
	CALL       _Glcd_Fill+0
;graphic.c,59 :: 		Glcd_Set_Font(Character8x7, 8, 7, 32);// Choose font, see
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
;graphic.c,62 :: 		Glcd_Write_Text("mikroE", 1, 7, 2); // Write string
	MOVLW      ?lstr1_graphic+0
	MOVWF      FARG_Glcd_Write_Text_text+0
	MOVLW      1
	MOVWF      FARG_Glcd_Write_Text_x_pos+0
	MOVLW      7
	MOVWF      FARG_Glcd_Write_Text_page_num+0
	MOVLW      2
	MOVWF      FARG_Glcd_Write_Text_color+0
	CALL       _Glcd_Write_Text+0
;graphic.c,63 :: 		for (ii = 1; ii <= 10; ii++) // Draw circles
	MOVLW      1
	MOVWF      main_ii_L0+0
L_main7:
	MOVF       main_ii_L0+0, 0
	SUBLW      10
	BTFSS      STATUS+0, 0
	GOTO       L_main8
;graphic.c,64 :: 		Glcd_Circle(63,32, 3*ii, 1);
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
;graphic.c,63 :: 		for (ii = 1; ii <= 10; ii++) // Draw circles
	INCF       main_ii_L0+0, 1
;graphic.c,64 :: 		Glcd_Circle(63,32, 3*ii, 1);
	GOTO       L_main7
L_main8:
;graphic.c,65 :: 		delay2S();
	CALL       _delay2S+0
;graphic.c,66 :: 		Glcd_Box(12,20, 70,57, 2); // Draw box
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
;graphic.c,67 :: 		delay2S();
	CALL       _delay2S+0
;graphic.c,69 :: 		Glcd_Fill(0xFF); // Fill GLCD
	MOVLW      255
	MOVWF      FARG_Glcd_Fill_pattern+0
	CALL       _Glcd_Fill+0
;graphic.c,70 :: 		Glcd_Set_Font(Character8x7, 8, 7, 32);// Change font
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
;graphic.c,71 :: 		someText = "8x7 Font";
	MOVLW      ?lstr2_graphic+0
	MOVWF      main_someText_L0+0
;graphic.c,72 :: 		Glcd_Write_Text(someText, 5, 0, 2); // Write string
	MOVF       main_someText_L0+0, 0
	MOVWF      FARG_Glcd_Write_Text_text+0
	MOVLW      5
	MOVWF      FARG_Glcd_Write_Text_x_pos+0
	CLRF       FARG_Glcd_Write_Text_page_num+0
	MOVLW      2
	MOVWF      FARG_Glcd_Write_Text_color+0
	CALL       _Glcd_Write_Text+0
;graphic.c,73 :: 		delay2S();
	CALL       _delay2S+0
;graphic.c,74 :: 		Glcd_Set_Font(System3x5, 3, 5, 32); // Change font
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
;graphic.c,75 :: 		someText = "3X5 CAPITALS ONLY";
	MOVLW      ?lstr3_graphic+0
	MOVWF      main_someText_L0+0
;graphic.c,76 :: 		Glcd_Write_Text(someText, 60, 2, 2); // Write string
	MOVF       main_someText_L0+0, 0
	MOVWF      FARG_Glcd_Write_Text_text+0
	MOVLW      60
	MOVWF      FARG_Glcd_Write_Text_x_pos+0
	MOVLW      2
	MOVWF      FARG_Glcd_Write_Text_page_num+0
	MOVLW      2
	MOVWF      FARG_Glcd_Write_Text_color+0
	CALL       _Glcd_Write_Text+0
;graphic.c,77 :: 		delay2S();
	CALL       _delay2S+0
;graphic.c,78 :: 		Glcd_Set_Font(font5x7, 5, 7, 32); // Change font
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
;graphic.c,79 :: 		someText = "5x7 Font";
	MOVLW      ?lstr4_graphic+0
	MOVWF      main_someText_L0+0
;graphic.c,81 :: 		Glcd_Write_Text(someText, 5, 4, 2); // Write string
	MOVF       main_someText_L0+0, 0
	MOVWF      FARG_Glcd_Write_Text_text+0
	MOVLW      5
	MOVWF      FARG_Glcd_Write_Text_x_pos+0
	MOVLW      4
	MOVWF      FARG_Glcd_Write_Text_page_num+0
	MOVLW      2
	MOVWF      FARG_Glcd_Write_Text_color+0
	CALL       _Glcd_Write_Text+0
;graphic.c,82 :: 		delay2S();
	CALL       _delay2S+0
;graphic.c,83 :: 		Glcd_Set_Font(FontSystem5x7_v2, 5, 7, 32); // Change font
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
;graphic.c,84 :: 		someText = "5x7 Font (v2)";
	MOVLW      ?lstr5_graphic+0
	MOVWF      main_someText_L0+0
;graphic.c,85 :: 		Glcd_Write_Text(someText, 5, 6, 2); // Write string
	MOVF       main_someText_L0+0, 0
	MOVWF      FARG_Glcd_Write_Text_text+0
	MOVLW      5
	MOVWF      FARG_Glcd_Write_Text_x_pos+0
	MOVLW      6
	MOVWF      FARG_Glcd_Write_Text_page_num+0
	MOVLW      2
	MOVWF      FARG_Glcd_Write_Text_color+0
	CALL       _Glcd_Write_Text+0
;graphic.c,86 :: 		delay2S();
	CALL       _delay2S+0
;graphic.c,88 :: 		}
	GOTO       L_main1
;graphic.c,89 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
