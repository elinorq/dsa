#include <iostream>
#include <vector>
using namespace std;

struct NODE{
    int key;
    NODE* p_left;
    NODE* p_right;
    int height;
};

NODE* createNode(int data){
    NODE *q = new NODE;
    q->key = data;
    q->p_left = q->p_right = nullptr;
    q->height = 0;
    return q;
}

int getNodeHeight(NODE *node){
    return node ? node->height : -1;
}

void updateHeight(NODE *q){
    if (q) {
        q->height = 1 + max(getNodeHeight(q->p_left), getNodeHeight(q->p_right));
    }
}

int checkIfBalanced(NODE* pRoot) {
    if (!pRoot) return 0;

    int leftHeight = checkIfBalanced(pRoot->p_left);
    int rightHeight = checkIfBalanced(pRoot->p_right);

    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) return -1;

    return (1 + max(leftHeight, rightHeight));
}


NODE* rotateLeft(NODE * &pRoot){
    NODE *q = pRoot->p_right;
    NODE *p = q->p_left;

    q->p_left= pRoot;
    pRoot->p_right = p;

    updateHeight(pRoot);
    updateHeight(q);
    return q;
}

NODE *rotateRight(NODE * &pRoot){
    NODE *q = pRoot->p_left;
    NODE *p = q->p_right;
    
    q->p_right = pRoot;
    pRoot->p_left = p;

    updateHeight(pRoot);
    updateHeight(q);

    return q;
}

bool isAVL(NODE *&pRoot){
    if (pRoot == nullptr)
            return true;
        
    if (checkIfBalanced(pRoot) == -1) return false;
    return true;

}

void Insert(NODE* &pRoot, int x){
    if (!pRoot){
        pRoot = createNode(x);
        return;
    }

    if (x < pRoot->key)
        Insert(pRoot->p_left, x);
    else if (x > pRoot->key)
        Insert(pRoot->p_right, x);
    else
        return;

    updateHeight(pRoot);
    int balance = getNodeHeight(pRoot->p_left) - getNodeHeight(pRoot->p_right);

    if (balance > 1){
        if (x < pRoot->p_left->key){ //Left-Left
          pRoot = rotateRight(pRoot); 
        }
        else { //Left-Right
            pRoot->p_left = rotateLeft(pRoot);
            pRoot = rotateRight(pRoot);
        }
    }

    if (balance < -1){
        if (x > pRoot->p_right->key){ //Right-Right
            pRoot = rotateLeft(pRoot);
        }
        else { //Right - Left
            pRoot->p_right = rotateRight(pRoot->p_right);
            pRoot = rotateLeft(pRoot);
        }
    }
}

void Remove(NODE* &pRoot, int x){
    if (!pRoot) return;

    if (x < pRoot->key) Remove(pRoot->p_left, x);
    else if (x > pRoot ->key) Remove(pRoot->p_right, x);
    
    else {
        if (!pRoot->p_left && !pRoot->p_right){
            delete pRoot;
            pRoot = nullptr;
        }
        else if (pRoot->p_left && !pRoot->p_right){
            NODE *q = pRoot;
            pRoot = pRoot->p_left;
            delete q;
        }
        else if (!pRoot->p_left && pRoot->p_right){
            NODE *q = pRoot;
            pRoot = pRoot->p_right;
            delete q;
        }
        else if (pRoot->p_left && pRoot->p_right){
            NODE* maxLeft = pRoot->p_left;
            while (maxLeft->p_right != nullptr) {
                maxLeft = maxLeft->p_right;
            }
            pRoot->key = maxLeft->key; //Dời lên và xóa node cũ ở dưới
            Remove(pRoot->p_left, maxLeft->key);
        }
        return;
    }
    
    updateHeight(pRoot);
    int balance = getNodeHeight(pRoot->p_left) - getNodeHeight(pRoot->p_right);

    if (balance > 1){
        if (getNodeHeight(pRoot->p_left->p_left) >= getNodeHeight(pRoot->p_left->p_right)){ //Left-Left
            pRoot = rotateRight(pRoot); 
    }
    else { //Left-Right
        pRoot->p_left = rotateLeft(pRoot->p_left);
        pRoot = rotateRight(pRoot);
        }
    }
    if (balance < -1){ 
        if (getNodeHeight(pRoot->p_right->p_right) >= getNodeHeight(pRoot->p_right->p_left)){ // Right Left
            pRoot = rotateLeft(pRoot);
        }
    else{ //Right - Left
        pRoot->p_right = rotateRight(pRoot->p_right);
        pRoot = rotateLeft(pRoot);
        }
    }
}
