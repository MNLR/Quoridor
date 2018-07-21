###########   © Mikel N. Legasa
### Makefile for Quoridor

# This is a wrapper of the Makefile located in source/

all:
	cd source/ && make quoridor && mv Quoridor ..
clean:
	cd source/ && make clean
cleanall:
	cd source/ && make clean && rm Quoridor
