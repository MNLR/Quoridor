#include <inc.h>

bool pawnUp(short);
bool pawnDown(short);
bool pawnLeft(short);
bool pawnRight(short);

void machine(mat2 &mov){

 if (mov[0][0]<0){
	switch(mov[0][0]){
		case -1:
			pawnUp(2);
			break;
 		case -2:
			pawnDown(2);
			break;
		case -3:
			pawnLeft(2);
			break;
		case -4:
			pawnRight(2);
			break;
	}
 }
 else{
	a.tablero[mov[0][0]][mov[0][1]]=true;
	a.tablero[mov[1][0]][mov[1][1]]=true;
 }
}
