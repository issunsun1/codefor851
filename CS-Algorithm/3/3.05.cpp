#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

const int maxsize = 101;

class mystack{

    private:
        vector<int> a;
        int s1;
        int s2;

    public:
        mystack(int maxsize) : a(maxsize), s1(0), s2(maxsize - 1) {};
        void mypush_s1(int x)
        {
            if(s1+1!=s2)
                a[s1++] = x;
        }

        void mypush_s2(int x)
        {
            if(s2-1!=s1)
                a[s2--] = x;
        }

        int mypop_s1()
        {
            if(s1>=0)
                return a[s1--];
        }

        int mypop_s2()
        {
            if(s2<=maxsize-1)
                return a[s2++];
        }
};

// int main()
// {
//     const long long num = 8 * 1024;
//     cout << hex << num << endl;

//     return 0;
// }
