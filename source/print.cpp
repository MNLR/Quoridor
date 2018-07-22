#include <inc.h>

int e1Min1(nodo);
int e1Min2(nodo);

void print(nodo aa){
 int i,j;
 for (i=1; i<=17; i++){
	cout <<" |";
	if (i%2==1){
		for (j=1; j<=9 ; j++){
			if (aa.p1[0]==i && aa.p1[1]==2*j-1){
				cout << "o";
			}
			else{
	                        if (aa.p2[0]==i && aa.p2[1]==2*j-1){
	                                cout<<"x";
                        	}

				else{
					cout<<"□";
				}
			}
			if (aa.tablero[i][2*j]==true){
				cout <<"|";
			}
			else{
				cout<<" ";
			}
 		}
	cout << "\n";
	}
	else{
		for (j=1; j<=17 ; j++){
			if(j%2==1){
                        	if (aa.tablero[i][j]==true){
                                	cout <<"_";
                        	}
				else{
					cout<<" ";
				}
			}
			else {
				cout <<" ";
			}
		}
 	cout << "\n";
	}
 }
 cout << "Posición 1: (";
 cout << aa.p1[0] << "," << aa.p1[1]<<") \n";
 cout << "Posición 2: (";
 cout << aa.p2[0] << "," << aa.p2[1]<<") \n";
 cout << "Paredes restantes 1: " << aa.walles1 << "\n";
 cout << "Paredes restantes 2: " << aa.walles2 << "\n";
 aa.d1=e1Min1(aa);
 aa.d2=e1Min2(aa);
 cout << "Distancia 1: " << aa.d1 << "\n";
 cout << "Distancia 2: " << aa.d2 << "\n";
 cout << "Evaluación : " << aa.d1-aa.d2 << "\n";
 cout << "Último movimiento máquina: " << aa.tablero[2][2] <<"\n";
}
