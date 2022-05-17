
_delay2S:

;Glcd.c,66 :: 		void delay2S(){ // 2 seconds delay function
;Glcd.c,67 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
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
;Glcd.c,68 :: 		}
L_end_delay2S:
	RETURN
; end of _delay2S

_main:

;Glcd.c,69 :: 		void main() {
;Glcd.c,74 :: 		ANSEL = 0; // Configure AN pins as digital
	CLRF       ANSEL+0
;Glcd.c,75 :: 		ANSELH = 0;
	CLRF       ANSELH+0
;Glcd.c,76 :: 		C1ON_bit = 0; // Disable comparators
	BCF        C1ON_bit+0, BitPos(C1ON_bit+0)
;Glcd.c,77 :: 		C2ON_bit = 0;
	BCF        C2ON_bit+0, BitPos(C2ON_bit+0)
;Glcd.c,78 :: 		Glcd_Init(); // Initialize GLCD
	CALL       _Glcd_Init+0
;Glcd.c,79 :: 		Glcd_Fill(0x00); // Clear GLCD
	CLRF       FARG_Glcd_Fill_pattern+0
	CALL       _Glcd_Fill+0
;Glcd.c,80 :: 		while(1) {
L_main1:
;Glcd.c,82 :: 		Glcd_Image(bitpic1); // Draw image
	MOVLW      _bitpic1+0
	MOVWF      FARG_Glcd_Image_image+0
	MOVLW      hi_addr(_bitpic1+0)
	MOVWF      FARG_Glcd_Image_image+1
	CALL       _Glcd_Image+0
;Glcd.c,83 :: 		delay2s();
	CALL       _delay2S+0
;Glcd.c,84 :: 		Glcd_Image(bitpic2);
	MOVLW      _bitpic2+0
	MOVWF      FARG_Glcd_Image_image+0
	MOVLW      hi_addr(_bitpic2+0)
	MOVWF      FARG_Glcd_Image_image+1
	CALL       _Glcd_Image+0
;Glcd.c,85 :: 		delay2s();
	CALL       _delay2S+0
;Glcd.c,86 :: 		Glcd_Image(bitpic3);
	MOVLW      _bitpic3+0
	MOVWF      FARG_Glcd_Image_image+0
	MOVLW      hi_addr(_bitpic3+0)
	MOVWF      FARG_Glcd_Image_image+1
	CALL       _Glcd_Image+0
;Glcd.c,87 :: 		delay2s();
	CALL       _delay2S+0
;Glcd.c,88 :: 		Glcd_Image(truck_bmp);
	MOVLW      _truck_bmp+0
	MOVWF      FARG_Glcd_Image_image+0
	MOVLW      hi_addr(_truck_bmp+0)
	MOVWF      FARG_Glcd_Image_image+1
	CALL       _Glcd_Image+0
;Glcd.c,89 :: 		delay2s();
	CALL       _delay2S+0
;Glcd.c,90 :: 		Glcd_Image(bitpic4);
	MOVLW      _bitpic4+0
	MOVWF      FARG_Glcd_Image_image+0
	MOVLW      hi_addr(_bitpic4+0)
	MOVWF      FARG_Glcd_Image_image+1
	CALL       _Glcd_Image+0
;Glcd.c,91 :: 		delay2s();
	CALL       _delay2S+0
;Glcd.c,95 :: 		}
	GOTO       L_main1
;Glcd.c,96 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
