#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long double pi = acos(-1);
long double e = exp(1.0);
// need functions for arithmetic

/**
 * addition
 * @author cyd
 */
long double add(long double x, long double y) {
    return x + y;
}
/**
 * subtraction
 * @author cyd
 */ 
long double subtract(long double x, long double y) {
    return x - y;
}
/**
 * multiplication
 * @author cyd
 */
long double multiplication(long double x, long double y) {
    return x * y;
}

/**
 * division
 */

/**
 * logs
 * @author cyd
 */
long double log_10(long double x) {
    return log10(x);
}

long double ln(long double x) {
    return log(x);
}

long double log_b(long double b, long double x) {
    return log(x) / log(b);
}

/**
 * Power function x ^ y
 * @author Andrew
 */
long double power(long double x, long double y){
    if (y == 1){
        return x;
    }
    return x * power(x, y-1);
}

 /**
 * Root function x^(1/y)
 * @author Andrew
 */
long double root(long double x, long double y, long double guess = 1.0L, long double eps = 1e-20L) {
    // Calculate next approximation using Newton-Raphson
    long double nextGuess = (1.0L / y) * ((y - 1) * guess + x / power(guess, y - 1));

    // Base case: if difference is small enough
    if (fabsl(nextGuess - guess) < eps) {
        return nextGuess;
    }

    // Recursive call
    return root(x, y, nextGuess, eps);
}

 /**
 * Euler function (e^x)
 * @author Andrew
 */
long double euler(long double y){
    if (y == 1){
        return e;
    }
    return e * euler(y-1);
}

int main() {
    // initialize numbers and sum variables
    long double x, y;

    cout << "Type a number: ";
    cin >> x;
    cout << "Type another number: ";
    cin >> y;
    cout << "The number " + to_string(static_cast<double>(x)) + " to the power of " + to_string(static_cast<double>(y)) + " is " + to_string(static_cast<double>(power(x, y))) + "\n";
    cout << "The sum is " << x + y << "\n";
    cout << "The root of " << y << " in " << x << " is: "<<root(x, y)<<"\n";
}