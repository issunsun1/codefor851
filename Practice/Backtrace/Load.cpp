#include <iostream>
#include <vector>
using namespace std;
int box_num;
vector<int> box_weight;
int ship_load;
int current_weight;
int best_weight;

void backtrace(int i)
{
    if(i>box_num)
    {   
        if(current_weight>best_weight)
            best_weight = current_weight;
        return;
    }
    if(current_weight+box_weight[i]<=ship_load)
    {
        current_weight += box_weight[i];
        backtrace(i + 1);
        current_weight -= box_weight[i];
    }
    backtrace(i + 1);
}
