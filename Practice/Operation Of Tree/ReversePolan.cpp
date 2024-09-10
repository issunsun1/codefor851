#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int calculate(string s)
{
    stack<int> num;
    stack<string> opera;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            int num1 = num.top();
            num.pop();
            int num2 = num.top();
            num.pop();
            if (s[i] == '+')
                num.push(num2 + num1);
            if (s[i] == '-')
                num.push(num2 - num1);
            if (s[i] == '*')
                num.push(num2 * num1);
            if (s[i] == '/')
                num.push(num2 / num1);
        }
        else
        {
            num.push(s[i] - '0');
        }
    }
    int result = num.top();
    num.pop(); // 把栈里最后一个元素弹出（其实不弹出也没事）
    return result;
}

int main()
{
    
    return 0;
}
