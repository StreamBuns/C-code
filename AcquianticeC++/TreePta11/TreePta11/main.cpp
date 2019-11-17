//
//  main.cpp
//  TreePta11
//
//  Created by 赵桐 on 2019/11/17.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iostream>
#include <string.h>
 
using namespace std;
 
//Huffman树结点类
class Node {
public:
    Node() {}
    Node(char element, int weight)
        :element(element), weight(weight), left(NULL), right(NULL) {}
 
    char element;
    int weight;
    Node* left = NULL;
    Node* right = NULL;
    bool isleave = false;
};
typedef Node* HFMTree;
 
//输入测试样例结点类
class Case {
public:
    char element;
    char route[1000];
    int length;
 
    int getlength() {
        return strlen(this->route);
    }
};
 
void Read(int num, vector<HFMTree>& minHeap, vector<HFMTree>& inputlist);
void Insert(vector<HFMTree>& minHeap, HFMTree node);        //插入数据创建最小堆
HFMTree CreateHFMT(vector<HFMTree>& minHeap);            //根据最小堆创建Huffman树
HFMTree DeleteMinHeap(vector<HFMTree>& minHeap);        //从最小堆中取出最小元素，删除该结点并重新调整最小堆,最后删除该结点
int getHFMLength(HFMTree hfmtree, int depth);                        //获得该树编码长度
 
