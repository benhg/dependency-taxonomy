#include <openacc.h>
#include <stdio.h>

int fib(int x) {
    int prevPrev = 0;
    int prev = 0;
    int curr = 1;

    # pragma acc kernels
    for (int i=0; i<x; i++) {
        prevPrev = prev;
        prev = curr;
        curr = prevPrev + prev;
    }
    return curr;
}

int main() {
    printf("Find 10th fib number\n");
    int num = fib(10);
    printf("%d\n", num);
    return 0;
}
