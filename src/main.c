#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DEFAULT_ITERATIONS 1000000

/**
 * Calculate pi using the Leibniz formula (Gregory-Leibniz series)
 * pi/4 = 1 - 1/3 + 1/5 - 1/7 + 1/9 - ...
 */
double calculate_pi_leibniz(int iterations) {
    double pi = 0.0;
    for (int i = 0; i < iterations; i++) {
        double term = 1.0 / (2 * i + 1);
        if (i % 2 == 0) {
            pi += term;
        } else {
            pi -= term;
        }
    }
    return pi * 4.0;
}

/**
 * Calculate pi using the Nilakantha series
 * pi = 3 + 4/(2*3*4) - 4/(4*5*6) + 4/(6*7*8) - ...
 */
double calculate_pi_nilakantha(int iterations) {
    double pi = 3.0;
    int sign = 1;
    for (int i = 1; i <= iterations; i++) {
        double denominator = (2.0 * i) * (2.0 * i + 1) * (2.0 * i + 2);
        pi += sign * (4.0 / denominator);
        sign *= -1;
    }
    return pi;
}

/**
 * Calculate pi using the Monte Carlo method
 */
double calculate_pi_monte_carlo(int iterations) {
    int inside_circle = 0;
    for (int i = 0; i < iterations; i++) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1.0) {
            inside_circle++;
        }
    }
    return 4.0 * inside_circle / iterations;
}

int main() {
    srand(time(NULL));
    int iterations = DEFAULT_ITERATIONS;
    
    printf("Pi Calculator\n");
    printf("=============\n\n");
    
    double pi_leibniz = calculate_pi_leibniz(iterations);
    printf("Leibniz formula (iterations=%d): %.15f\n", iterations, pi_leibniz);
    
    double pi_nilakantha = calculate_pi_nilakantha(iterations);
    printf("Nilakantha series (iterations=%d): %.15f\n", iterations, pi_nilakantha);
    
    double pi_monte_carlo = calculate_pi_monte_carlo(iterations);
    printf("Monte Carlo method (iterations=%d): %.15f\n", iterations, pi_monte_carlo);
    
    printf("\nActual value of pi:               %.15f\n", M_PI);
    
    return 0;
}
