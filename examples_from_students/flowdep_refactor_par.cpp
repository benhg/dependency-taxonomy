/* Kobe Davis
 * Prof. Karavanic
 * CS 405
 * 1 June 2019
 *
 * The purpose of this program is to demonstrate a refactoring
 * solution to a flow dependency problem. The sequential version
 * of this program (flowdep_refactor_seq.cpp) demonstrates how
 * a flow dependency results in a compile-time error from OpenACC.
*/

#include <cstdlib>
#include <ctime>
#include <omp.h>

const int DIM = 30; // Height and Width

int main() {
    srand(time(NULL));

    // Declare matrix of height and width, DIM
    int data[DIM][DIM];

    // Randomly initialize elements in range (0, 1)
    for(int i = 0; i < DIM; ++i)
        for(int j = 0; j < DIM; ++j)
            data[i][j] = rand() % 2;

    // In this version, we will iterate over the diagonals,
    // beginning at the top left diagonal and ending on the
    // bottom right diagonal
    int size = DIM-1;
    for(int l = 1; l < size*2; ++l) {
        int diagonal = (l <= size) ? l : size - (l % size);

        #pragma acc parallel loop
        for(int k = 0; k < diagonal; ++k) {
            int i = ((l <= size) ? diagonal : size) - k;
            int j = ((l <= size) ? 0 : (size - diagonal)) + (k+1);

            if(!data[i-1][j] == !data[i][j-1]) // XOR
                data[i][j] = data[i-1][j] && data[i][j-1];
        }
    }

    // Now we have refactored our code to use indices l and k, which
    // represent the diagonals across the matrix. Since the diagonal elements
    // are not dependent on each other, this executes with no complaints.

    return 0;
}
