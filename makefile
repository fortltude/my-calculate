all:book1


book1:calculate.c shift.h Stack.h calculate.h
        gcc calculate.c -o calculate.exe -lreadline