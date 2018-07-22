#include <inc.h>

int minimax(nodo, int, bool, int, int);

void print(nodo);   // Prints the board in terminal
void gPrint(nodo);  // Graphic board
void gPrintAux(nodo); // Graphic dummy board for aux mode

bool pawnUp(bool ficha, nodo&);
bool pawnLeft(bool ficha, nodo&);
bool pawnRight(bool ficha, nodo&);
bool pawnDown(bool ficha, nodo&);

void wall(mat2 &pos, int i, nodo);
bool wallPlace(mat2 &pos, nodo &a);



void loop() {
 int alfa;
 int beta;

 bool quit = false;      // flag main loop
 bool colocandowall;	 // flag wall placing loop
 SDL_Event e;            // event handler variables
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
 while(!quit){		// Main Game loop
	 while( SDL_PollEvent(&e)!=0 ){
		int alfa=-100; // MiniMax variables
 		int beta=100;

		if( e.type == SDL_QUIT ){
			quit = true;
		}
		else if( e.type == SDL_KEYDOWN ){
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
						if (a.tablero[pos[0][0]][pos[0][1]]==1) {
							aux.tablero[pos[0][0]][pos[0][1]]=1;
						}
						else{
							aux.tablero[pos[0][0]][pos[0][1]]=0;
						}
	                                        if (a.tablero[pos[1][0]][pos[1][1]]==1) {
                                                        aux.tablero[pos[1][0]][pos[1][1]]=1;
                                                }
                                                else{
                                                        aux.tablero[pos[1][0]][pos[1][1]]=0;
                                                }
						cout << "Wall: "<<"("<<wall[0][0]<<","<<wall[0][1]<<"):("<<wall[1][0]<<","<<wall[1][1]<<") \n";
						while (colocandowall){
							while (SDL_PollEvent(&t)){
								if (t.type == SDL_KEYDOWN){
      									switch (t.key.keysym.sym){
										case SDLK_ESCAPE:
											cout << "Wall cancelled. \n";

                  									colocandowall = false;
                  									gPrint(a);
											break;
                                                       	                        case SDLK_RETURN:
                                                                               	 	t0=chrono::high_resolution_clock::now();
											if (wallPlace(pos,a)){
                                                                                		cout << "Placed. \n";
												a.walles1--;
                                                                                		colocandowall = false;
												apaso=a;
												auxmod=a;
                                                                                                gPrint(a);

												if (mini1==true && a.p1[0]==3){ // Enemy in terminal position
													m=2;
													minimax(apaso, m, true, alfa, beta);
													m=1;
												}
												else{
                                                                                                minimax(apaso, m, true, alfa, beta);
                                                                                                	alfa=-100;
                                                                                                        beta=100;
                                                                                                        auxm=m;
                                                                                                        if (a.tablero[2][2]<=4){
                                                                                                        	cout << "Tweaking minimax from " << " to ";
                                                                                                                a=auxmod;
                                                                                                                m=1;
                                                                                                                minimax(auxmod, 1, true, alfa, beta);
                                                                                                                cout << a.tablero[2][2] << " \n";
                                                                                                        }
                                                                                                                m=auxm;
                                                                                                }

                                                						t1 = chrono::high_resolution_clock::now();
												T = chrono::duration_cast<chrono::nanoseconds>(t1-t0).count();
 												cout <<"T: "<<T<< "\n";
												print(a);
												gPrint(a);
											}
                                                                               		break;
										case SDLK_r:
											cout << "Rotate \n";
											wall(pos, 1, aux);
											break;
										case SDLK_UP:
											cout << "Wall up \n";
											wall(pos, 2, aux);
											break;
										case SDLK_DOWN:
											cout << "Pared down \n";
											wall(pos, 3, aux);
											break;
										case SDLK_LEFT:
											cout << "Pared left \n";
											wall(pos, 4, aux);
											break;
										case SDLK_RIGHT:
											cout << "Pared right \n";
											wall(pos, 5, aux);
											break;
                                                                                case SDLK_u:
                                                                                        cout << "SDL updated \n";
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
						cout << "Up \n";
			                        t0=chrono::high_resolution_clock::now();
						apaso=a;
						auxmod=a;
						gPrint(a);

						if (mini1==true && a.p1[0]==3){
							m=2;
							minimax(apaso, m, true, alfa, beta);
							m=1;
						}
						else{
							minimax(apaso,m,true, alfa, beta);
							alfa=-100;
							beta=100;
							auxm=m;
                                                       if (a.tablero[2][2]<=4){
								a=auxmod;
        	                                               	cout << "Tweaking Minimax from " << a.tablero[2][2] << " to ";
                	                                       	m=1;
								minimax(auxmod, 1, true, alfa, beta);
                        	                               	cout << a.tablero[2][2] << "\n";
                                			}
							m=auxm;
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
                                                cout << "Down \n";
                                                t0=chrono::high_resolution_clock::now();
                                                apaso=a;
						auxmod=a;
						gPrint(a);

						if (mini1==true && a.p1[0]==3){
							m=2;
							minimax(apaso, m, true, alfa, beta);
							m=1;
						}
						else{
							minimax(apaso,m,true, alfa, beta);
							alfa=-100;
							beta=100;
							auxm=m;
                                                	if (a.tablero[2][2]<=4){
								a=auxmod;
        	                                	        cout << "Tweaking minimax from " << a.tablero[2][2] << " to ";
                	                        	        m=1;
								minimax(auxmod, 1, true, alfa, beta);
                        	                	          	cout << a.tablero[2][2] << "\n";
                                			}
							m=auxm;
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
                                                cout << "Left \n";
						apaso=a;
						auxmod=a;
						gPrint(a);

						if (mini1==true && a.p1[0]==3){
							m=2;
							minimax(apaso, m, true, alfa, beta);
							m=1;
						}
						else{
							minimax(apaso,m,true, alfa, beta);
                                                	alfa=-100;
							beta=100;
							auxm=m;
                                               	       if (a.tablero[2][2]<=4){
								a=auxmod;
       	                                	               	cout << "Tweaking minimax from  " << a.tablero[2][2] << " to ";
               	                        	               	m=1;
								minimax(auxmod, 1, true, alfa, beta);
                       	                	               	cout << a.tablero[2][2] << "\n";
                               				}
							m=auxm;
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
	                                        cout << "Right \n";
                                                t0=chrono::high_resolution_clock::now();
						apaso=a;
						auxmod=a;
						gPrint(a);

						if (mini1==true && a.p1[0]==3){
							m=2;
							minimax(apaso, m, true, alfa, beta);
							m=1;
						}
						else{
							minimax(apaso,m,true, alfa, beta);
                                                	alfa=-100;
							beta=100;
							auxm=m;
                                                	if (a.tablero[2][2]<=4){
								a=auxmod;
        	                                	        cout << "Tweaking minimax from " << a.tablero[2][2] << " to ";
                	                        	        m=1;
								minimax(auxmod, 1, true, alfa, beta);
                        	                	        cout << a.tablero[2][2] << "\n";
                                			}
							m=auxm;
						}
						t1 = chrono::high_resolution_clock::now();
                                                T = chrono::duration_cast<chrono::nanoseconds>(t1-t0).count();
                                                cout <<"T: "<<T<< "\n";
				                print(a);
						gPrint(a);
					}
					break;

				case SDLK_F5:
                                	cout << "SDL updated \n";
                                        SDL_RenderPresent( gRenderer );
                                        break;
			}
        	if (a.p1[0]==1){
        		cout << "\n \n \n You won! \n \n \n";
        		quit=true;
			break;
		}
        	if (a.p2[0]==17){
        		cout << "\n \n \n You have been defeated. \n \n \n";
			quit=true;
		        break;
        	}
		}
	}
 }
}
