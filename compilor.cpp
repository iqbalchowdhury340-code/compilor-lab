#include<iostream>
#include<string>
using namespace std;

string NumericCheck(string input)
{
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] < '0' || input[i] > '9')
        {
            return "Not Numeric";
        }
    }

    return "Numeric Constant";
}

void OperatorCheck(string input)
{
    int count = 0;

    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == '+' || input[i] == '-' ||
           input[i] == '*' || input[i] == '/' ||
           input[i] == '%' || input[i] == '=')
        {
            count++;
            cout << "Operator " << count << ": " << input[i] << endl;
        }
    }

    if(count == 0)
    {
        cout << "No Operator Found" << endl;
    }
}

string CommentCheck(string input)
{
    int n = input.length();

    if(n >= 2 && input[0] == '/' && input[1] == '/')
    {
        return "Single Line Comment";
    }

    if(n >= 4 && input[0] == '/' && input[1] == '*' &&
       input[n-2] == '*' && input[n-1] == '/')
    {
        return "Multiple Line Comment";
    }

    return "Not Comment";
}

string IdentifierCheck(string input)
{
    if(input.length() == 0)
    {
        return "Not Identifier";
    }

    if(!((input[0] >= 'A' && input[0] <= 'Z') ||
         (input[0] >= 'a' && input[0] <= 'z') ||
         input[0] == '_'))
    {
        return "Not Identifier";
    }

    for(int i = 1; i < input.length(); i++)
    {
        if(!((input[i] >= 'A' && input[i] <= 'Z') ||
             (input[i] >= 'a' && input[i] <= 'z') ||
             (input[i] >= '0' && input[i] <= '9') ||
             input[i] == '_'))
        {
            return "Not Identifier";
        }
    }

    return "Identifier";
}

int main()
{
    string input;

    cout << "Enter Numeric Input: ";
    cin >> input;
    cout << NumericCheck(input) << endl;

    cout << "Enter Expression: ";
    cin >> input;
    OperatorCheck(input);

    cout << "Enter Comment: ";
    cin >> input;
    cout << CommentCheck(input) << endl;

    cout << "Enter Identifier: ";
    cin >> input;
    cout << IdentifierCheck(input) << endl;

    return 0;
}
