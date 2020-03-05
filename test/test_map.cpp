#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "../HuffmanTree.h"
#include "../HuffmanNode.h"
#include "../HuffmanTree.cpp"
#include "../HuffmanNode.cpp"

#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

// unsigned int Factorial( unsigned int number ) {
//     return number <= 1 ? number : Factorial(number-1)*number;
// }
using namespace std;



TEST_CASE( "FREQUENCY MAP IS BUILT", "[loadFrequencyMap]" ) {

    // vector<char> characters;
    // std::ifstream in;
    // in.open("../../input/test.txt");
    // if (!in){
    //     cout << "file not found" << endl;
    // }else{
    //     char c=0;
    //     while(!in.eof()){
    //      in >> c >> noskipws;
    //      characters.push_back(c); //put all characters into a vector
    //     }
    //     for(const auto& c:characters){
    //         fmap[c]++;
    //     }
        
    // }

    SECTION("Testing frequency map character frequencies for known input of characters and their frequencies"){

    TREE::HuffmanTree tree; //create tree instance on the stack
    tree.loadFrequencyMap("../../input/test.txt");
    std::unordered_map<char, int> fmap = tree.frequencyMap; //holds the frequency of each letter where each letter is the key

    REQUIRE( fmap['c'] == 2 );
    REQUIRE( fmap['t'] == 2 );
    REQUIRE( fmap['i'] == 1 );
    REQUIRE( fmap[' '] == 7 );
    REQUIRE( fmap['e'] == 6 );
    REQUIRE( fmap['b'] == 1 );
    REQUIRE( fmap['q'] == 1 );
    REQUIRE( fmap['u'] == 2 );
    REQUIRE( fmap['k'] == 1 );
    REQUIRE( fmap['r'] == 2 );
    REQUIRE( fmap['o'] == 3 );
    REQUIRE( fmap['w'] == 1 );
    REQUIRE( fmap['n'] == 2 );
    REQUIRE( fmap['f'] == 2 );
    REQUIRE( fmap['\n'] == 2 );
    REQUIRE( fmap['x'] == 1 );
    REQUIRE( fmap['j'] == 1 );
    REQUIRE( fmap['m'] == 1 );
    REQUIRE( fmap['p'] == 1 );
    REQUIRE( fmap['d'] == 1 );
    REQUIRE( fmap['v'] == 1 );
    } 
}

TEST_CASE( "TESTING HUFFMAN TREE BUILD", "[buildTree]" ) {
  SECTION("root node frequency should be the sum of its children"){

  }


}