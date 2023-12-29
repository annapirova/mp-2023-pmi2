#include <stdio.h>


void print_matrix1(int matrix[100][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void print_matrix2(int tempmatrix[100][100], int m, int mg) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < mg+1; j++) {
            printf("%d ", tempmatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void deletestolbik(int matrix[100][100], int* m, int* n,int* mg,int tempmatrix[100][100]) {
 
   
    
  
    for (int j = 0; j < *n; j++) {
        int gh = 1; 
        for (int i = 0; i < *m; i++) {
            if (matrix[i][j] <= 0) {
                gh = 0;
                break;
            }
        }

      
        if (gh==0) {
            (*mg)++;
            for (int i = 0; i < *m; i++) {
                tempmatrix[i][*mg] = matrix[i][j];
            }
            
        }
    }

   
}

int main() {
    int m, n;
    int mg = -1;
    int matrix[100][100];
    int tempmatrix[100][100];

    printf("kol-vo strok m : ");
    scanf_s("%d", &m);

    printf("kol-vo stolbcov n : ");
    scanf_s("%d", &n);

    printf("vvedite el-ti matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%d", &matrix[i][j]);
        }
    }

    printf("your matrix:\n");
    print_matrix1(matrix, m, n);

    deletestolbik(matrix, &m, &n, &mg, tempmatrix);

    printf("matrix posle ydal stolbcov:\n");
    print_matrix2(tempmatrix, m, mg);

    return 0;
}