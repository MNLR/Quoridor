###########   © Mikel N. Legasa
### Makefile for Quoridor

# This Makefile wraps the Makefile located in source/

all:
	cd source/ && make quoridor && cp Quoridor ..
clean:
	cd source/ && make clean
cleanall:
	cd source/ && make cleanall && cd .. && rm -f Quoridor
