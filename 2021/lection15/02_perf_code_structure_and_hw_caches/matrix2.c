#include <stdlib.h>

#define N 1024

double a[N][N];
double b[N][N];
double c[N][N];

void init_matrix() {
    unsigned long long int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = random()/RAND_MAX;
            b[i][j] = random()/RAND_MAX;
            c[i][j] = 0;
        }
    }
}

void mult() {
    unsigned long long int i, j, k;
    
    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                c[i][j] = c[i][j] + a[i][k]*b[k][j];
            }
        }
    }
}

int main(int argc, char **argv) {

    init_matrix();
    mult();

    return 0;
}
