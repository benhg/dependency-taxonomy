/* Kobe Davis
 * Prof. Karavanic
 * CS 405
 * 1 June 2019
 *
 * This is an example of a matrix operation which
 * contains a flow dependency. Despite the flow dependency,
 * the code may be refactored to execute in parallel.
 * The parallel version of this program, found in the file
 * (flowdep_refactor_par.cpp) demonstrates a solution through
 * refactoring.
*/

#include <cstdlib>
#include <ctime>

const int DIM = 30; // Height and Width

int main() {
    srand(time(NULL));

    // Declare matrix of height and width, DIM
    int data[DIM][DIM];

    // Randomly initialize elements in range (0, 1)
    for(int i = 0; i < DIM; ++i)
        for(int j = 0; j < DIM; ++j)
            data[i][j] = rand() % 2;

    // If the elements directly above and directly to
    // the left are equal, set the current element to match them
    // Otherwise do nothing
    #pragma acc parallel loop
    for(int i = 1; i < DIM; ++i)
        for(int j = 1; j < DIM; ++j)
            if(!data[i-1][j] == !data[i][j-1]) // XOR
                data[i][j] = data[i-1][j] && data[i][j-1];

    // There is a flow depency in the above code because our calculation of
    // data[i][j] relies on both the previous row and previous column. A partial
    // parallelization will not work because a dependency in both the previous
    // row and column stops us from simply parallelizing a single loop.

    return 0;
}
