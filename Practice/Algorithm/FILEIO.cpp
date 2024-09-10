#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    FILE *f;
    int a, b, c;

    fopen("a.txt'", "w");
    fscanf(f, "%d%d%d", a, b, c);
    fprintf(f, "%d%d%d", a, b, c);
    return 0;
}
