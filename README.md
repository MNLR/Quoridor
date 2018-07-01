# Quoridor

Implementation of an AI that plays the game [Quoridor](https://boardgamegeek.com/boardgame/624/quoridor) in  C++. It uses a Minimax with Alpha-Beta Prunning and a Dynamic Programming approach for the heuristic function.

The game uses a very simple graphics interface built using [Simple DirectMedia Layer](https://www.libsdl.org).

[Work in Progress]

### Compilation instructions
The Makefile is ready to be executed using [GNU Make](https://www.gnu.org/software/make/). Quickest way to compile is by downloading the files into a directory, cding into it and typing `make` from the terminal. By default `make` executes the rule `ALL` from the Makefile, other rules are an option, but should be used with care, refer to the [GNU Make Manual](https://www.gnu.org/software/make/manual/).
