//  Mikel N. Legasa


#include <inc.h>

// Main window dimensions extern
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 680;

// Aux functions
bool init();					// Starts SDL and loads the window
bool loadMedia();
void close();					// Shuts down SDL
SDL_Texture* loadTexture( std::string path );
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;			// Renderer
void loop();

void print(nodo);
void gPrint(nodo);

int m;
nodo a; 		// Main node. Board status.
bool mini1;             // Fixes a bug when minimax uses depth = 1 (dificulty level)

int main(int argc, char* args[]){
 short i,j, cosa;
 char op1, op2;
 mini1=false;
 cout<< "Input dificulty level \n 1: Easy 2: Medium 3: Hard 4+: Harder (Experimental) 8+: Nightmare (UberExperimental) \n";
 cin >> m;
 if (m==1){
	mini1=true;
 }

 // First node
 for (i=0; i<=18; i++){
	for (j=0; j<=18 ; j++){
		a.tablero[i][j]=0;
	}
 }

 // Board limits
 for (i=0; i<=18; i++) {
	a.tablero[0][i]=1;
	a.tablero[i][0]=1;
	a.tablero[i][18]=1;
	a.tablero[18][i]=1;
 }
 a.p1[0]=17;
 a.p1[1]=9;
 a.p2[0]=1;
 a.p2[1]=9;
 a.d1=8;
 a.d2=7;
 a.walles1=10;
 a.walles2=10;
 print(a);

 a.tablero[a.p1[0]][a.p1[1]]=1;
 a.tablero[a.p2[0]][a.p2[1]]=1;

 if( !init() ){
 	cout << "Failed to initialize SDL!\n" ;
 }
 else{
	if(!loadMedia()){
		cout << "Failed to load media!\n";
	}
	else{
		bool quit = false;
		SDL_Event e;
                SDL_Event t;
		gPrint(a);
		loop();
	close(); // Close SDL
	return 0;
	}
 }
}
