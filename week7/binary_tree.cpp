#include <iostream>
#include <vector>
using namespace std;

struct NODE{
    int key;
    NODE *p_left;
    NODE *p_right;
};

NODE *createNode(int data){
    NODE* q= new NODE;
    q->key=data;
    q->p_left = nullptr;
    q->p_right = nullptr;
    return q;
}
void NLRHelper(NODE *pRoot, vector<int> &c){
    if (!pRoot) return;
    c.push_back(pRoot->key);
    NLRHelper(pRoot->p_left, c);
    NLRHelper(pRoot->p_right, c);
}
vector <int> NLR(NODE *pRoot){
    vector<int> result;
    NLRHelper(pRoot, result);
    return result;
}
void LNRHelper(NODE *pRoot, vector<int> &c){
    if (!pRoot) return;
    LNRHelper(pRoot->p_left, c);
    c.push_back(pRoot->key);
    LNRHelper(pRoot->p_right, c);
}
vector<int> LNR(NODE *pRoot){
    vector<int> result;
    LNRHelper(pRoot, result);
    return result;
}

void LRNHelper(NODE *pRoot, vector<int> &c){
    if (!pRoot) return;
    LRNHelper(pRoot->p_left, c);
    LRNHelper(pRoot->p_right, c);
    c.push_back(pRoot->key);
}

vector<int> LRN(NODE *pRoot){
    vector<int> result;
    LRNHelper(pRoot, result);
    return result;
}

void levelOrderHelper(NODE* pRoot, vector<vector<int>>& q, int level){
    if (!pRoot) return;

    if (q.size() <= level) q.push_back({});
    q[level].push_back(pRoot->key); //Có level chỉ định, chỉ cần đảm bảo thứ tự thêm vào là trái sang phải (đệ quy)

    levelOrderHelper(pRoot->p_left, q, level + 1);
    levelOrderHelper(pRoot->p_right, q, level + 1);
}

vector<vector<int>> LevelOrder(NODE* pRoot){
    vector<vector<int>> result;
    levelOrderHelper(pRoot, result, 0);
    return result;
}

int countNode(NODE* pRoot){
    //Base case
    if (!pRoot) return 0;
    //Left
    int leftCount = countNode(pRoot->p_left);
    int rightCount = countNode(pRoot->p_right);
    return leftCount + rightCount + 1 ;
}
int sumNode(NODE* pRoot){
    if (!pRoot) return 0;

    int leftSum = sumNode(pRoot->p_left);
    int rightSum = sumNode(pRoot->p_right);

    return pRoot->key + leftSum + rightSum;
}

int getHeightNode (NODE *pRoot){
    if (!pRoot) return -1;
    return 1 + max(getHeightNode(pRoot->p_left), getHeightNode(pRoot->p_right));
}

int heightNode(NODE *pRoot, int value){
    if (!pRoot) return -1;
    if (pRoot->key == value){
        return getHeightNode(pRoot);
    }

    int left = heightNode(pRoot->p_left, value);
    if (left != -1) return left;

    return heightNode(pRoot->p_right, value);
}


int Level(NODE* pRoot, NODE* p){
   
    if (!pRoot || !p) return -1;

    if (pRoot == p) return 0;

    int leftLevel = Level(pRoot->p_left, p);
    if (leftLevel != -1) return leftLevel + 1;

    int rightLevel = Level(pRoot->p_right, p);
    if (rightLevel != -1) return rightLevel + 1;

   return -1;
}
int countLeaf(NODE* pRoot){
    if (!pRoot) return 0;
    if (!pRoot->p_left && !pRoot->p_right) return 1;

    int left = countLeaf(pRoot->p_left);
    int right = countLeaf(pRoot->p_right);
    
    return left+right;
}

