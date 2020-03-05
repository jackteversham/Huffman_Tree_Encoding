

#include "HuffmanTree.cpp"
#include "HuffmanNode.cpp"

#include <string>
#include <vector>
#include <memory>

using namespace std;
int main(int argc, char ** argv){
    string inputFile = argv[1];
    string outputFile = argv[2];
    string filename = ("../input/"+inputFile+".txt");
    TREE::HuffmanTree tree;
    tree.loadFrequencyMap(filename);
    tree.loadPriorityQueue();
    tree.buildTree();
    std::shared_ptr<NODE::HuffmanNode> r = tree.root;
    tree.traverse(r);
    string code = "";
    tree.createCodeTable((*r).letter, r, "");
    // for(const auto&pair:tree.codetable){
    //         cout<<pair.first<<":"<<pair.second<<endl;
    //     }

    tree.compress(outputFile);
return 0;
}