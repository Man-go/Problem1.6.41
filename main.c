#include <stdio.h>
#include <stdlib.h>

char mta_odmocnina2(unsigned int m, double x, double *res){
	double hyba = 0.00001;
	double aprox = x;
	double def;
	double koren = x/m;
	int i;

	def = (koren-aprox)<0 ? -(koren-aprox) : (koren-aprox);
	
	if((m%2==0) && (x<0)) 
		return 1;

	while(def >= hyba){
		aprox = x;
		for(i = 1; i < m; i++){
			aprox = aprox / koren;
		}
		koren = 0.5*(aprox + koren);
		def = (koren-aprox)<0 ? -(koren-aprox) : (koren-aprox);
	}
	
	*res = koren;
	return 0;		
	}			

int main(){
	int m = 7;
	double x = 152;
	double res;
	char odm;
	double *p_res;
	p_res = &res; 
	
	odm = mta_odmocnina2(m,x,p_res);
	
	printf("%f^-%d = %f", x,m,res);
	
	getchar();
	return 0;
}

