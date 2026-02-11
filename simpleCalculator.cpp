#include <iostream>
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


int main() {
    // initialize numbers and sum variables
    long double x, y;

    cout << "Type a number: ";
    cin >> x;
    cout << "Type another number: ";
    cin >> y;
    cout << "The sum is " << x + y << "\n";
}