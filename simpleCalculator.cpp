#include <iostream>
#include <cmath>

using namespace std;

double pi = acos(-1);
double e = exp(1.0);
// need functions for arithmetic

// addition
double add(double x, double y) {
    return x + y;
}
// subtraction
double subtract(double x, double y) {
    return x - y;
}
// mult


// div
// power
// log
// sqrt
// euler

int main() {
    // initialize numbers and sum variables
    double x, y;

    cout << "Type a number: ";
    cin >> x;
    cout << "Type another number: ";
    cin >> y;
    cout << "The sum is " << x + y << "\n";
}