;*****Set up the Constants****
STATUS equ 03h ;Address of the STATUS register
TRISA equ 85h ;Address of the tristate register for port A
PORTA equ 05h ;Address of Port A
COUNT1 equ 08h ;First counter for our delay loops
COUNT2 equ 09h ;Second counter for our delay loops
;****Set up the port****
bsf STATUS,5 ;Switch to Bank 1
movlw 01h ;Set the Port A pins:
movwf TRISA ;bit 1to output, bit 0 to input.
bcf STATUS,5 ;Switch back to Bank 0
;****Turn the LED on****
Start movlw 02h ;Turn the LED on by first putting it
movwf PORTA ;into the w register and then on the port
;****Check if the switch is closed
BTFSC PORTA,0 ;Get the value from PORT A
;BIT 0. If it is a zero
call Delay ;a zero, carry on as normal.
;If is is a 1, then add an
;extra delay routine

;****Add a delay
call Delay
;****Delay finished, now turn the LED off****
movlw 00h ;Turn the LED off by first putting it
movwf PORTA ;into the w register and then on the port

;****Check if the switch is still closed
BTFSC PORTA,0 ;Get the value from PORT A
;BIT 0. If it is a zero,
call Delay ;carry on as normal.
;If is a 1, then add an
;extra delay routine
;****Add another delay****
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
end ;Needed by some compilers, and also
;just in case we miss the goto instruction.