
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
#include "HuffmanNode.h"
#include <memory> //header file for shared_ptr
#include <queue>
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <cstdlib>

namespace TREE{

    using namespace std;
    //std::shared_ptr<NODE::HuffmanNode> root; //pointer to root node
   // std::unordered_map<char, int> frequencyMap; //holds the frequency of each letter where each letter is the key
   std::unordered_map<char, std::string> codetable;
    HuffmanTree::HuffmanTree(){
        root=nullptr; //initliase root to point at nullptr
    }
    HuffmanTree::~HuffmanTree(){
      root = nullptr; //root node points to nullptr, deletes whole tree
    }


    //special members    
    HuffmanTree::HuffmanTree(HuffmanTree && tree_other):  myQueue(move(tree_other.myQueue)) ,frequencyMap(move(tree_other.frequencyMap)) , root(move(tree_other.root)), codetable(move(tree_other.codetable)){}//move constructor - "steal the pointers of node_other" and breaks old connection
    HuffmanTree::HuffmanTree(HuffmanTree & tree_other): myQueue(tree_other.myQueue) , frequencyMap(tree_other.frequencyMap) , root(tree_other.root), codetable(tree_other.codetable){} //copy constructor
    HuffmanTree & HuffmanTree::operator=(const HuffmanTree & tree_other){ //copy assignment operator
      frequencyMap = tree_other.frequencyMap;
      myQueue = tree_other.myQueue;
      root = nullptr;
      root = tree_other.root;
      return *this; //return reference to the current object
    }
    HuffmanTree & HuffmanTree::operator=(HuffmanTree && tree_other){ //move assignment operator
      frequencyMap = move(tree_other.frequencyMap);
      myQueue = move(tree_other.myQueue);
      root = nullptr;
      root = move(tree_other.root);
      tree_other.root=nullptr; //make other tree's resources null
      return *this; //return reference to the current object
    }

    void HuffmanTree::loadFrequencyMap(std::string filename){ //load text file and populate frequency map
   
    vector<char> characters;
    ifstream in;
    in.open(filename);
    if (!in){
        cerr << "file not found" << endl;
    }else{
        char c=0;
        while(!in.eof()){
         in >> c >> noskipws;
         characters.push_back(c); //put all characters into a vector
        }

        for(const auto&c:characters){
            HuffmanTree::frequencyMap[c]++;
        }
        in.close();
    }
    } 
    void HuffmanTree::loadPriorityQueue(){
        for(auto & pair :frequencyMap){

            NODE::HuffmanNode n(pair.first,pair.second);
            //cout << "-----"<<n.letter <<":"<< n.frequency<<endl;
            myQueue.push(n);
        }

    //     std::priority_queue< ::NODE::HuffmanNode, std::vector< ::NODE::HuffmanNode>, ::compare>  temp =myQueue;

    // while (!temp.empty()) {
    //     cout << "----->>>>>>"<<temp.top().letter <<":"<< temp.top().frequency<<endl;
    //     temp.pop();
    // }
    }
    void HuffmanTree::buildTree(){
        //shared_ptr<NODE::HuffmanNode> letter_ptr = make_shared<NODE::HuffmanNode>;
        while(myQueue.size()>1){
            NODE::HuffmanNode right = myQueue.top(); //left node is smallest
            myQueue.pop(); //discard node which is now stored in left
            NODE::HuffmanNode left = myQueue.top();
            myQueue.pop(); //discard

            int sum = left.frequency+right.frequency;
            NODE::HuffmanNode newNode(0, sum);//new node just has fequency but no character
            newNode.linkLeft = make_shared<NODE::HuffmanNode>(left);
            newNode.linkRight = make_shared<NODE::HuffmanNode>(right);
            myQueue.push(newNode); //push new node onto priority queue
        }
         NODE::HuffmanNode top = myQueue.top(); //last element in queue is root
         root = make_shared<NODE::HuffmanNode>(top);
         myQueue.pop(); //discard last element
        
    }
    
    void HuffmanTree::traverse(std::shared_ptr<NODE::HuffmanNode> r){
        NODE::HuffmanNode node = *r;
        char c = node.letter;
        cout<<node.letter<<":"<<node.frequency<<endl;

        while(node.letter == c ){
        std::shared_ptr<NODE::HuffmanNode>left = node.linkRight; //recurse left
        node = *left;
       }
    }

    void HuffmanTree::createCodeTable(char rootChar,std::shared_ptr<NODE::HuffmanNode> r, std::string bString){
        
        string bitString = bString;
        NODE::HuffmanNode node =*r;
        if(node.letter != rootChar ){
            char c = node.letter;
            codetable[c] = bitString;

        }else{
            createCodeTable(rootChar, node.linkLeft, bitString+"0");
            createCodeTable(rootChar, node.linkRight, bitString+"1");
        }



    }
   


}

 

