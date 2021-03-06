;Kevin Hu
;kwh2
;This program prints a value in hexadecimal notation by turning each group of four bits into a digit, 
;calculating the corresponding ASCII character, and printing that character to the monitor

.ORIG x3000


	AND R1, R1, #0 ; digit counter
	LD R5, FIFTY_FIVE ; initialize R5 to 55

OUTER_LOOP
	ADD R7, R1, #-4
	BRzp DONE
	AND R2, R2, #0 ; INITIALIZE BIT COUNTER
	AND R0, R0, #0 ; INITIALIZE DIGIT

INNER_LOOP
	ADD R6, R2, #-4
	BRzp PRINT
	ADD R0, R0, R0 ; LEFT SHIFT DIGIT
	ADD R3, R3, #0
	BRzp #1
	ADD R0, R0, #1
	ADD R3, R3, R3 ; LEFT SHIFT R3
	ADD R2, R2, #1 ; INCREMENT BIT COUNTER
	BRnzp INNER_LOOP

PRINT
	ADD R4, R0, #-9
	BRnz #1
	ADD R0, R0, R5 ; ADD A - 10
	OUT
	ADD R1, R1, #1 ; INCREMENT DIGIT COUNTER
	BRnzp OUTER_LOOP

DONE
	HALT

FIFTY_FIVE .FILL #55

.END

; write your code here
