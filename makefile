all:book1


book1:main.c calculate.c shift.c Stack.c shift.h Stack.h calculate.h
	gcc main.c Stack.c shift.c calculate.c -o calculate.exe -lreadline