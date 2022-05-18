
_main:

;Alpha.c,3 :: 		void main() {
;Alpha.c,5 :: 		TRISB=0;
	CLRF       TRISB+0
;Alpha.c,6 :: 		PORTB=0x00;
	CLRF       PORTB+0
;Alpha.c,7 :: 		i=0;
	CLRF       _i+0
	CLRF       _i+1
;Alpha.c,8 :: 		while(1){
L_main0:
;Alpha.c,9 :: 		for(i=0;i<6;i++)  {
	CLRF       _i+0
	CLRF       _i+1
L_main2:
	MOVLW      128
	XORWF      _i+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main8
	MOVLW      6
	SUBWF      _i+0, 0
L__main8:
	BTFSC      STATUS+0, 0
	GOTO       L_main3
;Alpha.c,10 :: 		PORTB=ssdvec[i];
	MOVF       _i+0, 0
	MOVWF      R0+0
	MOVF       _i+1, 0
	MOVWF      R0+1
	RLF        R0+0, 1
	RLF        R0+1, 1
	BCF        R0+0, 0
	MOVF       R0+0, 0
	ADDLW      _ssdvec+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;Alpha.c,11 :: 		Delay_ms(1000);
	MOVLW      11
	MOVWF      R11+0
	MOVLW      38
	MOVWF      R12+0
	MOVLW      93
	MOVWF      R13+0
L_main5:
	DECFSZ     R13+0, 1
	GOTO       L_main5
	DECFSZ     R12+0, 1
	GOTO       L_main5
	DECFSZ     R11+0, 1
	GOTO       L_main5
	NOP
	NOP
;Alpha.c,9 :: 		for(i=0;i<6;i++)  {
	INCF       _i+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i+1, 1
;Alpha.c,12 :: 		}
	GOTO       L_main2
L_main3:
;Alpha.c,13 :: 		PORTB=0x00;
	CLRF       PORTB+0
;Alpha.c,14 :: 		Delay_ms(1000);
	MOVLW      11
	MOVWF      R11+0
	MOVLW      38
	MOVWF      R12+0
	MOVLW      93
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
;Alpha.c,15 :: 		i++;
	INCF       _i+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i+1, 1
;Alpha.c,18 :: 		}
	GOTO       L_main0
;Alpha.c,19 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
