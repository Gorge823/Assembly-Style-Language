add:
	mov iax, 2
	mov sax, idx
	syscall
	mov sax, "+"
	syscall
	mov sax, iex
	syscall
	mov sax, "="
	syscall

	add idx, iex
	
	mov sax, idx
	syscall
	
	mov iax, 5
	syscall

	mov iax, 0
	mov ibx, 0
	syscall
