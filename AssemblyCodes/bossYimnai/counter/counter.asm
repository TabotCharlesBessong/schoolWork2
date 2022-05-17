
_main:

;counter.c,4 :: 		void main() {
;counter.c,8 :: 		TRISC = 0;
	CLRF       TRISC+0
;counter.c,9 :: 		TRISA = 0;
	CLRF       TRISA+0
;counter.c,10 :: 		TRISB =0;
	CLRF       TRISB+0
;counter.c,11 :: 		TRISD = 255;
	MOVLW      255
	MOVWF      TRISD+0
;counter.c,12 :: 		PORTC = 0;
	CLRF       PORTC+0
;counter.c,13 :: 		PORTA=0;
	CLRF       PORTA+0
;counter.c,14 :: 		PORTB=0;
	CLRF       PORTB+0
;counter.c,19 :: 		while(1){
L_main0:
;counter.c,21 :: 		for(first =1; first<10; first ++){
	MOVLW      1
	MOVWF      R1+0
	MOVLW      0
	MOVWF      R1+1
L_main2:
	MOVLW      128
	XORWF      R1+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main13
	MOVLW      10
	SUBWF      R1+0, 0
L__main13:
	BTFSC      STATUS+0, 0
	GOTO       L_main3
;counter.c,23 :: 		for(second =1; second <=10; second++){
	MOVLW      1
	MOVWF      R3+0
	MOVLW      0
	MOVWF      R3+1
L_main5:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      R3+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main14
	MOVF       R3+0, 0
	SUBLW      10
L__main14:
	BTFSS      STATUS+0, 0
	GOTO       L_main6
;counter.c,25 :: 		for(decimal = 0; decimal<=9; decimal ++){
	CLRF       R5+0
	CLRF       R5+1
L_main8:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      R5+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main15
	MOVF       R5+0, 0
	SUBLW      9
L__main15:
	BTFSS      STATUS+0, 0
	GOTO       L_main9
;counter.c,28 :: 		PORTB = decimal;
	MOVF       R5+0, 0
	MOVWF      PORTB+0
;counter.c,29 :: 		delay_ms(100);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_main11:
	DECFSZ     R13+0, 1
	GOTO       L_main11
	DECFSZ     R12+0, 1
	GOTO       L_main11
	DECFSZ     R11+0, 1
	GOTO       L_main11
	NOP
;counter.c,25 :: 		for(decimal = 0; decimal<=9; decimal ++){
	INCF       R5+0, 1
	BTFSC      STATUS+0, 2
	INCF       R5+1, 1
;counter.c,30 :: 		}
	GOTO       L_main8
L_main9:
;counter.c,33 :: 		PORTB=0;
	CLRF       PORTB+0
;counter.c,34 :: 		PORTC = second;
	MOVF       R3+0, 0
	MOVWF      PORTC+0
;counter.c,23 :: 		for(second =1; second <=10; second++){
	INCF       R3+0, 1
	BTFSC      STATUS+0, 2
	INCF       R3+1, 1
;counter.c,36 :: 		}
	GOTO       L_main5
L_main6:
;counter.c,39 :: 		PORTC=0;
	CLRF       PORTC+0
;counter.c,40 :: 		PORTA = first;
	MOVF       R1+0, 0
	MOVWF      PORTA+0
;counter.c,21 :: 		for(first =1; first<10; first ++){
	INCF       R1+0, 1
	BTFSC      STATUS+0, 2
	INCF       R1+1, 1
;counter.c,42 :: 		}
	GOTO       L_main2
L_main3:
;counter.c,43 :: 		PORTC = 0;
	CLRF       PORTC+0
;counter.c,44 :: 		PORTA=0;
	CLRF       PORTA+0
;counter.c,45 :: 		PORTB=0;
	CLRF       PORTB+0
;counter.c,46 :: 		}
	GOTO       L_main0
;counter.c,49 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
