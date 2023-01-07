#include <stdio.h>

int main() {

    int N=1;
    int A;

    while (N <= 12) {
        A = 15 + ((N - 1) * 14);
            if (N >= 4 && N <=6) {
                A = A + 7;
            }

            if (N >= 7 && N <= 9) {
                A = A + 14;
            }
            
            if (N >= 10 && N <= 12) {
                A = A + 21;
            }

            if (N > 12) {
                A = 191;
            }
        printf("%d = %d\n", N, A);
        N++;
    }
    
    return 0;
}