#include<iostream>
#include<cmath>

//Integrantes:
//Guillén José
//Flores Emanuel
//Dominguez Kevin
//Peralta Arlette
 
using namespace std; 

double F(double x)
{
    return -25182*x-90*pow(x,2)+44*pow(x,3)-8*pow(x,4)+0.7*pow(x,5);
 
}

int comprobacion(int x1, int x2){
	float comp1;
	float comp2;

	comp1= -25182*x1-90*pow(x1,2)+44*pow(x1,3)-8*pow(x1,4)+0.7*pow(x1,5);
	comp2= -25182*x2-90*pow(x2,2)+44*pow(x2,3)-8*pow(x2,4)+0.7*pow(x2,5);

	 if((comp1>0 &&comp2<0)||((comp2>0 &&comp1<0))){
	 	return 1;
	 }
	 else{
	 	return 0;
	 }
} 

double biseccion(double xl,double xu,int iteraciones,double critconver,double EX){
    int i=1;
    double xr;
    double fxr;
	while(i<iteraciones)
	{
        xr=(xl+xu)/2;
        fxr=F(xr);
        if(abs(xu-xl)<critconver)
            return xr;
        if(abs(fxr)<EX)
            return xr;
        if(F(xl)*fxr<0)
            xu=xr;
        if(fxr*F(xu)<0)
            xl=xr;
        i=i+1;
    }
    return xr;
} 

int main (int argc, char *argv[]) {
   
	cout<<biseccion(15,17,100,0,0);//los dos primeros parametros corresponden a xl y xu
    return 0; 
}
