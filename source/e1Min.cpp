vec2 avance(arr2 cas, arr2 &p2 ,mat19 &lab){
 arr2 p;
 vec2 posibles;

 p[0]=cas[0]-2;
 p[1]=cas[1];



 if (lab[cas[0]-1][cas[1]]==0){
         if (lab[p[0]][p[1]]<=1){  
 		if (p==p2){ 
			if (lab[cas[0]][cas[1]]%2==0){		
				if (lab[p[0]-2][p[1]]==0){	
					if (lab[p[0]-1][p[1]]==0){  
						p[0]=p[0]-2;
						posibles.push_back(p);
						lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
					}
				}
			}
			else {   
				posibles.push_back(p);
				lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
			}
		}
		else{
			posibles.push_back(p);
			lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
		}
 }
}


 p[0]=cas[0]+2;
 if (lab[p[0]-1][p[1]]==0){ 
	 if (lab[p[0]][p[1]]<=1){ 
                if (p==p2){ 
			
                        if (lab[cas[0]][cas[1]]%2==0){     
                                if (lab[p[0]+2][p[1]]==0){     
                                        if (lab[p[0]+1][p[1]]==0){ 
                                                p[0]=p[0]+2;
                                                posibles.push_back(p);
                                                lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
					}
                                }
                        }
                        else { 
                                posibles.push_back(p);
                                lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
	                }
                }
                else{
                        posibles.push_back(p);
                        lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                }
 	}
 }

 p[0]=cas[0];
 p[1]=cas[1]-2;
 if (lab[p[0]][p[1]+1]==0){
	 if (lab[p[0]][p[1]]<=1){ 
                if (p==p2){
			if (lab[cas[0]][cas[1]]%2==0){
                                if (lab[p[0]][p[1]-2]==0){
                                        if (lab[p[0]][p[1]-1]==0){
                                                p[1]=p[1]-2;
                                                posibles.push_back(p);
                                                lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
			                }
                                }
                        }
                        else {
                                posibles.push_back(p);
                                lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
 		        }
                }
                else{
                        posibles.push_back(p);
                        lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;  
                }
 	}
 }


  p[1]=cas[1]+2;
 if (lab[p[0]][p[1]-1]==0){
	if (lab[p[0]][p[1]]<=1){
		if (p==p2){
                        if (lab[cas[0]][cas[1]]%2==0){
                                if (lab[p[0]][p[1]+2]==0){
                                        if (lab[p[0]][p[1]+1]==0){
                                                p[1]=p[1]+2;
                                                posibles.push_back(p);
                                                lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                                        }
                                }
                        }
                        else {
                                posibles.push_back(p);
                                lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                        }
                }
                else{
                        posibles.push_back(p);
                        lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                }
 }


}
 return posibles;
}



int e1Min1(nodo in){

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
vec2 avance2(arr2 &cas, arr2 &p1 ,mat19 &lab){
 arr2 p;
 vec2 posibles;

 p[0]=cas[0]+2;
 p[1]=cas[1];

 if (lab[p[0]-1][p[1]]==0){ 
	 if (lab[p[0]][p[1]]<=1){
                if (p==p1){
			
                        if (lab[cas[0]][cas[1]]%2==0){
                                if (lab[p[0]+2][p[1]]==0){
                                        if (lab[p[0]+1][p[1]]==0){
                                                p[0]=p[0]+2;
                                                posibles.push_back(p);
                                                lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                                        }
                                }
                        }
                        else {
                                posibles.push_back(p);
                                lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                        }
                }
                else{
                        posibles.push_back(p);
                        lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                }
 	}
 }

 p[0]=cas[0]-2;
 if (lab[cas[0]-1][cas[1]]==0){
         if (lab[p[0]][p[1]]<=1){ 
                if (p==p1){ 
                        if (lab[cas[0]][cas[1]]%2==0){
                                if (lab[p[0]-2][p[1]]==0){ 
                                        if (lab[p[0]-1][p[1]]==0){
                                                p[0]=p[0]-2;
                                                posibles.push_back(p);
                                                lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                                        }
                                }
                        }
                        else {                   
                                posibles.push_back(p);
                                lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                        }
                }
                else{
                        posibles.push_back(p);
                        lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                }
 }
}

 p[0]=cas[0];
 p[1]=cas[1]-2;
 if (lab[p[0]][p[1]+1]==0){
	 if (lab[p[0]][p[1]]<=1){
                if (p==p1){
                        if (lab[cas[0]][cas[1]]%2==0){ 
                                if (lab[p[0]][p[1]-2]==0){
                                        if (lab[p[0]][p[1]-1]==0){
                                                p[1]=p[1]-2;
                                                posibles.push_back(p);
                                                lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                                        }
                                }
                        }
                        else {
                                posibles.push_back(p);
                                lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                        }
                }
                else{
                        posibles.push_back(p);
                        lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                }
 	}
 }


 p[1]=cas[1]+2;
 if (lab[p[0]][p[1]-1]==0){ 
	if (lab[p[0]][p[1]]<=1){ 
		if (p==p1){
                        if (lab[cas[0]][cas[1]]%2==0){
                                if (lab[p[0]][p[1]+2]==0){
                                        if (lab[p[0]][p[1]+1]==0){
                                                p[1]=p[1]+2;
                                                posibles.push_back(p);
                                                lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                                        }
                                }
                        }
                        else { 
                                posibles.push_back(p);
                                lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                        }
                }
                else{
                        posibles.push_back(p);
                        lab[p[0]][p[1]]=lab[cas[0]][cas[1]]+1;
                }
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
        }
        if (c.front()[0]==17){
                in.d2=in.tablero[c.front()[0]][c.front()[1]]-2;
                buscar=false;
        }
        c.pop();
 }
 return in.d2;
}

