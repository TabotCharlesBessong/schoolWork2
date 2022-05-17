
_main:

;last.c,1 :: 		void main() {
;last.c,3 :: 		int ssDev[10] = {0X7E, 0X06, 0X6D, 0X79, 0X33, 0X5B, 0X5F, 0X70, 0X7F, 0X7B};
	MOVLW      126
	MOVWF      main_ssDev_L0+0
	MOVLW      0
	MOVWF      main_ssDev_L0+1
	MOVLW      6
	MOVWF      main_ssDev_L0+2
	MOVLW      0
	MOVWF      main_ssDev_L0+3
	MOVLW      109
	MOVWF      main_ssDev_L0+4
	MOVLW      0
	MOVWF      main_ssDev_L0+5
	MOVLW      121
	MOVWF      main_ssDev_L0+6
	MOVLW      0
	MOVWF      main_ssDev_L0+7
	MOVLW      51
	MOVWF      main_ssDev_L0+8
	MOVLW      0
	MOVWF      main_ssDev_L0+9
	MOVLW      91
	MOVWF      main_ssDev_L0+10
	MOVLW      0
	MOVWF      main_ssDev_L0+11
	MOVLW      95
	MOVWF      main_ssDev_L0+12
	MOVLW      0
	MOVWF      main_ssDev_L0+13
	MOVLW      112
	MOVWF      main_ssDev_L0+14
	MOVLW      0
	MOVWF      main_ssDev_L0+15
	MOVLW      127
	MOVWF      main_ssDev_L0+16
	MOVLW      0
	MOVWF      main_ssDev_L0+17
	MOVLW      123
	MOVWF      main_ssDev_L0+18
	MOVLW      0
	MOVWF      main_ssDev_L0+19
;last.c,4 :: 		TRISB = 0X00;
	CLRF       TRISB+0
;last.c,5 :: 		PORTB = 0X00;
	CLRF       PORTB+0
;last.c,6 :: 		while(1){
L_main0:
;last.c,8 :: 		int i =0;
	CLRF       main_i_L1+0
	CLRF       main_i_L1+1
;last.c,9 :: 		while(i < 10){
L_main2:
	MOVLW      128
	XORWF      main_i_L1+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main6
	MOVLW      10
	SUBWF      main_i_L1+0, 0
L__main6:
	BTFSC      STATUS+0, 0
	GOTO       L_main3
;last.c,10 :: 		PORTB = ssDev[i];
	MOVF       main_i_L1+0, 0
	MOVWF      R0+0
	MOVF       main_i_L1+1, 0
	MOVWF      R0+1
	RLF        R0+0, 1
	RLF        R0+1, 1
	BCF        R0+0, 0
	MOVF       R0+0, 0
	ADDLW      main_ssDev_L0+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;last.c,11 :: 		Delay_ms(1000);
	MOVLW      11
	MOVWF      R11+0
	MOVLW      38
	MOVWF      R12+0
	MOVLW      93
	MOVWF      R13+0
L_main4:
	DECFSZ     R13+0, 1
	GOTO       L_main4
	DECFSZ     R12+0, 1
	GOTO       L_main4
	DECFSZ     R11+0, 1
	GOTO       L_main4
	NOP
	NOP
;last.c,12 :: 		i++;
	INCF       main_i_L1+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L1+1, 1
;last.c,13 :: 		}
	GOTO       L_main2
L_main3:
;last.c,14 :: 		}
	GOTO       L_main0
;last.c,15 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
