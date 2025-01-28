#include <iostream>
#include <stack>
using namespace std;

bool areMatching(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(const string &expression)
{
    stack<char> s;
    for (char ch : expression)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty() || !areMatching(s.top(), ch))
            {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main()
{
    string expression = "{a+b*[c+(d-e)/h]+j}+k";
    if (isBalanced(expression))
    {
        cout << "Symbols are balanced." << endl;
    }
    else
    {
        cout << "Symbols are not balanced." << endl;
    }
    return 0;
}
