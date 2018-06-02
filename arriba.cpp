#include <inc.h>

bool arriba(bool ficha, nodo &in){

 switch(ficha){
	case true:
		if (in.tablero[in.p1[0]-1][in.p1[1]]==1){  //Comprueba pared obstruyendo movimiento
			return false;
 		}
 		else{
			if (in.tablero[in.p1[0]-2][in.p1[1]]==1){    // Comprueba ficha en posición. 1 si sí.
 				if (in.tablero[in.p1[0]-3][in.p1[1]]==1){   //Comprueba pared tras ficha. 1 si sí.
					return false;
 				}
				else{
                                        in.tablero[in.p1[0]][in.p1[1]]=0;
                                        in.p1[0]=in.p1[0]-4;		// Salto ficha
					in.tablero[in.p1[0]][in.p1[1]]=1;
					return true;
					}
			}
			else{
                                in.tablero[in.p1[0]][in.p1[1]]=0;
				in.p1[0]=in.p1[0]-2;			// Movimiento normal
				in.tablero[in.p1[0]][in.p1[1]]=1;
				return true;
			}
		}
		break;
        case false:
                if (in.tablero[in.p2[0]-1][in.p2[1]]==1){  //Comprueba pared obstruyendo movimiento
 			return false;
                }
                else{
                        if (in.tablero[in.p2[0]-2][in.p2[1]]==1){    // Comprueba ficha en posición. 1 si sí.
                                if (in.tablero[in.p2[0]-3][in.p2[1]]==1){   //Comprueba pared tras ficha. 1 si sí.
                                        return false;
                                }
                                else{
                                        in.tablero[in.p2[0]][in.p2[1]]=0;
                                        in.p2[0]=in.p2[0]-4;              // Salto ficha
                                        in.tablero[in.p2[0]][in.p2[1]]=1;
                                        return true;
                                        }
                        }
                        else{
                                in.tablero[in.p2[0]][in.p2[1]]=0;
                                in.p2[0]=in.p2[0]-2;                      // Movimiento normal
                                in.tablero[in.p2[0]][in.p2[1]]=1;
                                return true;
                        }
                }
                break;
 }
}

