/*
ID: henriqu13
PROG: transform
LANG: C++
*/
#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef vector<int> vi;
#define FOR(i, a, b) for(unsigned int i = a; i < b; i++)

#define MaxN 11
char original[11][11];
char transf[11][11];
char matrix[11][11];
char temp[11][11];

unsigned int N;

void resetMatrix() {
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            matrix[i][j] = original[i][j];
        }
    }
}

bool matrixEqualsTransf() {
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            if (matrix[i][j] != transf[i][j])
                return false;
        }
    }
    return true;
}

void rotateMatrixClockwiseBy90Degrees() {
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            temp[i][j] = matrix[i][j];
        }
    }
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            matrix[j][N-1-i] = temp[i][j];
        }
    }
}

void mirrorMatrixHorizontally() {
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            temp[i][j] = matrix[i][j];
        }
    }
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            matrix[i][N-1-j] = temp[i][j];
        }
    }
}

int main() {
    ///////////////////
    // READING INPUT //
    ///////////////////
    FILE *fin, *fout;
    fin = fopen("transform.in", "r");
    fscanf(fin, "%u", &N);

    char line[MaxN];
    FOR(i, 0, N) {
        fscanf(fin, "%s", line);
        FOR(j, 0, N) {
            original[i][j] = line[j];
        }
    }
    resetMatrix();
    FOR(i, 0, N) {
        fscanf(fin, "%s", line);
        FOR(j, 0, N) {
            transf[i][j] = line[j];
        }
    }

    ///////////////////////
    // INITIALIZING DATA //
    ///////////////////////
    unsigned int transformationID = 7;

    /////////////////////
    // PROCESSING DATA //
    /////////////////////
    bool done = false;
    while(1) {
        FOR(i, 1, 4) {
            rotateMatrixClockwiseBy90Degrees();
            if (matrixEqualsTransf()) {
                transformationID = i;
                done = true;
                break;
            }
        }
        if (done)
            break;

        resetMatrix();
        mirrorMatrixHorizontally();
        if (matrixEqualsTransf()) {
            transformationID = 4;
            break;
        }

        FOR(i, 1, 4) {
            rotateMatrixClockwiseBy90Degrees();
            if (matrixEqualsTransf()) {
                transformationID = 5;
                done = true;
                break;
            }
        }
        if (done)
            break;

        if (matrixEqualsTransf()) {
            transformationID = 6;
            break;
        }

        break;
    }

    /////////////////////
    // OUTPUTTING DATA //
    /////////////////////
    fout = fopen("transform.out", "w");
    fprintf(fout, "%u\n", transformationID);

    return 0;
}
