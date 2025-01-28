#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if the character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert prefix expression to postfix
string prefixToPostfix(const string& prefix) {
    stack<string> s;

    // Traverse the prefix expression from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];

        // If the character is an operand, push it to the stack
        if (isalnum(ch)) {
            s.push(string(1, ch));
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            // Combine the operands and operator in postfix form
            string result = op1 + op2 + ch;
            s.push(result);
        }
    }

    // The final element in the stack is the complete postfix expression
    return s.top();
}

int main() {
    string prefix = "*+AB-CD";
    cout << "Postfix expression: " << prefixToPostfix(prefix) << endl;
    return 0;
}
