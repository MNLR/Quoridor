#include <inc.h>



//
//
//    LOS NODOS SE CREAN CORRECTAMENTE. REVISAR DESCARTES (POR INSPECCIÓN PARECEN CORRECTOS) Y VERIFICAR CÓMO DEVOLVER CORRECTAMENTE LA SOLUCIÓN.
//    NO LO HACEN. REVISAR DEVOLUCIÓN DE NODOS Y MODIFICACIÓN PASO POR VALOR Y REFERENCIA
//    PARECEN ESTAR ARREGLADOS. MUCHO CUIDADO CON MODIFICAR NODO IN Y CON EL PASO POR REFERENCIA. HAY QUE BUSCAR UNA FORMA DE DEVOLVER LA SOLUCIÓN.

int e1_min1(nodo);
int e1_min2(nodo);
bool abajo(bool, nodo&);
bool arriba(bool, nodo&);
bool derecha(bool, nodo&);
bool izquierda(bool, nodo&);
void imprimir(nodo);

nodo siguiente2(nodo padre,int sucesor){
 
 if (sucesor<=4){
 	cout << "sucesor nodo MAX: " << sucesor << "\n";

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
 else{    // Paredes. Función conversora:
  
 }

 return padre;
}

nodo siguiente1(nodo padre, int sucesor){
 cout << "Sucesor nodo MIN " << sucesor << "\n";
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
                        if (izquierda(true, padre)){
                                padre.tablero[2][2]=3;

		           }
                        else{
                                padre.tablero[2][2]=-1;
                        }
                	break;
                case 4:
 
                        if (derecha(true, padre)){
                                padre.tablero[2][2]=4;
			 }
                        else{
                                padre.tablero[2][2]=-1;
                        }
                	break;


	}
 }
 else{    // Paredes. Función conversora:
  
 }

 return padre;
}


int minimax(nodo in, int n, bool mmax, int alfa, int beta){

 bool seguir;
 int eval;
 nodo paso;
 nodo sol;
 int sucesor;
 int cont;
 cout << "Minimax " << n << "\n";


 if (n==0){
	cout << "Minimax ejecutándose: " << e1_min1(in)-e1_min2(in) << " , el nodo HOJA es movimiento: " << in.tablero[2][2] << " y tablero :\n";
	imprimir(in);
	cout << "                                             FIN NODO HOJA  n\n";
        return e1_min1(in)-e1_min2(in);

 }
 else{
 	if (mmax){
		seguir=true;
		sucesor=1;
		while(seguir){
			paso=siguiente2(in, sucesor);
			//cout << "               (MAX)         Imprimiendo nodo de paso: \n";
			//imprimir(paso);
			//cout <<"       FIN PASO\n";

			if (paso.tablero[2][2]!=-1){   // Si no se descarta el nodo.
				cont++;
				eval=minimax(paso, n-1, false, alfa, beta);
				cout << "eval" << eval << "\n";
				if (n==m) {
					if (eval>alfa){
						cout << "Actualizando solución \n";
						a=paso;
						cout << "Movimiento máquina: " << paso.tablero[2][2] << "\n";
					}
				}
	        	        alfa=max(alfa, eval);
	        	        cout << "Alfa: " << alfa << "\n";
				if (beta<=alfa || sucesor==4){ // Último subnodo del padre o poda alfa-beta.
			
				        cout << "HA HABIDO UN DESCARTE NODO MAX con último sucesor " << sucesor << "\n";
					seguir=false;
				}
			}
			else {
				cout << "nodo " << sucesor << " Descartado (" << paso.tablero[2][2]<< ")";
			}
			sucesor++;
		}
		return alfa;
 	}
	else{
		seguir=true;
		sucesor=1;
		while(seguir){
                        paso=siguiente1(in, sucesor);
			//cout << "    (MIN)   Imprimiendo nodo de paso: \n";
                        //imprimir(paso);
                        //cout <<"      FIN PASO\n";
			if (paso.tablero[2][2]!=-1){   // Si no se descarta el nodo.
				eval=minimax(paso, n-1, true, alfa, beta);
				cout << "eval: " << eval << "\n";
	        	        beta=min(beta, eval);
	        	        cout << "Beta: " << beta << "\n";
				if (beta<=alfa || sucesor==4){ // Último subnodo del padre o poda alfa-beta.
					cout << "HA HABIDO UN DESCARTE NODO MIN con último sucesor " << sucesor << "\n";
					seguir=false;
				}
			}
			sucesor++;
		}
		return beta;
	}

 }

}
