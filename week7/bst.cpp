#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct NODE{
 int key;
 NODE* p_left;
 NODE* p_right;
};

NODE* Search(NODE* pRoot, int x){
    if (!pRoot) return nullptr;
    if (x < pRoot-> key) {
        return (Search(pRoot->p_left, x));
    }
    else if (x > pRoot->key){
        return (Search(pRoot->p_right, x));
    }
    else
        return pRoot;
}

void Insert(NODE* &pRoot, int x){
    if (!pRoot){
        pRoot = new NODE;
        pRoot->key = x;
        pRoot->p_left = pRoot->p_right = nullptr;
        return;
    }
    
    if (pRoot->key == x) return;
    if (pRoot->key > x)
        Insert(pRoot->p_left, x);
    else Insert(pRoot->p_right, x);
 
}

void Remove(NODE* &pRoot, int x){
    if (!pRoot) return;
    if (x == pRoot->key){
        if (!pRoot->p_left && !pRoot->p_right){ 
            delete pRoot;
            pRoot = nullptr;
        }
        else if (pRoot->p_left && !pRoot->p_right){
            NODE *temp = pRoot;
            pRoot = pRoot->p_left;
            delete temp;
        }
        else if (!pRoot->p_left && pRoot->p_right){
            NODE* temp = pRoot;
            pRoot = pRoot->p_right;
            delete temp;
        } else {
            
            // Find the rightmost node in the left subtree
            NODE* maxLeft = pRoot->p_left;
            while (maxLeft->p_right != nullptr) {
                maxLeft = maxLeft->p_right;
            }
            pRoot->key = maxLeft->key; //Dời lên và xóa node cũ ở dưới
            Remove(pRoot->p_left, maxLeft->key);
        }

    }   
    else if (x < pRoot->key) {
        Remove(pRoot->p_left, x);
    }
    else {
        Remove(pRoot->p_right, x);
    }
}

NODE* createTree(int a[], int n){
    NODE*pRoot = nullptr;
    for (int i =0; i<n; i++){
        Insert(pRoot, a[i]);
    }
    return pRoot;
}

void removeTree(NODE* &pRoot){
    if (pRoot){
        removeTree(pRoot->p_left);
        removeTree(pRoot->p_right);
        delete pRoot;
        pRoot = nullptr;
    }
}

int Height(NODE* pRoot){
    if (!pRoot) return -1;
    int leftHeight = Height(pRoot->p_left);
    int rightHeight = Height(pRoot->p_right);

    return (1+max(leftHeight, rightHeight));
}
int countLess(NODE* pRoot, int x){
    if (!pRoot) return 0;

    if (pRoot->key < x)
        return 1 + countLess(pRoot->p_left, x) + countLess(pRoot->p_right, x);
    else
        return countLess(pRoot->p_left, x); 
}
int countGreater(NODE* pRoot, int x){
    if (!pRoot) return 0;
    
    if (pRoot->key > x)
        return 1 + countGreater(pRoot->p_left, x) + countGreater(pRoot->p_right, x);
    else
        return countGreater(pRoot->p_right, x);
}
bool isBST(NODE* pRoot, int minVal, int maxVal){ //cần bound min/max
    if (!pRoot) return true;
    
    if (pRoot->key <= minVal || pRoot->key >= maxVal)
        return false;
    return isBST(pRoot->p_left, minVal, pRoot->key) && isBST(pRoot->p_right, pRoot->key, maxVal);

}
bool isFull(NODE* pRoot){
    if (!pRoot) return true;
    if ((pRoot->p_left == nullptr) != (pRoot->p_right == nullptr)) return false;
    return isFull(pRoot->p_left) && isFull(pRoot->p_right);
}

bool isFullBST(NODE* pRoot){
     return (isBST(pRoot, INT_MIN, INT_MAX) && isFull(pRoot));
}

