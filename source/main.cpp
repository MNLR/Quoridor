//  Mikel N. Legasa Ríos.


#include <inc.h>

// Dimensiones ventana principal - extern
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 680;

// Funciones auxiliares
bool init();					// Inicia SDL y crea la ventana
bool loadMedia();				// Carga media
void close();					// Libera la memoria y apaga SDL
SDL_Texture* loadTexture( std::string path );   // Carga imagen como textura
SDL_Window* gWindow = NULL;			// Ventana a la que se renderizará
SDL_Renderer* gRenderer = NULL;			// Renderizador de ventana
void loop();

void print(nodo);
void gPrint(nodo);

int m;
nodo a; // Nodo principal. Estado actual del tablero.
bool modificado;    // Variable de control minimax modificado.
bool mini1;         // Corrige funcionamiento 1 nivel

int main(int argc, char* args[]){
 short i,j, cosa;
 char op1, op2;
 modificado=false;
 mini1=false;
 cout<< "¿Dificultad? 1: Fácil 2: Medio 3: Difícil \n";
 cin >> m;
 if (m==1){
	mini1=true;
 }
 cout << "¿Minimax (n) o Minimax modificado (m)? \n";
 cin >> op1;
 if (op1=='m'){
	modificado=true;
 }
 // Inicialización primer nodo.
 for (i=0; i<=18; i++){
	for (j=0; j<=18 ; j++){
		a.tablero[i][j]=0;
	}
 }

 //Límites del tablero
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
 	cout << "Failed to initialize!\n" ;
 }
 else{
	if(!loadMedia()){
		cout << "Failed to load media!\n";
	}
	else{
		bool quit = false;	// flag loop principal
		SDL_Event e;   		// variables manejo de eventos
                SDL_Event t;
		gPrint(a);
		
		loop();
	// Liberar recursos y cerrar SDL.
	close();
	return 0;
	}
 }
}
