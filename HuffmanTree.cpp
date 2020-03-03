
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
#include <queue>
#include <string>

namespace TREE{

    using namespace std;
    std::shared_ptr<NODE::HuffmanNode> root; //pointer to root node
    HuffmanTree::HuffmanTree(unordered_map<char, int> map){
        root=nullptr; //initliase root to point at nullptr
        frequencyMap = map;
    }
    HuffmanTree::~HuffmanTree(){
      root = nullptr; //root node points to nullptr, deletes whole tree
    }

    //special members    
    HuffmanTree::HuffmanTree(HuffmanTree && tree_other): frequencyMap(move(tree_other.frequencyMap)), queue(move(tree_other.queue)), root(move(tree_other.root)){}//move constructor - "steal the pointers of node_other" and breaks old connection
    HuffmanTree::HuffmanTree(HuffmanTree & tree_other): frequencyMap(tree_other.frequencyMap), queue(tree_other.queue), root(tree_other.root){} //copy constructor
    HuffmanTree & HuffmanTree::operator=(const HuffmanTree & tree_other){ //copy assignment operator
      frequencyMap = tree_other.frequencyMap;
      queue = tree_other.queue;
      root = nullptr;
      root = tree_other.root;
      return *this; //return reference to the current object
    }
    HuffmanTree & HuffmanTree::operator=(HuffmanTree && tree_other){ //move assignment operator
      frequencyMap = move(tree_other.frequencyMap);
      queue = move(tree_other.queue);
      root = nullptr;
      root = move(tree_other.root);
      tree_other.root=nullptr; //make other tree's resources null
      return *this; //return reference to the current object
    }

    void loadFrequencyMap(string filename){ //load text file and populate frequency map
      

    } 
    void loadPriorityQueue(){}
    void buildTree(){}
   


}

 

