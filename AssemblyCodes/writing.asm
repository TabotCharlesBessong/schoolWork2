STATUS equ 03h 
TRISA equ 85h
PORTA equ 05h
COUNT1 equ 08h
COUNT2 equ 09h

;setting  up our  port
bsf STATUS,5 ; go to bank 1
movlw 00h ; put 00000 into w 
movwf TRISA ; move 00000 onto TRISA and set all pins  to output 
bcf STATUS,5 ; come back to bank 0 

; turning the  led on 
Start movlw 02h ; add binary 00010 into w register 
	  movwf PORTA ; move content of w to port a 

; getting our  first delay 
		call	Delay 


; offing the  led 
movlw 00h ; oof the led 
movwf PORTA ; modify the value of the port a

; getting our  second delay 
		call 	Delay 

 
goto Start

Delay 
Loop1  decfsz	 COUNT1,1 ; substract 1 from 255
		goto 	Loop1; carry on with the count
		decfsz	COUNT2,1 
		goto 	Loop1
return 

end  