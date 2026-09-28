#include <stdio.h>
#include <math.h>

int main() {
    float matrix[10][10] = {
        {74.0f, 12.0f, 58.0f, 91.0f, 43.0f, 19.0f, 67.0f, 85.0f, 31.0f, 26.0f},
        {48.0f, 63.0f, 17.0f, 89.0f, 52.0f, 72.0f, 34.0f, 96.0f, 21.0f, 57.0f},
        {81.0f, 29.0f, 46.0f, 95.0f, 11.0f, 68.0f, 77.0f, 23.0f, 54.0f, 39.0f},
        {18.0f, 87.0f, 42.0f, 61.0f, 97.0f, 14.0f, 79.0f, 53.0f, 27.0f, 66.0f},
        {92.0f, 33.0f, 71.0f, 24.0f, 88.0f, 49.0f, 16.0f, 73.0f, 44.0f, 59.0f},
        {22.0f, 78.0f, 41.0f, 94.0f, 15.0f, 62.0f, 83.0f, 36.0f, 69.0f, 51.0f},
        {56.0f, 28.0f, 98.0f, 13.0f, 76.0f, 47.0f, 64.0f, 32.0f, 86.0f, 45.0f},
        {35.0f, 99.0f, 18.0f, 75.0f, 38.0f, 82.0f, 25.0f, 55.0f, 70.0f, 12.0f},
        {65.0f, 27.0f, 84.0f, 50.0f, 93.0f, 20.0f, 60.0f, 40.0f, 8.0f, 71.0f},
        {30.0f, 90.0f, 37.0f, 80.0f, 9.0f, 53.0f, 24.0f, 97.0f, 42.0f, 68.0f}
    };

    double smoothed_matrix[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            float sum = 0.0f;
            float count = 0.0f;

            // Iterate over the neighboring elements
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di;
                    int nj = j + dj;

                    // Check if the neighbor is within bounds and not equal to i or/and j
                    if (ni >= 0 && ni < 10 && nj >= 0 && nj < 10 && !(ni == i && nj == j)) {
                        sum += matrix[ni][nj];
                        count++;
                    }
                }
            }

            // Calculate the average and assign it to the smoothed matrix
            smoothed_matrix[i][j] = sum / count;
        }
    }

    // Print the smoothed matrix
    printf("Smoothed Matrix:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("\t%.2lf ", smoothed_matrix[i][j]);
        }
        printf("\n");
    }

    //Absolute sum of elements below the main diagonal in the smoothed matrix
    float sum_below_diagonal = 0.0;
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < i; j++) {
            sum_below_diagonal += fabsf(smoothed_matrix[i][j]);
        }
    }

    printf("\nAbsolute sum of elements below the main diagonal: %.2f\n", sum_below_diagonal);

    return 0;
}
