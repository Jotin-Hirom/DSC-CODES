#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if the character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert postfix expression to prefix
string postfixToPrefix(const string& postfix) {
    stack<string> s;

    // Traverse the postfix expression from left to right
    for (char ch : postfix) {
        // If the character is an operand, push it to the stack
        if (isalnum(ch)) {
            s.push(string(1, ch));
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();

            // Combine the operands and operator in prefix form
            string result = ch + op1 + op2;
            s.push(result);
        }
    }

    // The final element in the stack is the complete prefix expression
    return s.top();
}

int main() {
    string postfix = "AB+CD-*";
    cout << "Prefix expression: " << postfixToPrefix(postfix) << endl;
    return 0;
}
