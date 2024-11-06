
#ifndef NOTATIONCONVERTER_HPP
#define NOTATIONCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "NotationConverterInterface.hpp"
#include "DLDeque.hpp"


class NotationConverter : public NotationConverterInterface {
    private:
    
        Deque deque;

        // Helper functions
        int getOperatorPrecedence(char op);
        bool isOperator(char c);
        bool isOperand(char c);
        bool isValid(char c);

    public:

        // Required fuctions
        std::string postfixToInfix(std::string inStr);
        std::string postfixToPrefix(std::string inStr);
        std::string infixToPostfix(std::string inStr);
        std::string infixToPrefix(std::string inStr);
        std::string prefixToInfix(std::string inStr);
        std::string prefixToPostfix(std::string inStr);
};



#endif