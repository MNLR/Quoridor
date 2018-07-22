#include <inc.h>


vec2 avance2(arr2 &cas, arr2 &p1 ,mat19 &lab){
 arr2 p;
 vec2 posibles;


// Abajo
 p[0]=cas[0]+2;
 p[1]=cas[1];

 if (lab[p[0]-1][p[1]]==0){ // ¿Sin wall?
	 if (lab[p[0]][p[1]]<=1){  // ¿Casilla sin marcar?
                //if (p==p1){    // ¿Ocupada?
		//	//cout <<"Encontrada pawnDown";
                 //       if (lab[cas[0]][cas[1]]%2==0){          //  ¿Corresponde mover? 
                 //               if (lab[p[0]+2][p[1]]==0){      // ¿Casilla sin marcar?
                 //                       if (lab[p[0]+1][p[1]]==0){  // No hay wall salto
                 //                               p[0]=p[0]+2;
                //                                posibles.push_back(p);
                 //                               lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                  //                      }
                   //             }
                    //    }
                   //     else {                    // Ocupada contra movimiento, se ocupa.
                    //            posibles.push_back(p);
                     //           lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                      //  }
                //}
                //else{
                        posibles.push_back(p);
                        lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                //}
 	}
 }

  // Arriba
 p[0]=cas[0]-2;

 if (lab[cas[0]-1][cas[1]]==0){ // ¿Sin wall?
         if (lab[p[0]][p[1]]<=1){  // ¿Casilla sin marcar?
                //if (p==p1){    // ¿Ocupada?
                        //cout << "Encontrada pawnUp";
                //        if (lab[cas[0]][cas[1]]%2==0){          //  ¿Corresponde mover?
                 //               if (lab[p[0]-2][p[1]]==0){      // ¿Casilla sin marcar?
                  //                      if (lab[p[0]-1][p[1]]==0){  // No hay wall salto
                   //                             p[0]=p[0]-2;
                    //                            posibles.push_back(p);
                     //                           lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                      //                  }
                       //         }
                        //}
                       // else {                    // Ocupada contra movimiento, se ocupa.
                        //        posibles.push_back(p);
                        //        lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                        //}
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
 if (lab[p[0]][p[1]+1]==0){ // ¿Sin wall?
	 if (lab[p[0]][p[1]]<=1){  // ¿Casilla sin marcar?
                //if (p==p1){    // ¿Ocupada?
		//	//cout << "Encontrada izda.";
                  //      if (lab[cas[0]][cas[1]]%2==0 ){          //  ¿Corresponde mover?
                   //             if (lab[p[0]][p[1]-2]==0){      // ¿Casilla sin marcar?
                    //                    if (lab[p[0]][p[1]-1]==0){  // No hay wall salto
                     //                           p[1]=p[1]-2;
                      //                          posibles.push_back(p);
                       //                         lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                        //                }
                         //       }
                        //}
                        //else {                    // Ocupada contra movimiento, se ocupa.
                         //       posibles.push_back(p);
                         //       lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                        //}
                //}
                //else{
                        posibles.push_back(p);
                        lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                //}
 	}
 }

//Derecha
  p[1]=cas[1]+2;
 if (lab[p[0]][p[1]-1]==0){ // ¿Sin wall?
	if (lab[p[0]][p[1]]<=1){  // ¿Casilla sin marcar?
		//if (p==p1){    // ¿Ocupada?
		//	//cout<<"Encontrada pawnRight";
                //        if (lab[cas[0]][cas[1]]%2==0){       //  ¿Corresponde mover? 
                 //               if (lab[p[0]][p[1]+2]==0){      // ¿Casilla sin marcar?
                  //                      if (lab[p[0]][p[1]+1]==0){  // No hay wall salto
                   //                             p[1]=p[1]+2;
                    //                            posibles.push_back(p);
                     //                           lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                      //                  }
                       //         }
                        //}
                        //else {                    // Ocupada contra movimiento, se ocupa.
                                posibles.push_back(p);
                                lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                        //}
                //}
                //else{
                        posibles.push_back(p);
                        lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                //}
 }
}

 return posibles;
}

int e1Min2(nodo in){

 int j,i;
 cola2 c;

 vec2 paso;

 c.push(in.p2);
 bool buscar=true;
 in.tablero[in.p2[0]][in.p2[1]]=2;

 while (buscar){
        paso=avance2(c.front(), in.p1, in.tablero);
        for (j=1;j<=paso.size();j++){
                c.push(paso[j-1]);
               //cout<<"("<<paso[j-1][0]<<","<<paso[j-1][1]<<")";
        }
      //for (i=0; i<=18; i++){
      //        for(j=0; j<=18; j++){
      //                cout << in.tablero[i][j] << " ";
      //        }
      //        cout << "\n";
      //}

        if (c.front()[0]==17){
                in.d2=in.tablero[c.front()[0]][c.front()[1]]-2;
                buscar=false;
        }
        c.pop();
 }
 return in.d2;
}



