#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long double pi = acos(-1);
long double e = exp(1.0);
// need functions for arithmetic

/**
 * Addition functions
 * @author Cydney
 */
long double add(long double x, long double y) {
    return x + y;
}
/**
 * Subtraction functions
 * @author Cydney
 */ 
long double subtract(long double x, long double y) {
    return x - y;
}
/**
 * Multiplication function
 * @author Cydney
 */
long double multiply(long double x, long double y) {
    return x * y;
}

/**
 * Division
 * @author Cydney
 */
long double divide(long double x, long double y) {
    return x / y;
}

/**
 * Log functions
 * @author Cydney
 */
// log (base 10)
long double log_10(long double x) {
    return log10(x);
}

// natural log (base e)
long double ln(long double x) {
    return log(x);
}

// log base b of x
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