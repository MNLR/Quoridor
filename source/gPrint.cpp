#include <inc.h>

void gPrint(nodo aa){
 
 //Clear screen
 SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
 SDL_RenderClear( gRenderer );
 int i,j;
 for (i=1; i<=17; i++){
	if (i%2==1){
		for (j=1; j<=17 ; j++){
			if (j%2==1){
				if (aa.p1[0]==i && aa.p1[1]==j){  
					SDL_Rect fillRect = {(50+SCREEN_WIDTH/11)+(SCREEN_WIDTH/11)*(j-1)/2+34, (SCREEN_HEIGHT/11)+(SCREEN_HEIGHT/11)*(i-1)/2+34, SCREEN_WIDTH/12, SCREEN_HEIGHT/12};
                                	SDL_SetRenderDrawColor( gRenderer, 0xff, 0xcc, 0x66, 0xFF );
                	        	SDL_RenderFillRect( gRenderer, &fillRect );
				}
				else{
	                       		if (aa.p2[0]==i && aa.p2[1]==j){
	                                	SDL_Rect fillRect = {(50+SCREEN_WIDTH/11)+(SCREEN_WIDTH/11)*(j-1)/2+34, (SCREEN_HEIGHT/11)+(SCREEN_HEIGHT/11)*(i-1)/2+34, SCREEN_WIDTH/12, SCREEN_HEIGHT/12};
                                		SDL_SetRenderDrawColor( gRenderer, 0x6E, 0x2C, 0x67, 0xFF );
                	               		SDL_RenderFillRect( gRenderer, &fillRect );
                        		}
					else{		
						SDL_Rect fillRect = {(50+SCREEN_WIDTH/11)+(SCREEN_WIDTH/11)*(j-1)/2+34, (SCREEN_HEIGHT/11)+(SCREEN_HEIGHT/11)*(i-1)/2+34, SCREEN_WIDTH/12, SCREEN_HEIGHT/12};
                                		SDL_SetRenderDrawColor( gRenderer, 0x8B, 0x45, 0x13, 0xFF);
                	               		SDL_RenderFillRect( gRenderer, &fillRect );
					}
				}
			}
			else{
				if (aa.tablero[i][j]==true){		
					SDL_Rect fillRect = {(50+SCREEN_WIDTH/11)+(SCREEN_WIDTH/11)*j/2+25, (SCREEN_HEIGHT/11)+(SCREEN_HEIGHT/11)*(i-1)/2+34, 17, SCREEN_HEIGHT/12};
                        		SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
                	        	SDL_RenderFillRect( gRenderer, &fillRect );
				}
				else{				
					SDL_Rect fillRect = {(50+SCREEN_WIDTH/11)+(SCREEN_WIDTH/11)*j/2+25, (SCREEN_HEIGHT/11)+(SCREEN_HEIGHT/11)*(i-1)/2+34, 17, SCREEN_HEIGHT/12};
                       		        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                                	SDL_RenderFillRect( gRenderer, &fillRect );
				}
			}
 		}
	}
	else{
		for (j=1; j<=17 ; j++){
			if(j%2==1){
                        	if (aa.tablero[i][j]==true){
		               		  SDL_Rect fillRect = {(50+SCREEN_WIDTH/11)+(SCREEN_WIDTH/11)*(j-1)/2+34, (SCREEN_HEIGHT/11)+(SCREEN_HEIGHT/11)*(i-1)/2+60, SCREEN_WIDTH/12 , 6};
                                          SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
                                          SDL_RenderFillRect( gRenderer, &fillRect );
				}

			}		
		}
 	}
 }

SDL_Rect fillRect = {30, 170, 40, 30};
SDL_SetRenderDrawColor( gRenderer, 0xff, 0xcc, 0x66, 0xFF );
SDL_RenderFillRect( gRenderer, &fillRect );

SDL_Rect fillRect2 = {90, 170, 40, 30};
SDL_SetRenderDrawColor( gRenderer, 0x6E, 0x2C, 0x67, 0xFF );
SDL_RenderFillRect( gRenderer, &fillRect2 );


 for (i=1; i<= aa.walles1; i++){
       SDL_Rect fillRect = {30,200+34*i, 40 , 4};
       SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
       SDL_RenderFillRect( gRenderer, &fillRect );

 }

 for (i=1; i<= aa.walles2; i++){
       SDL_Rect fillRect = {90,200+34*i, 40 , 4};
       SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
       SDL_RenderFillRect( gRenderer, &fillRect );

 }


                SDL_Rect outlineRect = {192, 95 , 973, 545};
                SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
                SDL_RenderDrawRect( gRenderer, &outlineRect );

                SDL_RenderPresent( gRenderer );

}
