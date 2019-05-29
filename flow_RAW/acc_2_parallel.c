#include <openacc.h>

int main(){
    
    int start = 1;
    int N = 100;
    double v[100];
    
    #pragma acc kernels
    for (int i=0; i<N; i+= 1){
        v[i] = i + 1 + 2; 

    }
}