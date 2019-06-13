#include <openacc.h>

int main(){
    int N = 20;
    int * b = (int*) malloc(sizeof(int) * N);
    b[1] = 5;
    int * a = (int*) malloc(sizeof(int) * N);
    
    for(int i = 0; i < N; ++i) {
          
    }
}