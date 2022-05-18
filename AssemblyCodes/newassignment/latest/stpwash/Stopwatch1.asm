
_main:

;Stopwatch1.c,2 :: 		void main() {
;Stopwatch1.c,3 :: 		int sec1[10] = {0X7E, 0X30, 0X6D, 0X79, 0X33, 0X5B, 0X5F, 0X70, 0X7F, 0X7D};
;Stopwatch1.c,4 :: 		int sec2[10] = {0X7E, 0X30, 0X6D, 0X79, 0X33, 0X5B, 0X5F, 0X70, 0X7F, 0X7D};
;Stopwatch1.c,5 :: 		int count = 0;
;Stopwatch1.c,6 :: 		int i = 0;
	CLRF       main_i_L0+0
	CLRF       main_i_L0+1
	CLRF       main_j_L0+0
	CLRF       main_j_L0+1
;Stopwatch1.c,10 :: 		TRISB = 0x00;
	CLRF       TRISB+0
;Stopwatch1.c,11 :: 		PORTB =  0x00;
	CLRF       PORTB+0
;Stopwatch1.c,12 :: 		TRISA = 0x00; //all port b is output
	CLRF       TRISA+0
;Stopwatch1.c,13 :: 		PORTA = 0x00;
	CLRF       PORTA+0
;Stopwatch1.c,14 :: 		while(1){
L_main0:
;Stopwatch1.c,15 :: 		for(j=0; j<6; j++)
	CLRF       main_j_L0+0
	CLRF       main_j_L0+1
L_main2:
	MOVLW      128
	XORWF      main_j_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main14
	MOVLW      6
	SUBWF      main_j_L0+0, 0
L__main14:
	BTFSC      STATUS+0, 0
	GOTO       L_main3
;Stopwatch1.c,17 :: 		PORTA = 0x00 +j ;
	MOVF       main_j_L0+0, 0
	MOVWF      PORTA+0
;Stopwatch1.c,19 :: 		for(i = 0; i < 4; i++)
	CLRF       main_i_L0+0
	CLRF       main_i_L0+1
L_main5:
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main15
	MOVLW      4
	SUBWF      main_i_L0+0, 0
L__main15:
	BTFSC      STATUS+0, 0
	GOTO       L_main6
;Stopwatch1.c,22 :: 		if(PORTB.F7 == 0X01)  {
	BTFSS      PORTB+0, 7
	GOTO       L_main8
;Stopwatch1.c,23 :: 		PORTB = 0x00 + i ;
	MOVF       main_i_L0+0, 0
	MOVWF      PORTB+0
;Stopwatch1.c,24 :: 		Delay_ms(50);
	MOVLW      130
	MOVWF      R12+0
	MOVLW      221
	MOVWF      R13+0
L_main9:
	DECFSZ     R13+0, 1
	GOTO       L_main9
	DECFSZ     R12+0, 1
	GOTO       L_main9
	NOP
	NOP
;Stopwatch1.c,25 :: 		}
	GOTO       L_main10
L_main8:
;Stopwatch1.c,28 :: 		i = PORTB;
	MOVF       PORTB+0, 0
	MOVWF      main_i_L0+0
	CLRF       main_i_L0+1
;Stopwatch1.c,30 :: 		PORTB = rev;
	MOVF       main_i_L0+0, 0
	MOVWF      PORTB+0
;Stopwatch1.c,31 :: 		}
L_main10:
;Stopwatch1.c,19 :: 		for(i = 0; i < 4; i++)
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;Stopwatch1.c,33 :: 		}   //end of for loop
	GOTO       L_main5
L_main6:
;Stopwatch1.c,34 :: 		PORTB = 0X00;
	CLRF       PORTB+0
;Stopwatch1.c,35 :: 		Delay_ms(50);
	MOVLW      130
	MOVWF      R12+0
	MOVLW      221
	MOVWF      R13+0
L_main11:
	DECFSZ     R13+0, 1
	GOTO       L_main11
	DECFSZ     R12+0, 1
	GOTO       L_main11
	NOP
	NOP
;Stopwatch1.c,15 :: 		for(j=0; j<6; j++)
	INCF       main_j_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_j_L0+1, 1
;Stopwatch1.c,40 :: 		}
	GOTO       L_main2
L_main3:
;Stopwatch1.c,41 :: 		PORTA = 0X00;
	CLRF       PORTA+0
;Stopwatch1.c,42 :: 		Delay_ms(50);
	MOVLW      130
	MOVWF      R12+0
	MOVLW      221
	MOVWF      R13+0
L_main12:
	DECFSZ     R13+0, 1
	GOTO       L_main12
	DECFSZ     R12+0, 1
	GOTO       L_main12
	NOP
	NOP
;Stopwatch1.c,44 :: 		}
	GOTO       L_main0
;Stopwatch1.c,48 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
