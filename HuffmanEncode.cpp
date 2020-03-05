

#include "HuffmanTree.cpp"
#include "HuffmanNode.cpp"

#include <string>
#include <vector>
#include <memory>

using namespace std;
int main(void){
    string filename = "../input/test.txt";
    TREE::HuffmanTree tree;
    tree.loadFrequencyMap(filename);
    tree.loadPriorityQueue();
    tree.buildTree();
    std::shared_ptr<NODE::HuffmanNode> r = tree.root;
    tree.traverse(r);
return 0;
}