#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#define maxsize 1000

using namespace std;

typedef struct
{
    int data[maxsize];
    int length;
} sqllist;

void init_list(sqllist &L)
{
    L.length = 0;
}

int main()
{
    // cout << "commit test" << endl;
    sqllist L;
    init_list(L);
    cout << L.length << endl;
    return 0;
}
