# Quoridor

Implementation of an AI that plays the game [Quoridor](https://boardgamegeek.com/boardgame/624/quoridor) in  C++. It uses a Minimax with Alpha-Beta Prunning and a Dynamic Programming approach for the heuristic function.

The game uses a very simple 2D graphics interface built using [Simple DirectMedia Layer](https://www.libsdl.org).

### Compilation Instructions

SDL2 development libraries and SDL_image are needed to compile the game. You can find the latest versions here: https://www.libsdl.org/download-2.0.php and here: https://www.libsdl.org/projects/SDL_image/.
For Linux users refer to your distribution maintainer. For instance, for Debian derivatives (in particular Ubuntu) you may use `apt-get`, i.e.

`sudo apt-get install libsdl2-dev libdsl2-image-dev`

The Makefile is ready to be executed using [GNU Make](https://www.gnu.org/software/make/). Quickest way to compile is by downloading the files into a directory, cding into it and typing `make` from the terminal. By default `make` executes the rule `ALL` from the Makefile, which compiles the objects and then links them into the executable. Other rules are an option, but should be used with care, refer to the [GNU Make Manual](https://www.gnu.org/software/make/manual/).

### How to Play

The rules of Quoridor are straightforward:

**Aim of the game:** The goal is to reach the other side of the board, which means reaching the top line for the player and the bottom line for the AI.
1. The board is 9×9. The game is played between two players. Each player has one pawn and *ten* walls.
2. Each player’s pawn starts on one side of the board in the center spaced. 
3. On a turn a player may take one action: move their pawn or place a wall.
4. Pawns move in four directions: up, down, left, or right. A pawn cannot move if there is a wall blocking that direction. Note that they block both players' movement.
5. Once placed walls cannot be moved. 
7. You can *never* completely wall in an opponent. There must always remain one path to the goal, i.e. top or bottom line, for each player.
8. When two pawns face each other on neighbouring squares which are not separated by a wall, the player whose turn it is can jump the opponent’s pawn (and place himself behind him), thus advancing an extra square. If there is a fence behind the said pawn, the player can place his pawn to the left or the right of the other pawn 

### Instructions

At start you will be prompted to input the dificulty. Input 1 for easy, 2 for medium and 3 for hard. Note that higher difficulties are an option, see next section. Then the board will open, you control the beige pawn and move first.



### A Note on Difficulty

Although 3 levels are sugested, you may input any positive integer when prompted to input the difficulty. This number is the depth of the minimax search, meaning the game will become harder, with the AI spending more and more time to make a move. A difficulty higher than 6 is likely to become unplayable even with a high end processor.
