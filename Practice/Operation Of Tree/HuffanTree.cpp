#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// 定义哈夫曼树节点结构
typedef struct HuffmanNode
{
    char data;
    int frequency;
    HuffmanNode *left;
    HuffmanNode *right;

    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
}HuffmanNode;

// 比较节点的优先级（频率），用于优先队列
struct cmp
{
    bool operator()(HuffmanNode *left, HuffmanNode *right)
    {
        return left->frequency > right->frequency;
        }
};


// 构造哈夫曼树
HuffmanNode *buildHuffmanTree(const unordered_map<char, int> &frequencies)
{
    priority_queue<HuffmanNode *, vector<HuffmanNode *>, cmp> minHeap;

    // 创建一个叶节点并将其插入优先队列
    for (const auto &pair : frequencies)
    {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    // 迭代直到堆中只有一个节点
    while (minHeap.size() != 1)
    {
        // 从堆中取出两个具有最低频率的节点
        HuffmanNode *left = minHeap.top();
        minHeap.pop();
        HuffmanNode *right = minHeap.top();
        minHeap.pop();

        // 创建一个新内部节点，其频率等于两个子节点的频率之和
        HuffmanNode *node = new HuffmanNode('\0', left->frequency + right->frequency);

        node->left = left;
        node->right = right;

        // 将新节点插入堆中
        minHeap.push(node);
    }

    // 堆中剩下的唯一节点是哈夫曼树的根节点
    return minHeap.top();
}

// 递归地生成哈夫曼编码
void generateHuffmanCodes(HuffmanNode *root, const std::string &str, std::unordered_map<char, std::string> &huffmanCodes)
{
    if (!root)
        return;

    // 找到叶节点
    if (!root->left && !root->right)
    {
        huffmanCodes[root->data] = str;
    }

    generateHuffmanCodes(root->left, str + "0", huffmanCodes);
    generateHuffmanCodes(root->right, str + "1", huffmanCodes);
}

int main()
{
    // 输入字符及其对应的频率
    unordered_set< pair<char, int> > set;
    unordered_map<char, int> frequencies;
    // set.insert({'a', 5});
    // set.insert({'b', 9});
    // set.insert({'c', 12});
    // set.insert({'d', 13});
    // set.insert({'e', 16});
    // set.insert({'f', 45});

    for(const auto &p:set)
    {
        frequencies.insert(p);
    }

    // 构造哈夫曼树
    HuffmanNode *root = buildHuffmanTree(frequencies);

    // 生成哈夫曼编码
    std::unordered_map<char, std::string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // 输出哈夫曼编码
    std::cout << "Character Huffman Codes:\n";
    for (const auto &pair : huffmanCodes)
    {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}
