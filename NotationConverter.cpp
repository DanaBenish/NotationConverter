/*

Written by Dana Benish. This header file implements the NotationConverter class 
implemented with Deque. Functions can convert between postfix, infix, and Prefix.

*/

#include "NotationConverter.hpp"
#include "DLDeque.hpp"
#include "DLDeque.cpp"

#include <sstream>

int NotationConverter::getOperatorPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // For any other character
}

// Check if char is operator
bool NotationConverter::isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Check if char is operand
bool NotationConverter::isOperand(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Chack if char is valid input
bool NotationConverter::isValid(char c){
    if( ( !isOperand(c) ) && ( !isOperator(c) ) && ( c != ' ' ) && (c != '(' ) && ( c != ')' )){
        return false;
    }
    return true;
 }

// Convert between postfix to infix
std::string NotationConverter::postfixToInfix(std::string inStr){

    Deque deque; // Create deque object

    for (char ch : inStr) {

        // Check if char is valid and throw if not
        if(!isValid(ch)){
            throw std::invalid_argument("Invalid character in expression");
        }

        if (isOperand(ch)) {
            // Push the operand as a string into the Deque
            deque.pushBack(std::string(1, ch));
        } else if (isOperator(ch)) {
            std::string operand2 = deque.popBack(); // Pop the second operand
            std::string operand1 = deque.popBack(); // Pop the first operand
            
            // Form the infix expression
            std::string expression = "(" + operand1 + " " + ch + " " + operand2 + ")";
            deque.pushBack(expression);
        }
    }
    return deque.popBack();
}

// Convert between postfix to prefix
std::string NotationConverter::postfixToPrefix(std::string inStr){

    // Use existing fuctions to convert postfix -> infix, and then infix -> prefix
    std::string temp = postfixToInfix(inStr);
    temp = infixToPrefix(temp);
    return temp;
}

// Convert between infix to postfix
std::string NotationConverter::infixToPostfix(std::string inStr){

    Deque deque; // Create deque object
    Deque operators; // Create helper operator deque

    for (char ch : inStr) {

        // Check if char is valid and throw if not
        if(!isValid(ch)){
            throw std::invalid_argument("Invalid character in expression");
        }
        if (isOperand(ch)) {
            // Push the operand as a string into the Deque
            deque.pushBack(std::string(1, ch));
        } else if (isOperator(ch)) {
            // Handle operator precedence and associativity
            while (!operators.isEmpty() && getOperatorPrecedence(operators.getBack()[0]) >= getOperatorPrecedence(ch)) {
                // Pop from operators and form the postfix expression
                std::string operand2 = deque.popBack();
                std::string operand1 = deque.popBack();
                std::string op = operators.popBack();
                deque.pushBack(operand1 + " " + operand2 + " " + op); // Postfix notation
            }
            // Push the current operator onto the operators deque
            operators.pushBack(std::string(1, ch));
        } else if (ch == '(') {
            // Push opening parenthesis to the operators deque
            operators.pushBack(std::string(1, ch));
        } else if (ch == ')') {
            // Pop until an opening parenthesis is found
            while (!operators.isEmpty() && operators.getBack() != "(") {
                std::string operand2 = deque.popBack();
                std::string operand1 = deque.popBack();
                std::string op = operators.popBack();
                deque.pushBack(operand1 + " " + operand2 + " " + op); // Postfix notation
            }
            // Remove the opening parenthesis
            operators.popBack();
        }
    }

    // Pop remaining operators
    while (!operators.isEmpty()) {
        std::string operand2 = deque.popBack();
        std::string operand1 = deque.popBack();
        std::string op = operators.popBack();
        deque.pushBack(operand1 + operand2 + op);
    }

    return deque.popBack();
}

// Convert between infix to prefix
std::string NotationConverter::infixToPrefix(std::string inStr){
    Deque deque;  // Create deque object
    Deque operators; // Create operator deque

    std::reverse(inStr.begin(), inStr.end()); // Reverse string

    for (char ch : inStr) {

        // Check if char is valid and throw if not
        if(!isValid(ch)){
            throw std::invalid_argument("Invalid character in expression");
        }
        if (isOperand(ch)) {
            // Push the operand to the deque
            deque.pushBack(std::string(1, ch));

        } else if (isOperator(ch)) {
            // Handle operator precedence and associativity
            while (!operators.isEmpty() && getOperatorPrecedence(operators.getBack()[0]) > getOperatorPrecedence(ch)) {
                // Pop from operators
                std::string operand1 = deque.popBack(); // Pop the first operand
                std::string operand2 = deque.popBack(); // Pop the second operand
                std::string op = operators.popBack();

                // Form the expression
                deque.pushBack(op + " " + operand1 + " " + operand2); // Prefix notation
            }

            // Push the current operator
            operators.pushBack(std::string(1, ch));

        } else if (ch == ')') {
            operators.pushBack(std::string(1, ch));
        } else if (ch == '(') {
            // Pop until a closing parenthesis is found
            while (!operators.isEmpty() && operators.getBack() != ")") {
                std::string operand1 = deque.popBack();
                std::string operand2 = deque.popBack();
                std::string op = operators.popBack();
                deque.pushBack(op + " " + operand1 + " " + operand2); // Prefix notation
            }
            // Remove the closing parenthesis
            operators.popBack();
        }
    }

    // Pop remaining operators
    while (!operators.isEmpty()) {
        std::string operand1 = deque.popBack(); // Pop the first operand
        std::string operand2 = deque.popBack(); // Pop the second operand
        std::string op = operators.popBack();
        deque.pushBack(op + " " + operand1 + " " + operand2); // Prefix notation
    }

    return deque.popBack();
    
}

// Convert between prefix to infix
std::string NotationConverter::prefixToInfix(std::string inStr){

    Deque deque; // Create deque object

    std::reverse(inStr.begin(), inStr.end()); // Reverse string

    for (char ch : inStr) {

        // Check if char is valid and throw if not
        if(!isValid(ch)){
            throw std::invalid_argument("Invalid character in expression");
        }
        if (isOperand(ch)) {
            // Push the operand as a string into the Deque
            deque.pushBack(std::string(1, ch));
        } else if (isOperator(ch)) {
            std::string operand2 = deque.popBack(); // Pop the second operand
            std::string operand1 = deque.popBack(); // Pop the first operand
            
            // Form the infix expression and push it back
            std::string expression = ")" + operand1 + " " + ch + " " + operand2 + "(";
            deque.pushBack(expression);
        }
    }

    std::string temp = deque.popBack();
    std::reverse(temp.begin(), temp.end());
    return temp;
}

// Convert between prefix to postfix
std::string NotationConverter::prefixToPostfix(std::string inStr){

    // Use existing fuctions to convert prefix -> infix, and then infix -> postfix
    std::string temp = prefixToInfix(inStr);
    temp = infixToPostfix(temp);
    return temp;
}


