#include <inc.h>


vec2 avance(arr2 cas, arr2 &p2 ,mat19 &lab){
 arr2 p;
 vec2 posibles;

  // Arriba
 p[0]=cas[0]-2;
 p[1]=cas[1];



 if (lab[cas[0]-1][cas[1]]==0){ // ¿Sin pared?
         if (lab[p[0]][p[1]]<=1){  // ¿Casilla sin marcar?
 		//if (p==p2){    // ¿Ocupada?
			//cout << "Encontrada arriba";
 		//	if (lab[cas[0]][cas[1]]%2==0){		//  ¿Corresponde mover?
		//		if (lab[p[0]-2][p[1]]==0){	// ¿Casilla sin marcar?
		//			if (lab[p[0]-1][p[1]]==0){  // No hay pared salto
		//				p[0]=p[0]-2;
		//				posibles.push_back(p);
		//				lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
		//			}
		//		}
		//	}
		//	else {                    // Ocupada contra movimiento, se ocupa.
		//		posibles.push_back(p);
		//		lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
		//	}
		//}
		//else{
			posibles.push_back(p);
			lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
		//}
 }
}

// Abajo
 p[0]=cas[0]+2;
 if (lab[p[0]-1][p[1]]==0){ // ¿Sin pared?
	 if (lab[p[0]][p[1]]<=1){  // ¿Casilla sin marcar?
                //if (p==p2){    // ¿Ocupada?
		//	//cout <<"Encontrada abajo";
                 //       if (lab[cas[0]][cas[1]]%2==0){          //  ¿Corresponde mover? 
                   //             if (lab[p[0]+2][p[1]]==0){      // ¿Casilla sin marcar?
                   //                     if (lab[p[0]+1][p[1]]==0){  // No hay pared salto
                   //                             p[0]=p[0]+2;
                   //                             posibles.push_back(p);
                   //                             lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
		//			}
                 //               }
                  //      }
                   //     else {                    // Ocupada contra movimiento, se ocupa.
                    //            posibles.push_back(p);
                     //           lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
	             //   }
                //}
                //else{
                        posibles.push_back(p);
                        lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                //}
 	}
 }


  // Izquierda
 p[0]=cas[0];
 p[1]=cas[1]-2;
 if (lab[p[0]][p[1]+1]==0){ // ¿Sin pared?
	 if (lab[p[0]][p[1]]<=1){  // ¿Casilla sin marcar?
                //if (p==p2){    // ¿Ocupada?
		//	//cout << "Encontrada izda.";
                 //       if (lab[cas[0]][cas[1]]%2){          //  ¿Corresponde mover?
                  //              if (lab[p[0]][p[1]-2]==0 && mueve1){      // ¿Casilla sin marcar?
                  //                      if (lab[p[0]][p[1]-1]==0){  // No hay pared salto
                  //                              p[1]=p[1]-2;
                  //                              posibles.push_back(p);
                  //                              lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
	//		                }
          //                      }
          //              }
          //              else {                    // Ocupada contra movimiento, se ocupa.
          //                      posibles.push_back(p);
          //                      lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
 	//	        }
         //       }
          //      else{
                        posibles.push_back(p);
                        lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
         //       }
 	}
 }

//Derecha
  p[1]=cas[1]+2;
 if (lab[p[0]][p[1]-1]==0){ // ¿Sin pared?
	if (lab[p[0]][p[1]]<=1){  // ¿Casilla sin marcar?
		//if (p==p2){    // ¿Ocupada?
			//cout<<"Encontrada derecha";
			
        //                if (lab[cas[0]][cas[1]]%2==0){       //  ¿Corresponde mover? y corresponde salto?
         //                       if (lab[p[0]][p[1]+2]==0){      // ¿Casilla sin marcar?
          //                              if (lab[p[0]][p[1]+1]==0){  // No hay pared salto
           //                                     p[1]=p[1]+2;
            //                                    posibles.push_back(p);
             //                                   lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
              //                          }
               //                 }
                //        }
                 //       else {                    // Ocupada contra movimiento, se ocupa.
              //                  posibles.push_back(p);
               //                 lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                //        }
                //}
                //else{
                        posibles.push_back(p);
                        lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
               // }
 }


}
 return posibles;
}

int e1_min1(nodo in){

 int j,i;
 cola2 c;

 vec2 paso;

 c.push(in.p1);
 bool buscar=true;
 in.tablero[in.p1[0]][in.p1[1]]=2;

 while (buscar){
	paso=avance(c.front(), in.p2, in.tablero);
	for (j=1;j<=paso.size();j++){
		c.push(paso[j-1]);
        }
        if (c.front()[0]==1){
                in.d1=in.tablero[c.front()[0]][c.front()[1]]-2;
                buscar=false;
        }
	c.pop();
 }

 return in.d1;

}
