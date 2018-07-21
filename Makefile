###########   © Mikel N. Legasa Ríos

##
### Executable, Objects and Dependencies
##

EX = juego
OB = ciclo.o arriba.o abajo.o derecha.o izquierda.o pared.o paredc.o\
 imprimir.o e1_min1.o e1_min2.o minimax.o gimprimir.o gimprimiraux.o \
 init.o loadMedia.o loadTexture.o close.o    #Excl. main.o - It has his own rule.
DP = inc.h

##
###
##

MAIN = $(wildcard *main.cpp)
MAINo = $(patsubst %.cpp,%.o,$(MAIN))
CLDIR = $(EX) $(OB) *main.o *~ *save

##
### Compiler and linker
##

C = g++
CF = -w -Wall -Wextra -I. -std=c++11 -fpermissive #Compiler flags
LF = -w -Wall -Wextra -std=c++11 -fpermissive #Linker flags
SDLF = -lSDL2 -lSDL2_image #Additional SDL flags


##
### Rules
##

all: $(EX)

$(EX):  $(MAINo) $(OB)
	$(C) $(LF) -o $@ $^ $(SDLF)

$(MAINo): $(MAIN) $(DP) $(OB)
	$(C) $(CF) -c -o $@ $<

$(OB): %.o:  %.cpp
	$(C) $(CF) -c -o $@ $<

### Cleanup
clean:
	rm -rf $(OB) *.o *~
###
cleanall:
	rm -rf $(CLDIR)
