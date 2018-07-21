#include <inc.h>

int e1_min1(nodo);
int e1_min2(nodo);
int minimax(nodo, int, bool, int, int);

void imprimir(nodo);   // Imprime el tablero y datos, por terminal.
void gimprimir(nodo);  // Tablero gráfico.
void gimprimiraux(nodo);

bool arriba(bool ficha, nodo&);
bool izquierda(bool ficha, nodo&);
bool derecha(bool ficha, nodo&);
bool abajo(bool ficha, nodo&);

void pared(mat2 &pos, int i, nodo);
bool paredc(mat2 &pos, nodo &a);



void ciclo() {
 int alfa;
 int beta;

 bool quit = false;      // flag ciclo principal
 bool colocandopared;	 // flag ciclo pared
 SDL_Event e;            // variables manejo de eventos
 SDL_Event t;

 chrono::high_resolution_clock::time_point t0,t1;
 double T;
 int i;
 bool posible;
 mat2 pos;
 nodo apaso;
 nodo aux;
 nodo auxmod;
 nodo auxmod2;
 int auxm;
 while(!quit){		// Ciclo principal
	 while( SDL_PollEvent(&e)!=0 ){  
		// Manejar eventos en la cola
		int alfa=-100;
 		int beta=100;

		if( e.type == SDL_QUIT ){  		// El usuario pide salida
			quit = true;
		}
		else if( e.type == SDL_KEYDOWN ){	//Presionar tecla
			switch( e.key.keysym.sym ){
				case SDLK_p:
					if (a.paredes1>0){
						cout << "p \n";
						colocandopared=true;
						pos[0][0]=8;
                                        	pos[0][1]=9;
						pos[1][0]=8;
						pos[1][1]=11;
						aux=a;
						aux.tablero[pos[0][0]][pos[0][1]]=2;
						aux.tablero[pos[1][0]][pos[1][1]]=2;
						gimprimiraux(aux);
						if (a.tablero[pos[0][0]][pos[0][1]]==1) {   //Si ya había una pared se revierte a su colocación para imprimirlo.
							aux.tablero[pos[0][0]][pos[0][1]]=1;
						}
						else{
							aux.tablero[pos[0][0]][pos[0][1]]=0;
						}
	                                        if (a.tablero[pos[1][0]][pos[1][1]]==1) {   //Si ya había una pared se revierte a su colocación para imprimirlo.
                                                        aux.tablero[pos[1][0]][pos[1][1]]=1;
                                                }
                                                else{
                                                        aux.tablero[pos[1][0]][pos[1][1]]=0;
                                                }
						cout << "Pared: "<<"("<<pared[0][0]<<","<<pared[0][1]<<"):("<<pared[1][0]<<","<<pared[1][1]<<") \n"; 
						while (colocandopared){
							while (SDL_PollEvent(&t)){
								if (t.type == SDL_KEYDOWN){
      									switch (t.key.keysym.sym){
										case SDLK_ESCAPE:
											cout << "Colocación cancelada. \n";

                  									colocandopared = false;
                  									gimprimir(a);
											break;
                                                       	                        case SDLK_RETURN:
                                                                               	 	t0=chrono::high_resolution_clock::now();
											if (paredc(pos,a)){
                                                                                		cout << "colocada. \n";
												a.paredes1--;
                                                                                		colocandopared = false;
												apaso=a;
												auxmod=a;
                                                                                                gimprimir(a);

												if (mini1==true && a.p1[0]==3){  // Enemigo en posición casi terminal
													m=2;
													minimax(apaso, m, true, alfa, beta);
													m=1;
												}
												else{
                                                                                                minimax(apaso, m, true, alfa, beta);
                                                                                                        if (modificado){
                                                                                                                alfa=-100;
                                                                                                                beta=100;
                                                                                                                auxm=m;
                                                                                                                if (a.tablero[2][2]<=4){
                                                                                                                        cout << "Modificando minimax. Cambiado de " << "a ";
                                                                                                                        a=auxmod;
                                                                                                                        m=1;
                                                                                                                        minimax(auxmod, 1, true, alfa, beta);
                                                                                                                        cout << a.tablero[2][2] << " \n";
                                                                                                                }
                                                                                                                m=auxm;
                                                                                                        }
                                                                                                }

                                                						t1 = chrono::high_resolution_clock::now();
												T = chrono::duration_cast<chrono::nanoseconds>(t1-t0).count();
 												cout <<"T: "<<T<< "\n";
												imprimir(a);
												gimprimir(a);
											}
                                                                               		break;
										case SDLK_r:
											cout << "rotar \n";
											pared(pos, 1, aux);
											break;
										case SDLK_UP:
											cout << "Pared arriba \n";
											pared(pos, 2, aux);
											break;
										case SDLK_DOWN:
											cout << "Pared abajo \n";
											pared(pos, 3, aux);
											break;
										case SDLK_LEFT:
											cout << "Pared izquierda \n";
											pared(pos, 4, aux);
											break;
										case SDLK_RIGHT:
											cout << "Pared derecha \n";
											pared(pos, 5, aux);
											break;
                                                                                case SDLK_a:
                                                                                        cout << "Actualización SDL \n";
                                                                                        SDL_RenderPresent( gRenderer );
                                                                                        break;
									}
								}
							}
						}
					}
					break;
				case SDLK_UP:
					if (arriba(true,a)){
						cout << "Arriba \n";
			                        t0=chrono::high_resolution_clock::now();
						apaso=a;
						auxmod=a;
						gimprimir(a);

						if (mini1==true && a.p1[0]==3){  // Enemigo en posición casi terminal
							m=2;
							minimax(apaso, m, true, alfa, beta);
							m=1;
						}
						else{
							minimax(apaso,m,true, alfa, beta);
                                                	if (modificado){
								alfa=-100;
								beta=100;
								auxm=m;
                                                	       if (a.tablero[2][2]<=4){
									a=auxmod;
        	                                	               	cout << "Modificando minimax. Cambiado de " << a.tablero[2][2] << "a ";
                	                        	               	m=1;
									minimax(auxmod, 1, true, alfa, beta);
                        	                	               	cout << a.tablero[2][2] << "\n";
                                				}
								m=auxm;
				                	}
						}
						t1 = chrono::high_resolution_clock::now();
                                                T = chrono::duration_cast<chrono::nanoseconds>(t1-t0).count();
                                                cout <<"T: "<<T<< "\n";
						imprimir(a);
						gimprimir(a);
					}
			       		break;
				case SDLK_DOWN:
                                        if (abajo(true,a)){
                                                cout << "Abajo \n";
                                                t0=chrono::high_resolution_clock::now();
                                                apaso=a;
						auxmod=a;
						gimprimir(a);

						if (mini1==true && a.p1[0]==3){  // Enemigo en posición casi terminal
							m=2;
							minimax(apaso, m, true, alfa, beta);
							m=1;
						}
						else{
							minimax(apaso,m,true, alfa, beta);
                                                	if (modificado){
								alfa=-100;
								beta=100;
								auxm=m;
                                                	       if (a.tablero[2][2]<=4){
									a=auxmod;
        	                                	               	cout << "Modificando minimax. Cambiado de " << a.tablero[2][2] << "a ";
                	                        	               	m=1;
									minimax(auxmod, 1, true, alfa, beta);
                        	                	               	cout << a.tablero[2][2] << "\n";
                                				}
								m=auxm;
				                	}
						}
						t1 = chrono::high_resolution_clock::now();
                                                T = chrono::duration_cast<chrono::nanoseconds>(t1-t0).count();
                                                cout <<"T: " <<T<< "\n";
						imprimir(a);
						gimprimir(a);
                                        }
					break;
				case SDLK_LEFT:
                                        if (izquierda(true,a)){
                                                t0=chrono::high_resolution_clock::now();
                                                cout << "Izquierda \n";
						apaso=a;
						auxmod=a;
						gimprimir(a);

						if (mini1==true && a.p1[0]==3){  // Enemigo en posición casi terminal
							m=2;
							minimax(apaso, m, true, alfa, beta);
							m=1;
						}
						else{
							minimax(apaso,m,true, alfa, beta);
                                                	if (modificado){
								alfa=-100;
								beta=100;
								auxm=m;
                                                	       if (a.tablero[2][2]<=4){
									a=auxmod;
        	                                	               	cout << "Modificando minimax. Cambiado de " << a.tablero[2][2] << "a ";
                	                        	               	m=1;
									minimax(auxmod, 1, true, alfa, beta);
                        	                	               	cout << a.tablero[2][2] << "\n";
                                				}
								m=auxm;
				                	}
						}
						t1 = chrono::high_resolution_clock::now();
                                                T = chrono::duration_cast<chrono::nanoseconds>(t1-t0).count();
                                                cout <<"T: "<<T<< "\n";
						imprimir(a);
						gimprimir(a);
                                                }
					break;
				case SDLK_RIGHT:
                                        if (derecha(true,a)){
	                                        cout << "Derecha \n";
                                                t0=chrono::high_resolution_clock::now();
						apaso=a;
						auxmod=a;
						gimprimir(a);

						if (mini1==true && a.p1[0]==3){  // Enemigo en posición casi terminal
							m=2;
							minimax(apaso, m, true, alfa, beta);
							m=1;
						}
						else{
							minimax(apaso,m,true, alfa, beta);
                                                	if (modificado){
								alfa=-100;
								beta=100;
								auxm=m;
                                                	       if (a.tablero[2][2]<=4){
									a=auxmod;
        	                                	               	cout << "Modificando minimax. Cambiado de " << a.tablero[2][2] << "a ";
                	                        	               	m=1;
									minimax(auxmod, 1, true, alfa, beta);
                        	                	               	cout << a.tablero[2][2] << "\n";
                                				}
								m=auxm;
				                	}
						}
						t1 = chrono::high_resolution_clock::now();
                                                T = chrono::duration_cast<chrono::nanoseconds>(t1-t0).count();
                                                cout <<"T: "<<T<< "\n";
				                imprimir(a);
						gimprimir(a);
					}
					break;

				case SDLK_a:
                                	cout << "Actualización SDL \n";
                                        SDL_RenderPresent( gRenderer );
                                        break;

			}
		
        	if (a.p1[0]==1){
        		cout << "Victoria \n";
        		quit=true;
			break;
		}
        	if (a.p2[0]==17){
        		cout << "Derrota \n";
			quit=true;
		        break;
        	}
		}
	}
 }
}
