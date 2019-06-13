// Dependencies with loop rearranging

#include <time.h>

#define SIZE 5000000

int A[SIZE];
int B[SIZE];
int C[SIZE];


void loopRearrange1() {
  for (int i = 1; i < SIZE; ++i) {
    A[i] =  A[i] + B[i-1];
    B[i] = B[i] + C[i];
  }
}

void loopRearrange1_opt() {
  //How can we make this parallel?
  for (int i = 1; i < SIZE; ++i) {
    A[i] =  A[i] + B[i-1];
    B[i] = B[i] + C[i];
  }
}

void loopRearrange2() {
  for (int i = 0; i < SIZE-1; ++i) {
    A[i] = A[i] + B[i+1];
    B[i] = B[i] + C[i];
  }
}

void loopRearrange2_opt() {
  //How can me make this parallel?
  for (int i = 0; i < SIZE-1; ++i) {
    A[i] = A[i] + B[i+1];
    B[i] = B[i] + C[i];
  }
}


//Initialize arrays, execute the function, and print the elapsed time
void run(void (*theFunction)()) {
  for (int i = 0; i < SIZE; ++i)
    A[i] = B[i] = C[i] = i;

  clock_t end, start = clock();
  theFunction();
  end = clock();
  
  printf("Time = %lf seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);
}


int main() {

  printf("\n--loopRearrange1--\n");
  run(loopRearrange1);
  
  printf("\n--loopRearrange1_opt--\n");
  run(loopRearrange1_opt);


  printf("\n--loopRearrange2--\n");
  run(loopRearrange2);

  printf("\n--loopRearrange2_opt--\n");
  run(loopRearrange2_opt);
  
  return 0;
}
