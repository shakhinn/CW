#include "Tree.h"
#include "InOut.h"


BinaryTree::BinaryTree(string &str, int &pos) {
    tree = scanTree(str, pos);
}

BinaryTree::~BinaryTree() {
    destroy(this->tree);
}

void BinaryTree::skip(string& str, int& pos, int n){
    if (str.length() >= n) {
        str = str.substr(n);
        pos++;
    }
}
int BinaryTree::getNum(string& str, int& pos){
    string strNum;
    while (isdigit(str[0]) || (strNum.length() == 0 && str[0] == '-')) {
        strNum += str[0];
        skip(str, pos, 1);
    }
    return stoi(strNum);
}

Node *BinaryTree::scanTree(string& str, int& pos) {
    if(str[0] == '(') {
        skip(str, pos, 1);
        if(str[0] == ')') {
            skip(str, pos, 1);
            return nullptr;
        }
        Node *buf = new Node();
        buf->setData(getNum(str, pos));
        if(str[0] == ')'){
            skip(str, pos, 1);
            buf->setLeft(nullptr);
            buf->setRight(nullptr);
            return buf;
        }
        if(str[0] == '('){
            buf->setLeft(scanTree(str, pos));
            if(str[0] == '('){
                buf->setRight(scanTree(str, pos));
                if(str[0]== ')') {
                    skip(str, pos, 1);
                    return buf;
                } else cout<<"error";
            }else if(str[0]== ')'){
                skip(str, pos, 1);
                return buf;
            }

        }

    }
    else{ cout<<"error";}
    return nullptr;
}

void BinaryTree::destroy(Node*& buf){
    if(buf != nullptr) {
        Node* left = buf->getLeft();
        Node* right = buf->getRight();
        destroy(left);
        destroy(right);
        delete buf;
    }
}

bool BinaryTree::checkBST(){
    if(tree != nullptr){
        if(checkBst_left(tree->getLeft(), MIN, tree->getData()) && checkBst_right(tree->getRight(), tree->getData(), MAX))
            return true;
        else return false;
    }
    return false;
}

bool BinaryTree::checkBst_left(Node* node, int min, int max){
    if(node != nullptr){
        if(node->getData() > min && node->getData() < max){
            int old_max = max;
            max = node->getData();
            int old_min = min;
            min = node->getData();
            if(checkBst_left(node->getLeft(), old_min, max) && checkBst_right(node->getRight(), min, old_max)){
                return true;
            } else return false;
        } else return false;
    }
    return true;
}
bool BinaryTree::checkBst_right(Node* node, int min, int max){
    if(node != nullptr){
        if(node->getData() > min && node->getData() < max){
            int old_max = max;
            max = node->getData();
            int old_min = min;
            min = node->getData();
            if(checkBst_left(node->getLeft(), old_min, max) && checkBst_right(node->getRight(), min, old_max)){
                return true;
            } else return false;
        } else return false;
    }
    return true;

}

bool BinaryTree::checkPiramid(){
    if(tree!= nullptr){
        if(checkPirapid_leaf(tree->getLeft(), tree->getData()) && checkPirapid_leaf(tree->getRight(), tree->getData())){
            return true;
        } else return false;
    }
    return false;
}

bool BinaryTree::checkPirapid_leaf(Node* node, int max){
    if(node != nullptr){
        if(node->getData() <= max){
            max = node->getData();
            if(checkPirapid_leaf(node->getLeft(), max) && checkPirapid_leaf(node->getRight(), max)) {
                return true;
            } else return false;
        } else return false;
    }
    return true;
}
