#include <inc.h>

int e1Min1(nodo);
int e1Min2(nodo);
int minimax(nodo, int, bool, int, int);

void print(nodo);   // Imprime el tablero y datos, por terminal.
void gPrint(nodo);  // Tablero gráfico.
void gPrintAux(nodo);

bool pawnUp(bool ficha, nodo&);
bool pawnLeft(bool ficha, nodo&);
bool pawnRight(bool ficha, nodo&);
bool pawnDown(bool ficha, nodo&);

void wall(mat2 &pos, int i, nodo);
bool wallPlace(mat2 &pos, nodo &a);



void loop() {
 int alfa;
 int beta;

 bool quit = false;      // flag loop principal
 bool colocandowall;	 // flag loop wall
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
					if (a.walles1>0){
						cout << "p \n";
						colocandowall=true;
						pos[0][0]=8;
                                        	pos[0][1]=9;
						pos[1][0]=8;
						pos[1][1]=11;
						aux=a;
						aux.tablero[pos[0][0]][pos[0][1]]=2;
						aux.tablero[pos[1][0]][pos[1][1]]=2;
						gPrintAux(aux);
						if (a.tablero[pos[0][0]][pos[0][1]]==1) {   //Si ya había una wall se revierte a su colocación para printlo.
							aux.tablero[pos[0][0]][pos[0][1]]=1;
						}
						else{
							aux.tablero[pos[0][0]][pos[0][1]]=0;
						}
	                                        if (a.tablero[pos[1][0]][pos[1][1]]==1) {   //Si ya había una wall se revierte a su colocación para printlo.
                                                        aux.tablero[pos[1][0]][pos[1][1]]=1;
                                                }
                                                else{
                                                        aux.tablero[pos[1][0]][pos[1][1]]=0;
                                                }
						cout << "Pared: "<<"("<<wall[0][0]<<","<<wall[0][1]<<"):("<<wall[1][0]<<","<<wall[1][1]<<") \n"; 
						while (colocandowall){
							while (SDL_PollEvent(&t)){
								if (t.type == SDL_KEYDOWN){
      									switch (t.key.keysym.sym){
										case SDLK_ESCAPE:
											cout << "Colocación cancelada. \n";

                  									colocandowall = false;
                  									gPrint(a);
											break;
                                                       	                        case SDLK_RETURN:
                                                                               	 	t0=chrono::high_resolution_clock::now();
											if (wallPlace(pos,a)){
                                                                                		cout << "colocada. \n";
												a.walles1--;
                                                                                		colocandowall = false;
												apaso=a;
												auxmod=a;
                                                                                                gPrint(a);

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
												print(a);
												gPrint(a);
											}
                                                                               		break;
										case SDLK_r:
											cout << "rotar \n";
											wall(pos, 1, aux);
											break;
										case SDLK_UP:
											cout << "Pared pawnUp \n";
											wall(pos, 2, aux);
											break;
										case SDLK_DOWN:
											cout << "Pared pawnDown \n";
											wall(pos, 3, aux);
											break;
										case SDLK_LEFT:
											cout << "Pared pawnLeft \n";
											wall(pos, 4, aux);
											break;
										case SDLK_RIGHT:
											cout << "Pared pawnRight \n";
											wall(pos, 5, aux);
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
					if (pawnUp(true,a)){
						cout << "Arriba \n";
			                        t0=chrono::high_resolution_clock::now();
						apaso=a;
						auxmod=a;
						gPrint(a);

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
						print(a);
						gPrint(a);
					}
			       		break;
				case SDLK_DOWN:
                                        if (pawnDown(true,a)){
                                                cout << "Abajo \n";
                                                t0=chrono::high_resolution_clock::now();
                                                apaso=a;
						auxmod=a;
						gPrint(a);

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
						print(a);
						gPrint(a);
                                        }
					break;
				case SDLK_LEFT:
                                        if (pawnLeft(true,a)){
                                                t0=chrono::high_resolution_clock::now();
                                                cout << "Izquierda \n";
						apaso=a;
						auxmod=a;
						gPrint(a);

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
						print(a);
						gPrint(a);
                                                }
					break;
				case SDLK_RIGHT:
                                        if (pawnRight(true,a)){
	                                        cout << "Derecha \n";
                                                t0=chrono::high_resolution_clock::now();
						apaso=a;
						auxmod=a;
						gPrint(a);

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
				                print(a);
						gPrint(a);
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
