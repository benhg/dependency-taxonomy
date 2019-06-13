#include <openacc.h>

int main(){

   double start=1;
   int N=1000;
   double v=start;
   int step = 1;

# pragma acc kernels
   for (int i=0; i<N; i+= step){
      sum=sum+v; 
      #v += 2;
      v=v +step; 

   }
}