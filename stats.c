#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>

// Global variables to store average, minimum, and maximum values
// Initialize the average to 0
double average_value = 0;
// Initialize the maximum value to INT_MAX, so the min value in the list will be smaller than the current min
int minimum_value = INT_MAX;
// Initialize the minimum value to INT_MIN, so the max value in the list will be larger than the current max
int maximum_value = INT_MIN;

// thread function to calculate the average
void *calculate_average(void *arg) {
    // store the input in numbers
    int *numbers = (int *)arg;
    // Initialize sum to 0
    int sum = 0;
    // Count is the number of elements in the input
    int count = numbers[0];
    // Calculates the sum of all the numbers in the list
    for (int i = 1; i <= count; ++i) {
        sum += numbers[i];
    }
    // Calculates average and terminates the thread
    average_value = (double)sum / count;
    pthread_exit(NULL);
}

// Worker function to find minimum value
void *find_minimum(void *arg) {
    // store the input in numbers
    int *numbers = (int *)arg;
    // Count is the number of elements in the input
    int count = numbers[0];
    // traverses through the list and stores the minimum value in minimum_value
    for (int i = 1; i <= count; ++i) {
        if (numbers[i] < minimum_value) {
            minimum_value = numbers[i];
        }
    }
    // Terminates the thread
    pthread_exit(NULL);
}

// Worker function to find maximum value
void *find_maximum(void *arg) {
    // store the input in numbers
    int *numbers = (int *)arg;
    // Count is the number of elements in the input
    int count = numbers[0];
    // traverses through the list and stores the maximum value in minimum_value
    for (int i = 1; i <= count; ++i) {
        if (numbers[i] > maximum_value) {
            maximum_value = numbers[i];
        }
    }
    // Terminates the thread
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Invalid input, please enter numbers:\n");
        return 1;
    }

    // Get numbers from command line arguments
    int *numbers = (int *)malloc((argc) * sizeof(int));
    numbers[0] = argc - 1;
    for (int i = 1; i <= (argc - 1); ++i) {
        numbers[i] = atoi(argv[i]);
    }

    // Create worker threads for all three functions
    pthread_t average_thread, minimum_thread, maximum_thread;
    pthread_create(&average_thread, NULL, calculate_average, (void *)numbers);
    pthread_create(&minimum_thread, NULL, find_minimum, (void *)numbers);
    pthread_create(&maximum_thread, NULL, find_maximum, (void *)numbers);

    // Wait for all threads to complete
    pthread_join(average_thread, NULL);
    pthread_join(minimum_thread, NULL);
    pthread_join(maximum_thread, NULL);

    // Output the results
    printf("The average value is %.2f\n", average_value);
    printf("The minimum value is %d\n", minimum_value);
    printf("The maximum value is %d\n", maximum_value);

    // Free allocated memory
    free(numbers);

    return 0;
}
