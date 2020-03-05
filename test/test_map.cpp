#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"


#include "../HuffmanTree.cpp"
#include "../HuffmanNode.cpp"

#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>

// unsigned int Factorial( unsigned int number ) {
//     return number <= 1 ? number : Factorial(number-1)*number;
// }
using namespace std;

TREE::HuffmanTree tree; //create tree instance on the stack

TEST_CASE( "FREQUENCY MAP IS BUILT", "[loadFrequencyMap]" ) {

    

    SECTION("Testing frequency map character frequencies for known input of characters and their frequencies"){

    
    tree.loadFrequencyMap("../../input/test.txt");
   // std::unordered_map<char, int> tree.frequencyMap = tree.frequencyMap; //holds the frequency of each letter where each letter is the key

    REQUIRE( tree.frequencyMap['c'] == 2 );
    REQUIRE( tree.frequencyMap['t'] == 2 );
    REQUIRE( tree.frequencyMap['i'] == 1 );
    REQUIRE( tree.frequencyMap[' '] == 7 );
    REQUIRE( tree.frequencyMap['e'] == 6 );
    REQUIRE( tree.frequencyMap['b'] == 1 );
    REQUIRE( tree.frequencyMap['q'] == 1 );
    REQUIRE( tree.frequencyMap['u'] == 2 );
    REQUIRE( tree.frequencyMap['k'] == 1 );
    REQUIRE( tree.frequencyMap['r'] == 2 );
    REQUIRE( tree.frequencyMap['o'] == 3 );
    REQUIRE( tree.frequencyMap['w'] == 1 );
    REQUIRE( tree.frequencyMap['n'] == 2 );
    REQUIRE( tree.frequencyMap['f'] == 2 );
    REQUIRE( tree.frequencyMap['\n'] == 2 );
    REQUIRE( tree.frequencyMap['x'] == 1 );
    REQUIRE( tree.frequencyMap['j'] == 1 );
    REQUIRE( tree.frequencyMap['m'] == 1 );
    REQUIRE( tree.frequencyMap['p'] == 1 );
    REQUIRE( tree.frequencyMap['d'] == 1 );
    REQUIRE( tree.frequencyMap['v'] == 1 );
    REQUIRE( tree.frequencyMap['h'] == 2 );
    } 

    SECTION("PRIORITY QUEUE SHOULD HAVE SMALLEST FREQUENCY AT TOP AND BIGGEST AT BOTTOM"){
        //TREE::HuffmanTree tree; //create tree instance on the stack
        tree.loadFrequencyMap("../../input/test.txt");
        tree.loadPriorityQueue();

        NODE::HuffmanNode node = tree.myQueue.top();
    
        REQUIRE(node.frequency == 1);
        while(tree.myQueue.size()>1){
            tree.myQueue.pop(); //discard all but last annd check if it has the highest frequency
        }
        REQUIRE(tree.myQueue.top().frequency==7);
        REQUIRE(tree.myQueue.top().letter==' ');
    }
}



TEST_CASE( "TESTING HUFFMAN TREE BUILD", "[buildTree]" ) {
    //TREE::HuffmanTree tree; //create tree instance on the stack
    tree.loadFrequencyMap("../../input/test.txt");
    tree.loadPriorityQueue();
    tree.buildTree();

    NODE::HuffmanNode node = *(tree.root);
    std::shared_ptr<NODE::HuffmanNode>left = node.linkLeft;
    std::shared_ptr<NODE::HuffmanNode> right = node.linkRight;

    NODE::HuffmanNode leftNode = *left;
    NODE::HuffmanNode rightNode = *right;

   // cout<<node.frequency<<endl;

   SECTION("root node frequency should be = to the sum off all the characters' frequencies"){
       int sum =0;
       for(const auto& pair:tree.frequencyMap){
           sum+=pair.second;
       }
        REQUIRE(node.frequency == (sum));

    }

    SECTION("root node frequency should be the sum of its children"){
        REQUIRE(node.frequency == (leftNode.frequency+rightNode.frequency));

    }

   SECTION("Right most node holds the lowest frequency"){ 
       char c = node.letter; //the root node
       while(node.letter == c){
        std::shared_ptr<NODE::HuffmanNode>right = node.linkRight; //recurse left
        node = *right;
       }
    
      REQUIRE(node.frequency == 1);
     

  }
}

TEST_CASE("Testing codetable string accuracy", "[createCodetable]"){
    //TREE::HuffmanTree tree; //create tree instance on the stack
    tree.loadFrequencyMap("../../input/test.txt");
    tree.loadPriorityQueue();
    tree.buildTree();
    NODE::HuffmanNode node = *(tree.root);
    string code = "";
    tree.createCodeTable(node.letter, tree.root, code);

    

    SECTION("Left most node has the lowest code - all zeros"){ 
        char c = node.letter; //the root node
       while(node.letter == c){
        std::shared_ptr<NODE::HuffmanNode>left = node.linkLeft; //recurse left
        node = *left;
       }
       string code = tree.codetable[node.letter];
       for(int i = 0; i<code.length(); i++){
          REQUIRE(code[i] == '0');
       }
      
    
  }

  SECTION("Right most node has the highest code - all 1s"){ 
        char c = node.letter; //the root node
       while(node.letter == c){
        std::shared_ptr<NODE::HuffmanNode>right = node.linkRight; //recurse left
        node = *right;
       }
       string code = tree.codetable[node.letter];
     for(int i = 0; i<code.length(); i++){
          REQUIRE(code[i] == '1');
       }
  }
  
}