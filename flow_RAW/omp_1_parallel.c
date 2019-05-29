#include <omp.h>

int main(){
    
    int start = 1;
    int N = 100;
    double v=start;
    int step = 1;
    
    #pragma omp parallel for reduction(+:v)
    for (int i=0; i<N; i+= step){
        v += 2;
        v = v +step; 

    }
}