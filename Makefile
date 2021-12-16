all: stringProg

stringProg: main.o str.o 
	gcc -Wall -o stringProg main.o str.o

main.o: main.c str.h
	gcc -Wall -c main.c

str.o: str.c str.h
	gcc -Wall -c str.c

.PHONY: clean all
	
clean:
	rm -f *.o stringProg *.txt
		
