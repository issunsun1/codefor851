#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void merge(vector<int> &nums, int l, int mid, int r)
{
    vector<int> temp(r - l + 1);
    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r)
    {
        if (nums[i] < nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }

    while (i <= mid)
        temp[k++] = nums[i++];
    while (j <= r)
        temp[k++] = nums[j++];

    for (int p = 0; p < temp.size(); p++)
    {
        nums[l + p] = temp[p];
    }
}

void merge_sort(vector<int> &nums, int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    merge_sort(nums, l, mid);
    merge_sort(nums, mid + 1, r);
    merge(nums, l, mid, r);
}

int findKthLargest(vector<int> &nums, int k)
{

    merge_sort(nums, 0, nums.size() - 1);
    return nums[nums.size() - k];
}



int main()
{
    
    return 0;
}
