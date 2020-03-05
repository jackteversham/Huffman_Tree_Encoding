/*
This class represents the tree nodes in the underlying huffmanTree
*/
#include "HuffmanNode.h"
#include <memory>
#include <vector>
namespace NODE{

    char letter; //holds letter
    int frequency; //holds the frequency of coccurence of above letter  
   
    std::shared_ptr<HuffmanNode> linkLeft; //smart shared pointers used as left and right links for tree nodes
    std::shared_ptr<HuffmanNode> linkRight;

   
    HuffmanNode::HuffmanNode(char l, int f){
        letter = l; 
        frequency=f;
    }
    HuffmanNode::~HuffmanNode(){}

    HuffmanNode::HuffmanNode(const HuffmanNode & node_other):letter(node_other.letter), frequency(node_other.frequency), linkLeft(node_other.linkLeft), linkRight(node_other.linkRight){} //copy constructor
    HuffmanNode::HuffmanNode(HuffmanNode && node_other): letter(std::move(node_other.letter)), frequency(std::move(node_other.frequency)), linkLeft(std::move(node_other.linkLeft)), linkRight(std::move(node_other.linkRight)){//move constructor - "steal the pointers of node_other"
        node_other.letter = 0;  //move connectino to new pointer and make old connection null
        node_other.frequency = 0;
    } 
    HuffmanNode & HuffmanNode::operator=(const HuffmanNode & node_other){ //copy assignment operator
        letter = node_other.letter;
        frequency = node_other.frequency;
        linkLeft = nullptr;
        linkRight = nullptr;
        linkLeft = node_other.linkLeft;
        linkRight = node_other.linkRight;
        return *this; //return pointer to this object
    } 
    //move assignment operator
    HuffmanNode & HuffmanNode::operator=(HuffmanNode && node_other){ //copies to new object and nullifies old connection
        letter = node_other.letter;
        frequency = node_other.frequency;
        linkLeft = nullptr;
        linkRight = nullptr;
        linkLeft = move(node_other.linkLeft);
        linkRight = move(node_other.linkRight);
        node_other.letter = 0;
        node_other.frequency = 0;
        return *this; //return pointer to this object

    }
    
}