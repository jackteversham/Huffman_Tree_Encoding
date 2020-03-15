

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
    cout << "\nFrequency map loaded.";
    int Nbits = 0;
    for(auto & pair :tree.frequencyMap){
        Nbits+=pair.second*8; //cacluate total input bits
        }  
    int inputBytes = (Nbits/8) + (Nbits%8 ? 1 : 0); //takes into account padding bits
    //int inputBytes = tree.characters.size();
    cout << " ---> Size of input file: "<<inputBytes<<" bytes."<< endl;
    tree.loadPriorityQueue();
    cout << "Priority queue loaded.\n";
    tree.buildTree();
    cout << "Huffman Tree built.\n";
    std::shared_ptr<NODE::HuffmanNode> r = tree.root;
    //tree.traverse(r);

    string code = "";
    tree.createCodeTable((*r).letter, r, "");
    cout << "Codetable created.\n\n";

    string outputBitString = "";

     for(auto & pair :tree.codetable){
         outputBitString=outputBitString + pair.second;//cacluate total input bits
        }  
       // cout<< outputBitString;

    //uint bitset    
   // Nbits = outputBitString.length()*8;
    //bytes = (Nbits/8) + (Nbits%8 ? 1 : 0); //takes into account padding bits
    //cout << " ---> Size of file before bit packing: "<<bytes<<" bytes."<< endl;


    // for(const auto&pair:tree.codetable){
    //         cout<<pair.first<<":"<<pair.second<<endl;
    //     }

    string outString = tree.compress(outputFile); //writes huffman enocded strings to output file
    Nbits = outString.length()*8;
    int outputBytes = (Nbits/8) + (Nbits%8 ? 1 : 0); //takes into account padding bits
   // cout << outString<<endl;

    //tree.strToBinary("the quick brown fox jumped over the fence");
    cout<< "Uncompressed output size: "<<outputBytes <<" bytes."<<endl;
    double compressionRatio = (double)inputBytes/(double)outputBytes;
    cout << "Compression ratio before bit packing: "<<compressionRatio<<"x"<<endl;

    ofstream ofs;
    filename = "../output/"+outputFile;
    int n = tree.bitPack(outString,ofs,filename);
    compressionRatio = (double)inputBytes/(double)n;
    cout << "Compression ratio after bit packing: " << compressionRatio<<"x"<<endl;
    cout<< "Bytes written: "<< n <<endl;
    filename = "../output/"+outputFile;
    std::string recoveredString = tree.unpack(filename);
    //cout << recoveredString << endl;


return 0;
}

