CC=gcc
program: traductor.c
	$(CC) traductor.c numero_a_letras.c romano_decimal.c -o traductor 
