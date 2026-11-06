#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;

    printf("введите N: ");
    while(scanf("%d", &N) != 1 || N <= 0) {
        printf("введите положительное число: ");
        while(getchar() != '\n');
    }

    printf("введите M: ");
    while(scanf("%d", &M) != 1 || M < 4) {
        printf("введите число больше или равно 4: ");
        while(getchar() != '\n');
    }

    float **matrix = (float**)malloc(N * sizeof(float*));
    for(int i = 0; i < N; i++) {
        matrix[i] = (float*)malloc(M * sizeof(float));
    }

    printf("введите элементы матрицы:\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("элемент: ");
            while(scanf("%f", &matrix[i][j]) != 1) {
                printf("введите число: ");
                while(getchar() != '\n');
            }
        }
    }

    float l = matrix[0][0];
    int max_i = 0, max_j = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            if(matrix[i][j] > l) {
                l = matrix[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    float S = 0;
    if(N >= 4 && M >= 4) {
        float a43 = matrix[3][2];
        if(a43 != 0) {
            for(int i = 0; i < N; i++) {
                float a_i2 = matrix[i][1];
                S += (a_i2 + a_i2 * a_i2) / a43;
            }

            matrix[max_i][max_j] = S;
        } else {
            printf("деление на ноль\n");
        }
    }

    printf("итоговая матрица:\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);

	printf("сумма S = %f\n", S);

    return 0;
}
