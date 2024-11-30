#include <iostream>
#include <vector>
using namespace std;

vector<int> weight;
vector<int> nums;
vector<int> value;

typedef struct TNode
{
    int val;
    TNode *left;
    TNode *right;
} TNode;

vector<int> pretravel(TNode *root)
{
    stack<TNode *> s;
    vector<int> ans;

    if(root==nullptr)
        return ans;

    s.push(root);

    while(root||!s.empty())
    {
        while(root)
        {
            ans.push_back(root->val);
            s.push(root);
            root = root->left;
        }

        TNode *temp = s.top();
        s.pop();

        root = temp->right;
    }
}

vector<int> centraltravel(TNode *root)
{
    stack<TNode *> s;
    vector<int> ans;
    if(root==nullptr)
        return ans;
    s.push(root);

}
