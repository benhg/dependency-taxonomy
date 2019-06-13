#include <openacc.h>

int main(){
    int N = 20;
    int * I = (int*) malloc(sizeof(int) * N);
    int ** a = (int**) malloc(sizeof(int*) * N);
    for(int i = 0; i < N; ++i)
        a[i] = (int*) malloc(sizeof(int) * N);
    
    a[0][0] = 0;
    
    #pragma acc kernels
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
           a[i][j] = (i != 0) ? ((j != 0) ? a[i-1][j-1] : a[i-1][j]) : a[i][j-1]; 
           if(i == j) I[i] = j;
        }
    }
}