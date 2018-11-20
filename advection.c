#include<stdio.h>
#include<math.h>

using namespace std;

double * initial_x(double dx, int N);
double * initial_u(double * x, int N);
double * flux(double * u, int N);
double * lax(double * u, double t_max, double dt, double dx);

int main(int argc, char ** argv){
    double L = 4.0;
    int N = int(L/dx) + 1;
}

double * initial_x(double dx, int N){

    double * x = new double[N];
    x[0] = 0.0;
    for(int i=1, i<N;i++){
        x[i] = x[i-1] + dx;
    }
    return x;
}

double * intial_u(double * x, int N){
    double * u = new double[N];
    for i(int i=0;i<N,i++){
        if(x[i]<2.0){u[i]=1.0;}
        if(x[i]>2.0){u[i]=0.0;}
    }
    return u;
}
double * flux(double * u, int N){
    double * f = new double[N];
    for(int i=0;i<N;i++){
        f[i] = 0.5 * u[i]*u[i];
    }
    return f;
}
double * lax(double * u, double t_max, double dt, double dx){
    
}