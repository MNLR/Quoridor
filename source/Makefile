###########   © Mikel N. Legasa

##
### Executable, Objects and Dependencies
##

EX = Quoridor
OB = loop.o pawnUp.o pawnDown.o pawnRight.o pawnLeft.o wall.o wallPlace.o\
 print.o e1Min1.o e1Min2.o minimax.o gPrint.o gPrintAux.o \
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

quoridor: $(EX)

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
