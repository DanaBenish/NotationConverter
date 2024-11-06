# NotationConverter
Overview:
This project implements a Notation Converter using a custom-built Deque (Double-Ended Queue) based on a doubly linked list. The Notation Converter class can convert between three types of mathematical notations commonly used in arithmetic:

Postfix (Reverse Polish) Notation
Infix Notation
Prefix (Polish) Notation
Functionality

The Notation Converter can convert input strings from one notation to another. Valid inputs include expressions with:
Operands represented by letters (case-insensitive)
Operators: +, -, *, /
Parentheses for infix notation (with specific whitespace rules)
Example Conversions:

Postfix: "c d / a b * r r * / *" → Infix: "((c / d) * ((a * b) / (r * r)))"
Prefix: "* + A B - C D" → Postfix: "A B + C D - *"
Class and Methods

The NotationConverter class contains the following methods:
postfixToInfix(std::string inStr)
postfixToPrefix(std::string inStr)
infixToPostfix(std::string inStr)
infixToPrefix(std::string inStr)
prefixToInfix(std::string inStr)
prefixToPostfix(std::string inStr)
Each method converts the notation as specified using only the Deque for data storage (no STL containers).

Testing:
This project uses the Catch2 testing framework for validating the implementation. Ensure all test requirements are met by running the provided test file (PP2Test.cpp) before submission.

Deliverables
NotationConverter.hpp (Header file)
NotationConverter.cpp (Source file)
PP2Test.cpp (Test file)
catch.hpp (Catch2 header)
NotationConverterInterface.hpp (Interface header)
