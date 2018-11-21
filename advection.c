#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

double * initial_x(double dx, int N){

    double * x = new double[N];
    x[0] = 0.0;
    for(int i=1;i<N;i++){
        x[i] = x[i-1] + dx;
    }
    return x;
}

double * in_u(double * x, int N){
    double * u = new double[N];
    for (int i=0;i<N;i++){
        if(x[i]<2.0){u[i]=1.0;}
        else{u[i]=0.0;}
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
double * lax(double * u, double t_max, double dt, double dx, int N){
    
    int N_t = (int) t_max/dt;
    double * u_f = new double[N];
    for(int i=0;i<N;i++){u_f[i]=u[i];}
    for(int i=0;i<N_t;i++){
        double * F = flux (u, N);
        for (int j=1;j<N;j++){
            u_f[j] = 0.5 * ( u[j+1] + u[j-1]);
        }
        for (int j=1;j<N;j++){
            u_f[j] = u_f[j] - ( (0.5 * dt/dx) * ( F[j+1] - F[j-1]  )  );
        }
        for(int i=0;i<N;i++){u[i]=u_f[i];}
    }
    return u_f;    
}

int main(int argc, char ** argv){
    double L = 4.0;
    double dx = 0.05;
    int N = int(L/dx) + 1;
    FILE *out;
    char filename[128];
    
    double * tmax = new double[4];
    for(int i=0;i<3;i++){tmax[i]=0.5*i;}
    tmax[3]=2.0;
    for (int i=0;i<4;i++){
        double * x = initial_x(dx, N);
        double * u_in = in_u(x, N);
        double * u_final = lax(u_in,tmax[i], 0.5*dx, dx, N);
        sprintf(filename, "sample_%d.txt", i);
        out = fopen(filename, "w");
        for (int j=0;j<N;j++){
            fprintf(out, "%f , %f\n", x[j], u_final[j]);
        }
    }
    return 0;
}
