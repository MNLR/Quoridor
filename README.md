# Quoridor

Implementation of an AI that plays the game [Quoridor](https://boardgamegeek.com/boardgame/624/quoridor) in  C++. It uses a Minimax with Alpha-Beta Prunning and a Dynamic Programming approach for the heuristic function.

The game uses a very simple 2D graphic interface built using [Simple DirectMedia Layer](https://www.libsdl.org). 

The executable provided (Quoridor) is precompiled for Debian based systems.

### Compilation and Installation Instructions

SDL2 development libraries and SDL_image are needed to compile the game. You can find the latest versions here: https://www.libsdl.org/download-2.0.php and here: https://www.libsdl.org/projects/SDL_image/.
For Linux users refer to your distribution maintainer. For instance, for Debian derivatives (in particular Ubuntu) you may use `apt-get`, i.e.

`sudo apt-get install libsdl2-dev libdsl2-image-dev`

The Makefile is ready to be executed using [GNU Make](https://www.gnu.org/software/make/). Quickest way to compile is by downloading the files into a directory, cding into it and typing `make` from the terminal. By default `make` executes the rule `ALL` from the Makefile, which compiles the objects and then links them into the executable. Other rules are an option, but should be used with care, refer to the [GNU Make Manual](https://www.gnu.org/software/make/manual/).

Under Windows systems you may either use your preferred IDE or use the Makefile itself, something you can do, e.g. by employing [GNUWin's Make](https://sourceforge.net/projects/gnuwin32/?source=typ_redirect) or through Visual Studio. Note that it is likely that you will need to modify the Makefile to point to the includes.

### How to Play

The rules of Quoridor are straightforward:

**Aim of the game:** The goal is to reach the other side of the board, which means reaching the top line for the player and the bottom line for the AI.
1. The board is 9×9. The game is played between two players. Each player has one pawn and *ten* walls.
2. Each player’s pawn starts on one side of the board in the center spaced. 
3. On a turn a player may take one action: move their pawn or place a wall.
4. Pawns move in four directions: up, down, left, or right. A pawn cannot move if there is a wall blocking that direction. Note that they block both players' movement.
5. Once placed walls cannot be moved. 
7. You can *never* completely wall in an opponent. There must always remain one path to the goal, i.e. top or bottom line, for each player.
8. When two pawns face each other on neighbouring squares which are not separated by a wall, the player whose turn it is can jump the opponent’s pawn (and place himself behind him), thus advancing an extra square. If there is a fence behind the said pawn, the player can place his pawn to the left or the right of the other pawn.

Watch [this](https://www.youtube.com/watch?v=lOCWJw61M6A) video if it is still unclear.

### Instructions

To **start the game**, execute the compiled file `Quoridor` (In bash use `./Quoridor` where this file is located i.e. in the main directory).

At start you will be prompted to input the dificulty. Input 1 for easy, 2 for medium and 3 for hard. Note that higher difficulties are an option, see next section. Then the board will open, you control the beige pawn and move first.

Controls:

* Use `arrow keys` to move the pawn:

   `←` : move your pawn left

   `→` : move your pawn right

   `↑` : move your pawn up

   `↓` : move your pawn down

* Press `p`  to start placing a wall. The wall will appear on the screen, then use:

   `←` : move your pawn left

   `→` : move your pawn right

   `↑` : move your pawn up

   `↓` : move your pawn down
   
   `r` : rotate the wall
  
   `Enter` : place the wall
   
   `Esc` : Cancel wall placing
   
   Note that if you try to place a wall where you would block every path to your enemy's or your own goal, pressing `Enter` won't work, and that if you try to place a wall and there are none left `p` won't work either.

* Press `F5` to update the screen if it gets blurred out or are any graphic artifact should should appear.


### A Note on Difficulty

Although 3 levels are sugested, you may input any positive integer when prompted to input the difficulty. This number is the depth of the minimax search, meaning the game will become harder, with the AI spending more and more time to make a move. A difficulty higher than 6 is likely to become unplayable even with a high end processor.

### Final Note and Contributing: 

This was a personal project that I created several years ago (before C++14 came out), when I was an undergraduate student, in which I am no longer working on. The objective was to make the computer be able to play a moderately complex game and be competent at it, and also creating a playable interface. This provides a basis for further improvements, in particular and not restricted to 1) Using heuristic search approaches for exploring the tree in the minimax algorithm, thus making the AI stochastic, less reliable but much more imaginative 2) using Machine Learning techniques for more complex AIs or 3) testing different evaluation measures.
