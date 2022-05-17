
_main:

;letters_display.c,1 :: 		void main() {
;letters_display.c,3 :: 		int A[]={63,6,91,79,102,109,125,7,127,111};
	MOVLW      ?ICSmain_A_L0+0
	MOVWF      ___DoICPAddr+0
	MOVLW      hi_addr(?ICSmain_A_L0+0)
	MOVWF      ___DoICPAddr+1
	MOVLW      main_A_L0+0
	MOVWF      FSR
	MOVLW      40
	MOVWF      R0+0
	CALL       ___CC2DW+0
;letters_display.c,5 :: 		TRISB=0x00;
	CLRF       TRISB+0
;letters_display.c,6 :: 		TRISC=0X00;
	CLRF       TRISC+0
;letters_display.c,7 :: 		while(1){
L_main0:
;letters_display.c,8 :: 		for(i=0;i<=9;i++)
	CLRF       R3+0
	CLRF       R3+1
L_main2:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      R3+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main10
	MOVF       R3+0, 0
	SUBLW      9
L__main10:
	BTFSS      STATUS+0, 0
	GOTO       L_main3
;letters_display.c,9 :: 		{PORTB=A[i];
	MOVF       R3+0, 0
	MOVWF      R0+0
	MOVF       R3+1, 0
	MOVWF      R0+1
	RLF        R0+0, 1
	RLF        R0+1, 1
	BCF        R0+0, 0
	MOVF       R0+0, 0
	ADDLW      main_A_L0+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;letters_display.c,10 :: 		for(j=0;j<=9;j++)
	CLRF       R5+0
	CLRF       R5+1
L_main5:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      R5+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main11
	MOVF       R5+0, 0
	SUBLW      9
L__main11:
	BTFSS      STATUS+0, 0
	GOTO       L_main6
;letters_display.c,11 :: 		{PORTC=B[j];
	MOVF       R5+0, 0
	MOVWF      R0+0
	MOVF       R5+1, 0
	MOVWF      R0+1
	RLF        R0+0, 1
	RLF        R0+1, 1
	BCF        R0+0, 0
	MOVF       R0+0, 0
	ADDLW      main_B_L0+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTC+0
;letters_display.c,12 :: 		delay_ms(100);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_main8:
	DECFSZ     R13+0, 1
	GOTO       L_main8
	DECFSZ     R12+0, 1
	GOTO       L_main8
	DECFSZ     R11+0, 1
	GOTO       L_main8
	NOP
;letters_display.c,10 :: 		for(j=0;j<=9;j++)
	INCF       R5+0, 1
	BTFSC      STATUS+0, 2
	INCF       R5+1, 1
;letters_display.c,13 :: 		}
	GOTO       L_main5
L_main6:
;letters_display.c,8 :: 		for(i=0;i<=9;i++)
	INCF       R3+0, 1
	BTFSC      STATUS+0, 2
	INCF       R3+1, 1
;letters_display.c,14 :: 		} }
	GOTO       L_main2
L_main3:
	GOTO       L_main0
;letters_display.c,15 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
