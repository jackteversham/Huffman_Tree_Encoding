
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

    //special members    
    HuffmanNode(HuffmanNode && node_other); //move constructor - "steal the pointers of node_other"
    HuffmanNode(const HuffmanNode & node_other); //copy constructor
    HuffmanNode & operator=(const HuffmanNode & node_other); //assignment operator
    HuffmanNode & operator=(HuffmanNode && node_other);//move assignment operator

};
}
#endif