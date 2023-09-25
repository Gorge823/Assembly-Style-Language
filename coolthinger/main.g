start:
	mov iax, 2
	mov sax, "1: Add\n2: Subtract\n"
	syscall

	mov iax, 3
	syscall

	mov icx, sax

	mov iax, 2
	mov sax, "Input value #1:\n"
	syscall

	mov iax, 3
	syscall

	mov idx, sax
	
	mov iax, 2
	mov sax, "Input value #2:\n"
	syscall

	mov iax, 3
	syscall
	mov iex, sax	

	comp icx, 1
	je add

	comp icx, 2
	je sub

	mov iax, 0
	mov ibx, 1
	syscall	
