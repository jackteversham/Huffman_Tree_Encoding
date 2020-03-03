
#include <memory>
#include <queue>
#include <unordered_map>
#include <vector>
#include "HuffmanNode.h"

#ifndef HTREE_H
#define HTREE_H 

struct compare{
    bool operator() (const NODE::HuffmanNode& a, const NODE::HuffmanNode& b ){ //compare function to ensure funcitonality of priority queue
        if(a.frequency > b.frequency){
            return true;
        }else{
            return false;
        }
    }
};
namespace TREE{
class HuffmanTree{
private:
    std::unordered_map<char, int> frequencyMap; //holds the frequency of each letter where each letter is the key
    std::priority_queue<NODE::HuffmanNode, std::vector<NODE::HuffmanNode>, ::compare> queue; //priority queue to order the nodes according to their frequency to help with tree building
public:  
    std::shared_ptr<NODE::HuffmanNode> root; //pointer to the root node of the tree

    HuffmanTree(std::unordered_map<char, int> map); //default constructor
    ~HuffmanTree(); //defualt destructor

    //special members    
    HuffmanTree(HuffmanTree && tree_other); //move constructor - "steal the pointers of node_other"
    HuffmanTree(HuffmanTree & tree_other); //copy constructor
    HuffmanTree & operator=(const HuffmanTree & tree_other); //assignment operator
    HuffmanTree & operator=(HuffmanTree && tree_other);//move assignment operator

    void loadFrequencyMap(); //load text file and populate frequency map
    void loadPriorityQueue();
    void buildTree();

};
}
#endif