void Input(vector<Case>& testcase, int num);
bool isOptimalLen(vector<Case>& testcase, vector<HFMTree>& inputlist, int weight);    //检查是否符合最优编码长度
bool isPrefixCode(vector<Case>& testcase);                //检查是否符合前缀码编码
 
 
int main()
{
    /*根据输入序列建立Huffman树，并获得最优编码长度*/
    int num;
    cin >> num;
 
    vector<HFMTree> minHeap;        //创建最小堆，用最小堆对序列进行存储
    vector<HFMTree> inputlist;        //记录输入顺序与权值大小
    HFMTree flag = new Node('-', -1);
    minHeap.push_back(flag);
    Read(num, minHeap, inputlist);
 
    HFMTree hfmtree;                //利用最小堆创建Huffman树
    hfmtree = CreateHFMT(minHeap);
    int optcodelength = getHFMLength(hfmtree, 0);    //通过序列创建的Huffman树获得最优编码长度
 
 
    /*对提交数据进行检查：1.是否符合最优编码长度，2.是否符合无歧义解码规则（前缀码编码，数据仅存在于二叉树叶节点）*/
    int count;
    cin >> count;
 
    for (int i = 0;i < count;i++) {
        vector<Case> testcase;
        Input(testcase, num);
        bool isoptimallen = isOptimalLen(testcase, inputlist, optcodelength);
        bool isprefixcode = isPrefixCode(testcase);
        if (isoptimallen && isprefixcode) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
 
    system("pause");
    return 0;
}
 
void Read(int num, vector<HFMTree>& minHeap, vector<HFMTree>& inputlist) {
    char element;
    int weight;
    for (int i = 0; i < num; i++) {
        cin >> element >> weight;
        HFMTree node = new Node(element, weight);
        inputlist.push_back(node);
        Insert(minHeap, node);
    }
    //minHeap.erase(minHeap.begin());
}
 
void Insert(vector<HFMTree>& minHeap, HFMTree node) {
    int index = minHeap.size();
    minHeap.push_back(node);
 
    //每次插入后自底向上进行调整
    while ((*minHeap[index / 2]).weight > (*node).weight) {
        //此处不可单纯进行值交换，需要交换两个对象
        //(*minHeap[index]).element = (*minHeap[index / 2]).element;
        //(*minHeap[index]).weight = (*minHeap[index / 2]).weight;
        minHeap[index] = minHeap[index / 2];
        index /= 2;
    }
    minHeap[index] = node;
}
 
HFMTree CreateHFMT(vector<HFMTree>& minHeap) {
 
    HFMTree hfmtree = new Node();
    int size = minHeap.size() - 1;
    //进行size-1次合并
    for (int i = 1; i < size; i++) {
        HFMTree node = new Node();
        //每次从最小堆中取出堆顶的两个结点作为该结点的左右子结点
        node->left = DeleteMinHeap(minHeap);
        node->right = DeleteMinHeap(minHeap);
        node->weight = node->left->weight + node->right->weight;
        //将该结点作为根节点的二叉树重新加入最小堆
        Insert(minHeap, node);
    }
 
    //从最小堆中取出建好的Huffman树
    hfmtree = DeleteMinHeap(minHeap);
 
    return hfmtree;
}
 
HFMTree DeleteMinHeap(vector<HFMTree>& minHeap) {
    //检查是否堆空
    if (minHeap.size() == 1) {
        return NULL;
    }
 
    //将该堆最大元素装入新结点并返回
    HFMTree node = new Node();
    node = minHeap[1];
 
    //重新调整该堆
    int size = minHeap.size();
    int parent, child;
    //用最大堆中最后一个元素从根结点开始向上过滤下层结点
    HFMTree cmp = new Node();
    cmp = minHeap[size - 1];
 
    //从根节点开始，用parent记录根结点下标，用child记录其最小子结点下标，每次循环将parent更新为上一次循环的child
    //当parent指向底层结点时跳出循环（会有极端情况比如偏向一边的堆使得parent最终并非指向该子树底层结点，但不影响结果）
    for (parent = 1; 2 * parent < size; parent = child) {
        child = parent * 2;
        //若该子结点不是堆尾结点，令child指向左右子结点中的较小者
        if ((child != size - 1) && ((*minHeap[child]).weight > (*minHeap[child + 1]).weight)) {
            child++;
        }
        //当循环到堆尾结点值小于等于该子结点值时，可以结束（此时堆尾结点会替换parent结点而不是child结点）
        if (cmp->weight <= (*minHeap[child]).weight) {
            break;
        }
        else {
            minHeap[parent] = minHeap[child];
        }
    }
    //将尾结点与当前父结点替换
    minHeap[parent] = cmp;
 
    //删除堆尾结点
    //此处不能用minHeap.erase(minHeap.end());，因为erase会返回被删除结点的下一结点，而尾结点的下一结点超限
    minHeap.pop_back();
 
    //返回该结点
    return node;
}
 
int getHFMLength(HFMTree hfmtree, int depth) {
    //若为叶子节点，直接返回其编码长度
    if (!hfmtree->left && !hfmtree->right) {
        return hfmtree->weight * depth;
    }
    //否则其他节点一定有两个子树，返回左右子树编码长度之合,深度相应加一
    else {
        return getHFMLength(hfmtree->left, depth + 1) + getHFMLength(hfmtree->right, depth + 1);
    }
}
 
void Input(vector<Case>& testcase, int num) {
    for (int i = 0;i < num;i++) {
        Case inputcase;
        cin >> inputcase.element >> inputcase.route;
        inputcase.length = inputcase.getlength();
        testcase.push_back(inputcase);
    }
}
 
bool isOptimalLen(vector<Case>& testcase, vector<HFMTree>& inputlist, int weight) {
    int testweight = 0;
    for (int i = 0;i < testcase.size();i++) {
        testweight += (testcase[i].length * (*inputlist[i]).weight);
    }
    if (testweight == weight) {
        return true;
    }
    else {
        return false;
    }
 
}
 
bool isPrefixCode(vector<Case>& testcase) {
    bool isprefixcode = true;
    HFMTree newtree = new Node();
 
    //两种情况验证不满足前缀码要求：1.后创建的分支经过或超过已经被定义的叶子结点，2.后创建分支创建结束时未达到叶子结点
    for (int i = 0;i < testcase.size();i++) {
        HFMTree point = newtree;
        if (isprefixcode == false)break;
 
        for (int j = 0;j < testcase[i].length;j++) {
 
            if (isprefixcode == false)break;
 
            if (testcase[i].route[j] == '0') {
                //先检查左子结点是否存在，若不存在，则创建一个左子结点
                if (!point->left) {
                    HFMTree newnode = new Node();
                    point->left = newnode;
                    point = point->left;
                    //若此时为分支的最后一环，则将该结点定义为叶子结点
                    if (j == testcase[i].length - 1) {
                        point->isleave = true;
                    }
                }
                //若左子树存在,则先将标记指针移至左子树。
                else {
                    point = point->left;
                    //若左子树为叶子结点，则不符合要求
                    if (point->isleave) {
                        isprefixcode = false;
                        break;
                    }
                    //若此时为分支的最后一环且仍有叶子结点，则不符合要求
                    if ((j == testcase[i].length - 1) && (point->left || point->right)) {
                        isprefixcode = false;
                        break;
                    }
                }
            }
            else if (testcase[i].route[j] == '1') {
                //先检查右子结点是否存在，若不存在，则创建一个右子结点
                if (!point->right) {
                    HFMTree newnode = new Node();
                    point->right = newnode;
                    point = point->right;
                    //若此时为分支的最后一环，则将该结点定义为叶子结点
                    if (j == testcase[i].length - 1) {
                        point->isleave = true;
                    }
                }
                //若左子树存在,则先将标记指针移至左子树。
                else {
                    point = point->right;
                    //若左子树为叶子结点，则不符合要求
                    if (point->isleave) {
                        isprefixcode = false;
                        break;
                    }
                    //若此时为分支的最后一环且仍有叶子结点，则不符合要求
                    if ((j == testcase[i].length - 1) && (point->left || point->right)) {
                        isprefixcode = false;
                        break;
                    }
                }
            }
        }
    }
 
    return isprefixcode;
}


