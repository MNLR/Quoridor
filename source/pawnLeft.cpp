#include <inc.h>

bool pawnLeft(bool ficha, nodo &in){
 switch(ficha){
        case true:
                if (in.tablero[in.p1[0]][in.p1[1]-1]==1){
                        return false;
                }
                else{
                        if (in.tablero[in.p1[0]][in.p1[1]-2]==1){
                                if (in.tablero[in.p1[0]][in.p1[1]-3]==1){
                                        return false;
                                }
                                else{
                                        in.tablero[in.p1[0]][in.p1[1]]=0;
                                        in.p1[1]=in.p1[1]-4;
                                        in.tablero[in.p1[0]][in.p1[1]]=1;
					return true;
                                }
                        }
                        else{
                                in.tablero[in.p1[0]][in.p1[1]]=0;
				in.p1[1]=in.p1[1]-2;
                                in.tablero[in.p1[0]][in.p1[1]]=1;
				return true;
			}
                }
                break;
        case false:
                if (in.tablero[in.p2[0]][in.p2[1]-1]==1){
                        return false;
                }
                else{
                        if (in.tablero[in.p2[0]][in.p2[1]-2]==1){
                                if (in.tablero[in.p2[0]][in.p2[1]-3]==1){
                                        return false;
                                }
                                else{
                                        in.tablero[in.p2[0]][in.p2[1]]=0;
                                        in.p2[1]=in.p2[1]-4;
                                        in.tablero[in.p2[0]][in.p2[1]]=1;
					return true;
                                }
                        }
                        else{
                                in.tablero[in.p2[0]][in.p2[1]]=0;
				in.p2[1]=in.p2[1]-2;
                                in.tablero[in.p2[0]][in.p2[1]]=1;
				return true;
			}
                }
                break;
 }
}
