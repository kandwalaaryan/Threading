# Multithreaded Statistical Analysis and Prime Number Generation

This repository contains two C programs developed by me. Both programs demonstrate the use of POSIX threads for concurrent execution.

## Statistical Analysis Program (`stats.c`)

This program calculates statistical values for a list of numbers provided on the command line. It creates three separate worker threads to determine the average, maximum, and minimum values of the numbers.

### Compilation and Execution

```bash
gcc -o stats stats.c -lpthread
./stats 90 81 78 95 79 72 85
```

## Prime Number Generator Program (`prime.c`)

This program is designed to find and list all prime numbers up to a specified limit. It accepts a single integer argument from the command line and spawns a thread that calculates and prints all prime numbers less than or equal to the given number.

### Compilation and Execution

To compile and run the program, use the following commands in a terminal with GCC installed:

```bash
gcc -o prime prime.c -lpthread
./prime 20
