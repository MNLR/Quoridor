#include <inc.h>

vec2 avancep(arr2 &cas, mat19 &lab){
 arr2 p;
 vec2 posibles;

  // Arriba
 p[0]=cas[0]-2;
 p[1]=cas[1];
 if (lab[p[0]][p[1]]==0){  // ¿Casilla ya marcada?
	if (lab[cas[0]-1][cas[1]]==0){ // ¿Pared?
 		posibles.push_back(p);
		lab[p[0]][p[1]]=1;
	}
 }
  // Abajo
 p[0]=cas[0]+2;
 if (lab[p[0]][p[1]]==0){  // ¿Casilla ya marcada?
        if (lab[cas[0]+1][cas[1]]==0){ // ¿Pared?
                posibles.push_back(p);
                lab[p[0]][p[1]]=1;
        }
 }
  // Izquierda
 p[0]=cas[0];
 p[1]=cas[1]-2;
 if (lab[p[0]][p[1]]==0){  // ¿Casilla ya marcada?
        if (lab[cas[0]][cas[1]-1]==0){ // ¿Pared?
                posibles.push_back(p);
                lab[p[0]][p[1]]=1;
        }
 }
  // Derecha
 p[1]=cas[1]+2;
 if (lab[p[0]][p[1]]==0){  // ¿Casilla ya marcada?
        if (lab[cas[0]][cas[1]+1]==0){ // ¿Pared?
                posibles.push_back(p);
                lab[p[0]][p[1]]=1;
        }
 }
 return posibles;
}

bool paredp(nodo in, mat2 &pared){

 int j;
 cola2 c,d;
 bool c1=true;
 bool c2=true;

 int i;
 vec2 paso;
 c.push(in.p1);

 in.tablero[pared[0][0]][pared[0][1]]=1;
 in.tablero[pared[1][0]][pared[1][1]]=1;
 
 mat19 copia=in.tablero;
 in.tablero[in.p2[0]][in.p2[1]]=0;
 copia[in.p1[0]][in.p1[1]]=0;

 while (c1==true && c.size()!=0){

	paso=avancep(c.front(), in.tablero);
	for (j=1;j<=paso.size();j++){
		c.push(paso[j-1]);
	}

	if (c.front()[0]==1){
		c1=false;
	}
	c.pop();
 }
 
 if (c1){
        return false;
 }
 else {
        d.push(in.p2);
        while (c2==true && d.size()!=0){
                paso=avancep(d.front(), copia);
                for (j=1;j<=paso.size();j++){
                        d.push(paso[j-1]);
                }
                if (d.front()[0]==17){
                        c2=false;
                }
                d.pop();
        }
        if (c2==false){
                return true;
        }
        else{
                return false;
        }
 }
 
}


bool paredc(mat2 &pared, nodo &nod){
  //False indica no se puede colocar pared.
 if (nod.tablero[pared[0][0]][pared[0][1]]==1 || nod.tablero[pared[1][0]][pared[1][1]]==1) {
	return false;
 }
 else {
	if (pared[0][0]==pared[1][0]){           // Según la rotación se comprueban unas u otras casillas.
        	if (nod.tablero[pared[0][0]+1][pared[0][1]+1]==1 && nod.tablero[pared[1][0]-1][pared[1][1]-1]==1){  //Pared cruzada
        		return false;
		}
		else{				// COMPROBACIÖN CAMINO LIBRE
			if (paredp(nod, pared)==true){
                		nod.tablero[pared[0][0]][pared[0][1]]=1;
                		nod.tablero[pared[1][0]][pared[1][1]]=1;
               			return true;
			}
			else {
               			return false;
       			}
		}
	}
	else{
		if (nod.tablero[pared[0][0]-1][pared[0][1]-1]==1 && nod.tablero[pared[1][0]+1][pared[1][1]+1]==1){
                       	return false;
		}
                else{                             // Bloque idéntico   (Comprobación camino libre)
	                if (paredp(nod, pared)==true){
        	                nod.tablero[pared[0][0]][pared[0][1]]=1;
                                nod.tablero[pared[1][0]][pared[1][1]]=1;
                                return true;
                 	}
                        else {
                        	return false;
                        }
		}

	 }
 }
}
