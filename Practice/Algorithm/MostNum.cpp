#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

bool static cmp(const pair<int,int>a,const pair<int,int> b)
{
    return a.second > b.second;
}

vector<int> search_num(vector<int> a)
{
    unordered_map<int,int> map;
    vector<int> res;

    for (int i = 0; i < a.size();i++)
        map[a[i]]++;

    vector< pair<int, int> > b(map.begin(),map.end());

    sort(b.begin(),b.end(), cmp);

    res.push_back(b[0].first);

    for (int i = 1; i < b.size();i++)
    {
        if(b[i].second==b[0].second)
            res.push_back(b[i].first);
        else
            break;
    }

    return res;
}

int main()
{
    
    return 0;
}
