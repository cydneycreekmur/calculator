#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
#include <cctype>

using namespace std;

long double pi = acos(-1);
long double e = exp(1.0);

/**
 * enum for parsing expressions
 * @author Cydney
 */
enum TokenType {
    INT,
    FLOAT,
    OPERATOR,
    IDENTIFIER,
    LEFT_PARENT,
    RIGHT_PARENT
};

/**
 * class for token objects
 * @author Cydney
 */
class Token {
public:
    TokenType type;
    string value;

    Token(TokenType t, string v)
        : type(t), value(v) {}

    static const vector<Token> OPERATORS;
};

// use this for checking operators
const vector<Token> Token::OPERATORS = {
    {OPERATOR, "+"},
    {OPERATOR, "-"},
    {OPERATOR, "*"},
    {OPERATOR, "/"},
    {OPERATOR, "="}
};

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

/**
 * Tokenizer
 * Use for expressions and equations before parsing
 * @author Cydney
 */
vector<Token> tokenize(const string& expression) {
    vector<Token> tokens;

    

    /**string current = "";
    
    for (char c : str) {
        if (c == delimiter) {
            result.push_back(current);
            current = "";
        } else {
            current += c;
        }
    }
    
    // Add the last substring
    result.push_back(current);
    
    return result;*/
}

/**
 * ParseExpression Function
 * Will solve an expression with no variables or known variables
 * @author Cydney
 */
long double parseExpressionSolve(vector<Token> tokens){

};

/**
 * ParseExpression Function
 * Will simplify an expression with unknown variables
 * @author Cydney
 */
vector<long double> parseExpressionSimplify(vector<Token> tokens){

};

/**
 * ParseEquation Function
 * @author Andrew
 */
vector<long double> parseEquation(string equation){
    
    if (count(equation.begin(), equation.end(), '=') > 2) {
        cout << "Please provide a valid Equation (Too many ='s in the Equation)\n";
        return {};
    }

    string left_side = "";
    string right_side = "";

    // First string pass
    int count = 0;
    for (char letter : equation){
        if (letter == '='){
            count += 1;
        }else if (count == 0){
            left_side += letter;
        }else{
            right_side += letter;
        }
    }

    // check for which side has the y and which has the x
    string x_equ = "";
    string y_equ = "";
    if (left_side.find('x') == string::npos){
        x_equ = left_side;
        y_equ = right_side;
    }else{
        x_equ = right_side;
        y_equ = left_side;
    }

    stack<string> equ;



}

/**
 * Sanitize Negatives Function:
 * turns subtractions into + negative numbers
 * @author Andrew
 */
string negative_sanitize(string equ){
    string new_equ = "";
    int neg_counter = 0;

    for (int i = 0; i < equ.length(); i++){
        if (equ[i] == '-'){
            neg_counter += 1; // increase the negative count
        }else if (equ[i] == '+' && neg_counter > 0){
            continue;
        }else if (neg_counter > 0){
            if (neg_counter % 2 == 0){
                new_equ += '+';
            }else{
                if (i == 1){
                    new_equ += '-';
                }else{
                    new_equ += '+';
                    new_equ += '-';
                }
            }
            new_equ += equ[i];
            neg_counter = 0;
        }else{
            new_equ += equ[i];
        }
    }
    return new_equ;
}

/**
 * Sanitize Multiplication Function:
 * turns implicit multiplication into *
 * @author Andrew
 */
string multiply_sanitize(string equ){
    string new_equ = "";

    for (int i = 0; i < equ.length(); i++){

        if (equ[i] == '('){

            // checking for implicit multiplication on the left side of (
            if (i != 0 && (isdigit(equ[i-1]) || isalpha(equ[i-1]))){ 
                new_equ += '*';
            }
            new_equ += '(';
        }else{

            if (i != 0){

                // Checking for )alpha or )num or numAlpha or alphaNum
                bool digitAfterLetter = isdigit(equ[i]) && isalpha(equ[i-1]);
                bool letterAfterDigit = isdigit(equ[i-1]) && isalpha(equ[i]);
                bool parenFollowedByAlphaNum = equ[i-1] == ')' && (isdigit(equ[i]) || isalpha(equ[i]));
                
                if (digitAfterLetter || letterAfterDigit || parenFollowedByAlphaNum) {
                    new_equ += '*';
                }
            }
            new_equ += equ[i];
        }
    }

    return new_equ;
}

/**
 * Sanitize Operator Function:
 * Checks for multiple operators and condenses to 1 (+, *, /, ^, =)
 * @author Andrew
 */
string operator_sanitize(string equ) {
    vector<char> operators = {'+', '*', '/', '^', '='};
    string new_equ = "";
    char last_char = '\0';

    for (char c : equ) {
        bool is_operator = find(operators.begin(), operators.end(), c) != operators.end();
        
        // Skip if this is a duplicate consecutive operator
        if (is_operator && c == last_char) {
            continue;
        }
        
        new_equ += c;
        last_char = c;
    }

    return new_equ;
}

/**
 * Parenthesis Check Function:
 * Checks to see if all parenthesis are correctly closed. if not, return Bool False
 * @author Andrew
 */
bool parenthesis_check(string equ) {
    int count = 0;
    for (char c : equ) {
        if (c == '(') {
            count++;
        } else if (c == ')') {
            count--;
            // If count goes negative, we have a closing paren without opening
            if (count < 0) {
                return false;
            }
        }
    }
    
    // If count is 0, all parens are balanced
    return count == 0;
}

/**
 * Split Function:
 * Splits a string by a delimiter character and returns a vector of substrings
 * @author Andrew
 */
vector<string> split(string str, char delimiter) {
    vector<string> result;
    string current = "";
    
    for (char c : str) {
        if (c == delimiter) {
            result.push_back(current);
            current = "";
        } else {
            current += c;
        }
    }
    
    // Add the last substring
    result.push_back(current);
    
    return result;
}


int main() {

    cout << multiply_sanitize(negative_sanitize(operator_sanitize("-3(3-4++++5-4-4****y(5-3))--2"))) + "\n";

    /*
    // initialize numbers and sum variables
    long double x, y;
    cout << "Type a number: ";
    cin >> x;
    cout << "Type another number: ";
    cin >> y;
    cout << "The number " + to_string(static_cast<double>(x)) + " to the power of " + to_string(static_cast<double>(y)) + " is " + to_string(static_cast<double>(power(x, y))) + "\n";
    cout << "The sum is " << x + y << "\n";
    cout << "The root of " << y << " in " << x << " is: "<<root(x, y)<<"\n";
    */    
}