#include <inc.h>

void gPrintAux(nodo);

void wall(mat2 &wall, int i, nodo aux){
 switch(i){
	case 1:
		if (wall[0][0]==wall[1][0]){
			wall[0][0]=wall[0][0]+1;
                	wall[0][1]=wall[0][1]+1;
                	wall[1][0]=wall[1][0]-1;
			wall[1][1]=wall[1][1]-1;
		}
		else{
                	wall[0][0]=wall[0][0]-1;
               		wall[0][1]=wall[0][1]-1;
                	wall[1][0]=wall[1][0]+1;
                	wall[1][1]=wall[1][1]+1;
		}
		cout << "Pared: "<<"("<<wall[0][0]<<","<<wall[0][1]<<"):("<<wall[1][0]<<","<<wall[1][1]<<") \n"; 
		break;
	case 2:
		if (wall[0][0]-2 >=1 && wall[1][0]-2 >=1){
			wall[0][0]=wall[0][0]-2;
                	wall[1][0]=wall[1][0]-2;
		}
		cout << "Pared: "<<"("<<wall[0][0]<<","<<wall[0][1]<<"):("<<wall[1][0]<<","<<wall[1][1]<<") \n"; 
		break;
	case 3:
		if (wall[0][0]+2 <=17 && wall[1][0]+2 <=17){
                	wall[0][0]=wall[0][0]+2;
                	wall[1][0]=wall[1][0]+2;
		}
		cout << "Pared: "<<"("<<wall[0][0]<<","<<wall[0][1]<<"):("<<wall[1][0]<<","<<wall[1][1]<<") \n"; 
		break;
	case 4:
                if (wall[0][1]-2 >=1 && wall[1][1]-2 >=1){
			wall[0][1]=wall[0][1]-2;
                	wall[1][1]=wall[1][1]-2;
		}
		cout << "Pared: "<<"("<<wall[0][0]<<","<<wall[0][1]<<"):("<<wall[1][0]<<","<<wall[1][1]<<") \n"; 
                break;
	case 5:
                if (wall[0][1]+2 <=17 && wall[1][1]+2 <=17){
			wall[0][1]=wall[0][1]+2;
                	wall[1][1]=wall[1][1]+2;
		}
		cout << "Pared: "<<"("<<wall[0][0]<<","<<wall[0][1]<<"):("<<wall[1][0]<<","<<wall[1][1]<<") \n"; 
                break;
 }
 aux.tablero[wall[0][0]][wall[0][1]]=2;
 aux.tablero[wall[1][0]][wall[1][1]]=2;
 gPrintAux(aux);
}
