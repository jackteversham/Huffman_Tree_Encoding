

#include "HuffmanTree.cpp"
#include "HuffmanNode.cpp"

#include <string>
#include <vector>

using namespace std;
int main(void){
    string filename = "../input/test.txt";
    TREE::HuffmanTree tree;
    tree.loadFrequencyMap(filename);
    tree.loadPriorityQueue();
    tree.buildTree();
   
return 0;
}