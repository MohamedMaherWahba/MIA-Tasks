#include <stdio.h>

#define ARRAY_SIZE 5

void averageMeasurements(const double* measurement1, const double* measurement2, double* result) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = (measurement1[i] + measurement2[i]) / 2.0;
    }
}

void printArray(const char* label, const double* array) {
    printf("%s: ", label);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

int main() {
    double measurement1[ARRAY_SIZE] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
    double measurement2[ARRAY_SIZE] = {0.0,9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};
    double result[ARRAY_SIZE];

    averageMeasurements(measurement1, measurement2, result);

    printArray("Measurement 1", measurement1);
    printArray("Measurement 2", measurement2);
    printArray("Averaged Measurement", result);

    return 0;
}
