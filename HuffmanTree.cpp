
//HuffmanTree class
/*
This class serves to manage the tree and contains methods to BUILD, MANIPULATE, and COMPRESS the tree.
The tree is a Binary tree where the parent is always greater than its children

    parent holds sum of children frequncies 
              /    \
             /      \
            /        \
 left child freq   right child freq


*/
#include "HuffmanTree.h"
#include <memory> //header file for shared_ptr

namespace TREE{

    std::shared_ptr<NODE::HuffmanNode> root; //pointer to root node

    HuffmanTree::~HuffmanTree(){
      root = nullptr; //root node points to nullptr, deletes whole tree
    }

}

 

