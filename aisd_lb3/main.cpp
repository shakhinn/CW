#include "Tree.h"
#include "InOut.h"

int main (int argc, char** argv){
    string input = cuinput(argc, argv);
    if(input.empty()){
        cout<<"ERROR";
        return 0;
    }
    string copy = string(input);
    int pos = 0;
    BinaryTree tree = BinaryTree(copy, pos);
    if(tree.checkBST()){
        cout<<"BST\n";
    } else if(tree.checkPiramid()){
        cout<<"piramid\n";
    } else cout<<"noooo\n";
}
