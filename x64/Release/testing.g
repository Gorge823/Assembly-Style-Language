start:
	call hello

	mov iax, 4
	mov ibx, 3000
	syscall

	mov iax, 2
	mov ibx, 0
	syscall
