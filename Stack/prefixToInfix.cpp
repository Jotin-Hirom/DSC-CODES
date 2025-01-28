#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if the character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert postfix expression to infix
string postfixToInfix(const string& postfix) {
    stack<string> s;

    for (char ch : postfix) {
        // If the character is an operand, push it to the stack
        if (isalnum(ch)) {
            string operand(1, ch);
            s.push(operand);
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();

            // Combine the two operands and operator in infix form
            string result = "(" + op1 + ch + op2 + ")";
            s.push(result);
        }
    }

    // The final element in the stack is the complete infix expression
    return s.top();
}

int main() {
    string postfix = "ab+c*";
    cout << "Infix expression: " << postfixToInfix(postfix) << endl;
    return 0;
}
