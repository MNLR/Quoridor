#include <inc.h>

// This is the function where the magic really happens. 
// It makes the machine pseudointelligent

int e1Min1(nodo);
int e1Min2(nodo);
bool pawnDown(bool, nodo&);
bool pawnUp(bool, nodo&);
bool pawnRight(bool, nodo&);
bool pawnLeft(bool, nodo&);
bool wallPlace(mat2&, nodo&);
void print(nodo);

nodo siguiente2(nodo padre,int sucesor){
 mat2 wall;
 if (sucesor<=4){
 	switch(sucesor){
		case 1:
 			if (pawnDown(false, padre)){
				padre.tablero[2][2]=1;
			}
			else{
				padre.tablero[2][2]=-1;
			}
			break;
                case 2:
			if (pawnUp(false, padre)){
			        padre.tablero[2][2]=2;
			}
			else{
				padre.tablero[2][2]=-1;
			}
                	break;
                case 3:
                        if (pawnLeft(false, padre)){
                                padre.tablero[2][2]=3;
                        }
			else{
				padre.tablero[2][2]=-1;
			}
                	break;
                case 4:

                        if (pawnRight(false, padre)){
 	                       padre.tablero[2][2]=4;
        		}
			else{
				padre.tablero[2][2]=-1;
			}
                	break;


	}
 }
 else{
        if (sucesor <= 68){   // Horizontal Walls
                wall[0][0]= ((sucesor-5)/8+1)*2;
                wall[0][1]= ((sucesor-5)%8)*2+1;
                wall[1][0]=wall[0][0];
                wall[1][1]=wall[0][1]+2;
        }
        else {                // Vertical Walls
                wall[0][0]=((sucesor-69)%8)*2+1+2;
                wall[0][1]=((sucesor-69)/8+1)*2;
                wall[1][0]=wall[0][0]-2;
                wall[1][1]=wall[0][1];

        }
        if (wallPlace(wall, padre)){
                padre.tablero[2][2]=sucesor;
		padre.walles2--;
        }
        else{
                padre.tablero[2][2]=-1;
        }
 }

 return padre;
}

nodo siguiente1(nodo padre, int sucesor){
 mat2 wall;

 if (sucesor<=4){
 	switch(sucesor){
		case 1:
 			if (pawnUp(true, padre)){
				padre.tablero[2][2]=1;
			}
			else{
				padre.tablero[2][2]=-1;
			}
			break;
                case 2:
                        if (pawnDown(true, padre)){
                                padre.tablero[2][2]=2;
	                }
			else{
				padre.tablero[2][2]=-1;
			}
                	break;
                case 3:
                        if (pawnRight(true, padre)){
                                padre.tablero[2][2]=3;

		           }
                        else{
                                padre.tablero[2][2]=-1;
                        }
                	break;
                case 4:
 
                        if (pawnLeft(true, padre)){
                                padre.tablero[2][2]=4;
			 }
                        else{
                                padre.tablero[2][2]=-1;
                        }
                	break;


	}
 }
 else{
        if (sucesor <= 68){ 
                wall[0][0]= ((sucesor-5)/8+1)*2;
                wall[0][1]= ((sucesor-5)%8)*2+1;
                wall[1][0]=wall[0][0];
                wall[1][1]=wall[0][1]+2;
        }
        else {            
                wall[0][0]=((sucesor-69)%8)*2+1+2;
                wall[0][1]=((sucesor-69)/8+1)*2;
                wall[1][0]=wall[0][0]-2;
                wall[1][1]=wall[0][1];

        }
        if (wallPlace(wall, padre)){
                padre.tablero[2][2]=sucesor;
		padre.walles1--;
        }
        else{
                padre.tablero[2][2]=-1;
        }

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
                return e1Min1(in)-e1Min2(in);
        }
 }
 else{
 	if (mmax){
		seguir=true;
		sucesor=1;
		while(seguir){
			paso=siguiente2(in, sucesor);
			if (in.walles2==0){ // No walls left, minimax tree has breadth 4
				co=4;
			}
			else {
				co=132;
			}
			if (paso.tablero[2][2]!=-1){  
				eval=minimax(paso, n-1, false, alfa, beta);
				if (n==m) {
					if (eval>alfa){
						a=paso;
					}
				}
	        	        alfa=max(alfa, eval);
                        	if (beta<=alfa || sucesor==co){ 
                                	seguir=false;
                        	}
			}
			else {
				if (sucesor==co){
					seguir=false;
				}
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
                        if (in.walles1==0){
                                co=4;
                        }
                        else {
                                co=132;
                        }
			if (paso.tablero[2][2]!=-1){ 
				eval=minimax(paso, n-1, true, alfa, beta);
                                beta=min(beta, eval);
                                if (beta<=alfa || sucesor==co){
                                        seguir=false;
                                }
                        }
			else {
                        	if (sucesor==co){
                                	seguir=false;
				}
			}
                        sucesor++;

		}
		return beta;
	}

 }

}
