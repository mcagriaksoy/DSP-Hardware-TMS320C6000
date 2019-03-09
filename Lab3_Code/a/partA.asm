
		.text					; read-only
		.global _partA
		
_partA:	MV		A6, B1			; Loop counter
		ZERO		A7				; Output accumulator
		
loop:		LDH 		*A4++, A0
		LDH 		*B4++, B0
		NOP		4
		
		MPY		A0, A0, A0
		MPY		B0, B0, B0
		NOP		

		SUB		A0, B0, A0
		ABS		A0, A0
		ADD		A0, A7, A7
		SUB		B1, 1, B1		; Decrement loop counter

    [B1]   B		loop
		NOP		5
		STH 		A7,*A4		; MV		A7, A4
							; Return the sum in A4
							
		B		B3
		NOP		5
		.end




