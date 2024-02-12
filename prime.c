#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

// This Function checks if a given number is prime
bool is_prime(int n) {
    // If num is less than 2, it is not prime
    if (n <= 1) {
        return false;
    }
    // Checks from 2 to the largest whole number less than the square root of n for prime
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
// Thread function to print primes from 0 to any given number, uses helper function
void* print_primes(void* arg) {
    // Sets n to the input
    int n = (int)arg;
    // Checks if every number from 2 to n is prime
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d is prime\n", i);
        }
    }
    // Terminates the thread
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    // Checks for invalid input
    if (argc != 2) {
        fprintf("Invalid input, please enter only 1 number:\n");
        return 1;
    }
    // sets n to the input
    int n = atoi(argv[1]);
    
    //Runs the thread
    pthread_t prime_thread;
    pthread_create(&prime_thread, NULL, print_primes, (void *)n);
    pthread_join(prime_thread, NULL);

    return 0;
}
