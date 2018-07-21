#include <inc.h>

void gimprimiraux(nodo);

void pared(mat2 &pared, int i, nodo aux){
 switch(i){
	case 1:  //Rotar
		if (pared[0][0]==pared[1][0]){
			pared[0][0]=pared[0][0]+1;
                	pared[0][1]=pared[0][1]+1;
                	pared[1][0]=pared[1][0]-1;
			pared[1][1]=pared[1][1]-1;
		}
		else{
                	pared[0][0]=pared[0][0]-1;
               		pared[0][1]=pared[0][1]-1;
                	pared[1][0]=pared[1][0]+1;
                	pared[1][1]=pared[1][1]+1;
		}
		cout << "Pared: "<<"("<<pared[0][0]<<","<<pared[0][1]<<"):("<<pared[1][0]<<","<<pared[1][1]<<") \n"; 
		break;
	case 2:  //Arriba
		if (pared[0][0]-2 >=1 && pared[1][0]-2 >=1){
			pared[0][0]=pared[0][0]-2;
                	pared[1][0]=pared[1][0]-2;
		}
		cout << "Pared: "<<"("<<pared[0][0]<<","<<pared[0][1]<<"):("<<pared[1][0]<<","<<pared[1][1]<<") \n"; 
		break;
	case 3:  //Abajo
		if (pared[0][0]+2 <=17 && pared[1][0]+2 <=17){
                	pared[0][0]=pared[0][0]+2;
                	pared[1][0]=pared[1][0]+2;
		}
		cout << "Pared: "<<"("<<pared[0][0]<<","<<pared[0][1]<<"):("<<pared[1][0]<<","<<pared[1][1]<<") \n"; 
		break;
	case 4:  //Izda
                if (pared[0][1]-2 >=1 && pared[1][1]-2 >=1){
			pared[0][1]=pared[0][1]-2;
                	pared[1][1]=pared[1][1]-2;
		}
		cout << "Pared: "<<"("<<pared[0][0]<<","<<pared[0][1]<<"):("<<pared[1][0]<<","<<pared[1][1]<<") \n"; 
                break;
	case 5:  //Ddcha
                if (pared[0][1]+2 <=17 && pared[1][1]+2 <=17){
			pared[0][1]=pared[0][1]+2;
                	pared[1][1]=pared[1][1]+2;
		}
		cout << "Pared: "<<"("<<pared[0][0]<<","<<pared[0][1]<<"):("<<pared[1][0]<<","<<pared[1][1]<<") \n"; 
                break;
 }
 aux.tablero[pared[0][0]][pared[0][1]]=2;
 aux.tablero[pared[1][0]][pared[1][1]]=2;
 gimprimiraux(aux);
}








