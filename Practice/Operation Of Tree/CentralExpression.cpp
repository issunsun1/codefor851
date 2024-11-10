#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <stdexcept>

using namespace std;

int priority(char a)
{
    if(a=='*'||a=='/')
        return 2;
    else
        return 1;
}

//  中缀表达式转后缀表达式
stack<char> calculate(string s)
{
    stack<char> ans;
    stack<char> opera;

    for (int i = 0; i < s.length(); i++)
    {
        // 当输入的运算符优先级小于或等于暂时栈顶运算符，则将栈内运算符输出，
        // 直到左括号或者栈顶运算符优先级小于等于输入运算符

        // 当输入的为右括号则将运算符栈中所有运算符输出，直到遇到左括号    
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            while (!opera.empty() && opera.top() != '(' && priority(opera.top())>=priority(s[i]))
            {
                ans.push(opera.top());
                opera.pop();
            }
            opera.push(s[i]);
        }
        else if (s[i] == '(')
        {
            opera.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!opera.empty() && opera.top() != '(')
            {
                ans.push(opera.top());
                opera.pop();
            }
            if (!opera.empty())
                opera.pop();
        }
        else
        {
            ans.push(s[i]-'0');
        }
    }

    while (!opera.empty())
    {
        ans.push(opera.top());
        opera.pop();
    }

    return ans;
}

int evaluate(stack<char> postfix)
{
    stack<int> ans;
    while (!postfix.empty())
    {
        char temp = postfix.top();
        postfix.pop();
        if (isdigit(temp))
        {
            ans.push(temp - '0');
        }
        else
        {
            int b = ans.top();
            ans.pop();
            int a = ans.top();
            ans.pop();
            switch (temp)
            {
            case '+':
                ans.push(a + b);
                break;
            case '-':
                ans.push(a - b);
                break;
            case '*':
                ans.push(a * b);
                break;
            case '/':
                if (b == 0)
                    throw runtime_error("Division by zero");
                ans.push(a / b);
                break;
            }
        }
    }
    return ans.top();
}