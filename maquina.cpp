#include <inc.h>

bool arriba(short);
bool abajo(short);
bool izquierda(short);
bool derecha(short);

void maquina(mat2 &mov){

 if (mov[0][0]<0){
	switch(mov[0][0]){
		case -1:
			arriba(2);
			break;
 		case -2:
			abajo(2);
			break;
		case -3:
			izquierda(2);
			break;
		case -4:
			derecha(2);
			break;
	}
 }
 else{
	a.tablero[mov[0][0]][mov[0][1]]=true;
	a.tablero[mov[1][0]][mov[1][1]]=true;
 }
}
