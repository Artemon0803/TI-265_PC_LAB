#include <stdio.h>
#include <math.h>

void smooth_matrix(float *matrix, double *smoothed_matrix, int rows, int cols);
void print_matrix(double *matrix, int rows, int cols);
void calculate_absolute_sum_below_diagonal(double *matrix, int rows);

int main() {
    float matrix[10][10] = {
        {74.3f, 0.0f, 58.0f, 91.0f, 43.0f, 19.0f, 67.6f, 85.0f, 31.0f, 26.9f},
        {48.0f, 63.0f, 17.0f, 89.7f, 52.0f, 72.2f, 34.0f, 96.0f, 21.0f, 57.0f},
        {81.0f, 29.7f, 46.0f, 95.0f, 11.0f, 68.0f, 77.0f, 23.0f, 54.0f, 39.0f},
        {18.0f, 87.0f, 42.0f, 61.0f, 97.0f, 14.0f, 79.0f, 53.0f, 27.0f, 66.0f},
        {92.0f, 33.0f, 71.0f, 24.0f, 0.0f, 49.0f, 16.0f, 73.0f, 44.0f, 59.0f},
        {22.4f, 78.0f, 41.0f, 94.0f, 15.0f, 62.0f, 83.0f, 36.0f, 69.0f, 51.0f},
        {56.0f, 28.0f, 98.0f, 13.0f, 76.0f, 47.0f, 64.0f, 32.0f, 86.0f, 45.0f},
        {35.0f, 99.0f, 18.0f, 75.0f, 38.0f, 82.0f, 25.0f, 0.0f, 70.0f, 12.0f},
        {65.0f, 27.0f, 84.0f, 50.0f, 93.0f, 20.0f, 60.0f, 40.0f, 8.00f, 71.0f},
        {30.8f, 90.0f, 37.5f, 80.8f, 9.00f, 53.0f, 24.0f, 97.0f, 42.1f, 68.9f}
    };

    double smoothed_matrix[10][10];


    smooth_matrix(&matrix[0][0], &smoothed_matrix[0][0], 10, 10);
    print_matrix(&smoothed_matrix[0][0], 10, 10);
    calculate_absolute_sum_below_diagonal(&smoothed_matrix[0][0], 10);

    return 0;
}

void smooth_matrix(float *matrix, double *smoothed_matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            float sum = 0.0f;
            float count = 0.0f;

            // Iterate over the neighboring elements
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di;
                    int nj = j + dj;

                    // Check if the neighbor is within bounds and not equal to i and j
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && !(ni == i && nj == j)) {
                        sum += matrix[ni * cols + nj];
                        count++;
                    }
                }
            }

            // Calculate the average and assign it to the smoothed matrix
            smoothed_matrix[i * cols + j] = sum / count;
        }
    }
}

void print_matrix(double *matrix, int rows, int cols) {
    // Print the matrix
    printf("Smoothed Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("\t%.2lf ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

void calculate_absolute_sum_below_diagonal(double *smoothed_matrix, int rows) {
    //Absolute sum of elements below the main diagonal in the matrix
    double sum_below_diagonal = 0.0;
    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            sum_below_diagonal += fabs(smoothed_matrix[i * rows + j]);
        }
    }

    printf("\nAbsolute sum of elements below the main diagonal: %.2lf\n", sum_below_diagonal);
}