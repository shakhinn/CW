#ifndef AISD_LB3_TREE_H
#define AISD_LB3_TREE_H

#include "Node.h"
#include "structs.h"
#define MIN -30000
#define MAX 30000

class BinaryTree{
public:
    BinaryTree(string& str, int& pos);
    bool checkBST();
    bool checkPiramid();
    ~BinaryTree();

private:
    Node* tree;
    void skip (string& str, int& pos, int n = 1);
    int getNum(string& input, int& pos);
    Node* scanTree(string& str, int& pos);
    void destroy(Node*& buf);

    bool checkBst_left(Node* node, int min = MIN , int max = MAX);
    bool checkBst_right(Node* node, int min = MIN, int max = MAX);

    bool checkPirapid_leaf(Node* node, int max);

};







#endif //AISD_LB3_TREE_H
