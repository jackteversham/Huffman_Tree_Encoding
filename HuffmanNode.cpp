/*
This class represents the tree nodes in the underlying huffmanTree
*/
#include "HuffmanNode.h"
#include <memory>
namespace NODE{

    char letter; //holds letter
    int frequency; //holds the frequency of coccurence of above letter  
   
    std::shared_ptr<HuffmanNode> linkLeft; //smart shared pointers used as left and right links for tree nodes
    std::shared_ptr<HuffmanNode> linkRight;

    HuffmanNode::HuffmanNode(char l, int f){
        letter = l; frequency=f;
    }


}