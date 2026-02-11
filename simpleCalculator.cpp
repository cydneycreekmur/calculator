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
 * powers
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
 * roots
 */

/**
 * euler
 */

// mult - Cyd
// div - Cyd
// log - Cyd

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