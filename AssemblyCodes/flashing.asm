
;*****Set up the Constants****
STATUS equ 03h ;Address of the STATUS register
TRISA equ 85h ;Address of the tristate register for port A
PORTA equ 05h ;Address of Port A
COUNT1 equ 08h ;First counter for our delay loops
COUNT2 equ 09h ;Second counter for our delay loops


;****Set up the port****
	bsf STATUS,5 ;Switch to Bank 1
	movlw 00h ;Set the Port A pins
	movwf TRISA ;to output.
	bcf STATUS,5 ;Switch back to Bank 0
	movlw 02h ;Set up our w register with 02h

;****Turn the LED on and off****
Start xorwf PORTA,1 ;Toggle the LED



;****Add a delay
call Delay

;****Now go back to the start of the program
goto Start ;go back to Start and turn LED on again

;****Here is our Subroutine
Delay
Loop1 decfsz COUNT1,1 ;This second loop keeps the LED
goto Loop1 ;turned off long enough for us to
decfsz COUNT2,1 ;see it turned off
goto Loop1 ;
return
;****End of the program****