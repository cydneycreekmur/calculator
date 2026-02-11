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
 * Square Root function x^(1/y)
 * @author Andrew
 */

 /**
 * Euler function (e^x)
 * @author Andrew
 */

int main() {
    // initialize numbers and sum variables
    long double x, y;

    cout << "Type a number: ";
    cin >> x;
    cout << "Type another number: ";
    cin >> y;
    cout << "The number " + to_string(static_cast<double>(x)) + " to the power of " + to_string(static_cast<double>(y)) + " is " + to_string(static_cast<double>(power(x, y))) + "\n";
    cout << "The sum is " << x + y << "\n";
}