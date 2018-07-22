#include <inc.h>

vec2 avancep(arr2 &cas, mat19 &lab){
 arr2 p;
 vec2 posibles;

 p[0]=cas[0]-2;
 p[1]=cas[1];
 if (lab[p[0]][p[1]]==0){ 
	if (lab[cas[0]-1][cas[1]]==0){
 		posibles.push_back(p);
		lab[p[0]][p[1]]=1;
	}
 }

 p[0]=cas[0]+2;
 if (lab[p[0]][p[1]]==0){ 
        if (lab[cas[0]+1][cas[1]]==0){
                posibles.push_back(p);
                lab[p[0]][p[1]]=1;
        }
 }

 p[0]=cas[0];
 p[1]=cas[1]-2;
 if (lab[p[0]][p[1]]==0){ 
        if (lab[cas[0]][cas[1]-1]==0){ 
                posibles.push_back(p);
                lab[p[0]][p[1]]=1;
        }
 }
 p[1]=cas[1]+2;
 if (lab[p[0]][p[1]]==0){ 
        if (lab[cas[0]][cas[1]+1]==0){ 
                posibles.push_back(p);
                lab[p[0]][p[1]]=1;
        }
 }
 return posibles;
}

bool wallp(nodo in, mat2 &wall){

 int j;
 cola2 c,d;
 bool c1=true;
 bool c2=true;

 int i;
 vec2 paso;
 c.push(in.p1);

 in.tablero[wall[0][0]][wall[0][1]]=1;
 in.tablero[wall[1][0]][wall[1][1]]=1;
 
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


bool wallPlace(mat2 &wall, nodo &nod){
 if (nod.tablero[wall[0][0]][wall[0][1]]==1 || nod.tablero[wall[1][0]][wall[1][1]]==1) {
	return false;
 }
 else {
	if (wall[0][0]==wall[1][0]){          
        	if (nod.tablero[wall[0][0]+1][wall[0][1]+1]==1 && nod.tablero[wall[1][0]-1][wall[1][1]-1]==1){
        		return false;
		}
		else{
			if (wallp(nod, wall)==true){
                		nod.tablero[wall[0][0]][wall[0][1]]=1;
                		nod.tablero[wall[1][0]][wall[1][1]]=1;
               			return true;
			}
			else {
               			return false;
       			}
		}
	}
	else{
		if (nod.tablero[wall[0][0]-1][wall[0][1]-1]==1 && nod.tablero[wall[1][0]+1][wall[1][1]+1]==1){
                       	return false;
		}
                else{
	                if (wallp(nod, wall)==true){
        	                nod.tablero[wall[0][0]][wall[0][1]]=1;
                                nod.tablero[wall[1][0]][wall[1][1]]=1;
                                return true;
                 	}
                        else {
                        	return false;
                        }
		}

	 }
 }
}
