#include <inc.h>



//
//
//    
//    

int e1_min1(nodo);
int e1_min2(nodo);
bool abajo(bool, nodo&);
bool arriba(bool, nodo&);
bool derecha(bool, nodo&);
bool izquierda(bool, nodo&);
bool paredc(mat2&, nodo&);
void imprimir(nodo);

nodo siguiente2(nodo padre,int sucesor){
 mat2 pared;
 if (sucesor<=4){
 	switch(sucesor){
		case 1:
 			if (abajo(false, padre)){
				padre.tablero[2][2]=1;
			}
			else{
				padre.tablero[2][2]=-1;
			}
			break;
                case 2:
			if (arriba(false, padre)){
			        padre.tablero[2][2]=2;
			}
			else{
				padre.tablero[2][2]=-1;
			}
                	break;
                case 3:
                        if (izquierda(false, padre)){
                                padre.tablero[2][2]=3;
                        }
			else{
				padre.tablero[2][2]=-1;
			}
                	break;
                case 4:

                        if (derecha(false, padre)){
 	                       padre.tablero[2][2]=4;
        		}
			else{
				padre.tablero[2][2]=-1;
			}
                	break;


	}
 }
 else{
        if (sucesor <= 68){   // Paredes horizontales.
                pared[0][0]= ((sucesor-5)/8+1)*2;
                pared[0][1]= ((sucesor-5)%8)*2+1;
                pared[1][0]=pared[0][0];
                pared[1][1]=pared[0][1]+2;
        }
        else {                // Paredes verticales
                pared[0][0]=((sucesor-69)%8)*2+1+2;
                pared[0][1]=((sucesor-69)/8+1)*2;
                pared[1][0]=pared[0][0]-2;
                pared[1][1]=pared[0][1];

        }
        if (paredc(pared, padre)){
                padre.tablero[2][2]=sucesor;
		padre.paredes2--;
        }
        else{
                padre.tablero[2][2]=-1;
        }
 //cout << "Pared: "<<"("<<pared[0][0]<<","<<pared[0][1]<<"):("<<pared[1][0]<<","<<pared[1][1]<<") \n"; 

 }

 return padre;
}

nodo siguiente1(nodo padre, int sucesor){
 mat2 pared;

 if (sucesor<=4){
 	switch(sucesor){
		case 1:
 			if (arriba(true, padre)){
				padre.tablero[2][2]=1;
			}
			else{
				padre.tablero[2][2]=-1;
			}
			break;
                case 2:
                        if (abajo(true, padre)){
                                padre.tablero[2][2]=2;
	                }
			else{
				padre.tablero[2][2]=-1;
			}
                	break;
                case 3:
                        if (derecha(true, padre)){
                                padre.tablero[2][2]=3;

		           }
                        else{
                                padre.tablero[2][2]=-1;
                        }
                	break;
                case 4:
 
                        if (izquierda(true, padre)){
                                padre.tablero[2][2]=4;
			 }
                        else{
                                padre.tablero[2][2]=-1;
                        }
                	break;


	}
 }
 else{
        if (sucesor <= 68){   // Paredes horizontales.
                pared[0][0]= ((sucesor-5)/8+1)*2;
                pared[0][1]= ((sucesor-5)%8)*2+1;
                pared[1][0]=pared[0][0];
                pared[1][1]=pared[0][1]+2;
        }
        else {                // Paredes verticales
                pared[0][0]=((sucesor-69)%8)*2+1+2;
                pared[0][1]=((sucesor-69)/8+1)*2;
                pared[1][0]=pared[0][0]-2;
                pared[1][1]=pared[0][1];

        }
        if (paredc(pared, padre)){
                padre.tablero[2][2]=sucesor;
		padre.paredes1--;
        }
        else{
                padre.tablero[2][2]=-1;
        }
 //cout << "Pared: "<<"("<<pared[0][0]<<","<<pared[0][1]<<"):("<<pared[1][0]<<","<<pared[1][1]<<") \n"; 

 }
 return padre;
}



int minimax(nodo in, int n, bool mmax, int alfa, int beta){

 bool seguir;
 int eval;
 nodo paso;
 nodo sol;
 int sucesor;
 int co;

 if (n==0  || in.p1[0]==1 || in.p2[0]==17){
        if (in.p1[0]==1 || in.p2[0]==17){
                switch (mmax){
                        case true:
                                if (in.p2[0]==1){
                                        return 100;
                                }
                                else{
                                        return -100;
                                }
                                break;
                        case false:
                                if (in.p2[0]==1){
                                        return -100;
                                }
                                else{
                                        return 100;
                                }
                        break;
                }
        }
        else{
                return e1_min1(in)-e1_min2(in);
        }
 }
 else{
 	if (mmax){
		seguir=true;
		sucesor=1;
		while(seguir){
			paso=siguiente2(in, sucesor);
			if (in.paredes2==0){  // En el nodo padre no quedan paredes => No se exploran subnodos con paredes.
				co=4;
			}
			else {
				co=132;
			}
			if (paso.tablero[2][2]!=-1){   // Si no se descarta el nodo.
				eval=minimax(paso, n-1, false, alfa, beta);
				if (n==m) {
					if (eval>alfa){
						a=paso;
					}
				}
	        	        alfa=max(alfa, eval);
	        	        //cout << "Movimiento: " << paso.tablero[2][2] <<" con alfa: " << alfa << "\n";
                        	if (beta<=alfa || sucesor==co){ 
                                	seguir=false;
                        	}
			}
			else {
				if (sucesor==co){  // También debe comprobarse fuera. Por si el nodo es descartado.
					seguir=false;
				}
			}
			sucesor++;
			//cout << "("<<sucesor<<")";
		}
		return alfa;
 	}
	else{
		seguir=true;
		sucesor=1;
		while(seguir){
                        paso=siguiente1(in, sucesor);
                        if (in.paredes1==0){  // En el nodo padre no quedan paredes => No se exploran subnodos con paredes.
                                co=4;
                        }
                        else {
                                co=132;
                        }
			if (paso.tablero[2][2]!=-1){   // Si no se descarta el nodo.
				eval=minimax(paso, n-1, true, alfa, beta);
                                beta=min(beta, eval);
				//cout << "Movimiento: " << paso.tablero[2][2] <<" con beta: " << beta << "\n";

                                if (beta<=alfa || sucesor==co){
                                        seguir=false;
                                }
                        }
			else {      // Para evitar doble comprobación
                        	if (sucesor==co){  // También debe comprobarse fuera. Por si el nodo es descartado.
                                	seguir=false;
				}
			}
                        sucesor++;

		}
		return beta;
	}

 }

}
