# another-pi-with-c
Another c app to calculate pi

## Overview

This application demonstrates three different mathematical approaches to calculating the value of pi, each utilizing distinct computational strategies with varying convergence rates and accuracy characteristics. The implementation showcases how different numerical methods can be applied to solve the same mathematical problem, providing insights into their relative performance and precision.

## Mathematical Methods

The program implements three well-established algorithms for computing pi, each with its own theoretical foundation and practical considerations. The Leibniz formula represents one of the earliest infinite series approaches to calculating pi, though it converges relatively slowly compared to more modern methods. This method is based on the Gregory-Leibniz series, which expresses pi divided by four as an alternating sum of reciprocals of odd numbers. Specifically, the formula states that pi/4 equals 1 minus 1/3 plus 1/5 minus 1/7 plus 1/9, and so on, continuing indefinitely. While elegant in its simplicity, this method requires a substantial number of iterations to achieve high precision due to its slow convergence rate.

The Nilakantha series offers a significantly faster convergence compared to the Leibniz formula, making it a more practical choice for applications requiring higher accuracy with fewer iterations. This method starts with an initial approximation of 3 and then adds or subtracts terms involving products of consecutive even numbers. The series takes the form of pi equals 3 plus 4 divided by the product of 2, 3, and 4, minus 4 divided by the product of 4, 5, and 6, plus 4 divided by the product of 6, 7, and 8, and so forth. Each term contributes more significantly to the final result than the corresponding term in the Leibniz series, allowing for faster convergence to the true value of pi.

The Monte Carlo method represents a completely different approach based on probabilistic sampling rather than infinite series summation. This technique leverages random number generation to estimate pi by simulating the relationship between the area of a circle and its enclosing square. The algorithm generates random points within a unit square and determines what proportion of these points fall within a quarter circle inscribed in that square. Since the ratio of the area of a quarter circle to the area of the unit square equals pi divided by 4, multiplying the proportion of points inside the circle by 4 yields an approximation of pi. While this method is conceptually straightforward and demonstrates the power of stochastic simulation, its accuracy depends heavily on the quality of the random number generator and typically requires a very large number of samples to achieve precision comparable to the deterministic series methods.

## Calculating More Digits of Pi

The precision of pi calculations depends fundamentally on the number of iterations performed by each algorithm. To obtain more digits of pi, you need to increase the iteration count, which allows the mathematical series to converge closer to the true value. The application currently uses a default of one million iterations, which provides a reasonable balance between computation time and precision.

However, achieving additional decimal places typically requires significantly more iterations, with the exact relationship varying based on each algorithm's convergence rate. To modify the number of iterations, you can edit the DEFAULT_ITERATIONS constant defined in the source code before compilation. Increasing this value to ten million, one hundred million, or even higher will progressively improve the precision of the results, though with correspondingly longer execution times.

Each algorithm responds differently to increased iterations, with the Nilakantha series typically requiring fewer iterations than the Leibniz formula to achieve the same precision, while the Monte Carlo method's accuracy improves more gradually and probabilistically with sample size.

## Building and Running

To build this application, you'll need a C compiler with math library support. The project uses CMake as its build system, which provides a cross-platform way to generate native build files. Create a build directory, navigate into it, and run CMake to configure the project, then compile the source code using your platform's native build tools. Once compiled, execute the resulting binary to see the pi calculations performed using all three methods simultaneously, with each method using the same number of iterations for comparison purposes. The program will display the computed values alongside the actual value of pi, allowing you to observe the relative accuracy of each approach.
