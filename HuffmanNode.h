
#include <memory>

#ifndef HTREE_NODE
#define HTREE_NODE

namespace NODE{
class HuffmanNode{
public:
    char letter; //holds letter
    int frequency; //holds the frequency of coccurence of above letter   
    std::shared_ptr<NODE::HuffmanNode> linkLeft; //smart shared pointers used as left and right links for tree nodes
    std::shared_ptr<NODE::HuffmanNode> linkRight;

    HuffmanNode(char l, int f); //default constructor
    ~HuffmanNode(); //destructor
    

    //move constructor
    //copy constructor
    //assignment operator
    //move assignment operator

};
}
#endif