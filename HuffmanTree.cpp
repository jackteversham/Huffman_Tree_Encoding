
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
   vector<char> characters; //holds each character of input file


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

    void HuffmanTree::loadFrequencyMap(const std::string filename){ //load text file and populate frequency map
    characters.clear();
    frequencyMap.clear();
    
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
        //empty the priority queue for testing purposes
        while (!myQueue.empty()) {
            myQueue.pop();
        }
        for(auto & pair :frequencyMap){

            NODE::HuffmanNode n(pair.first,pair.second);
          //cout << "---"<<n.letter <<":"<< n.frequency<<endl;
            myQueue.push(n);
        }

      //  std::priority_queue< ::NODE::HuffmanNode, std::vector< ::NODE::HuffmanNode>, ::compare>  temp =myQueue;
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
        //cout<<node.letter<<":"<<node.frequency<<endl;

        while(node.letter == c ){
        std::shared_ptr<NODE::HuffmanNode>right = node.linkRight; //recurse left
        node = *right;
       }
       //cout <<node.frequency<<endl;
    }

    void HuffmanTree::createCodeTable(const char rootChar,std::shared_ptr<NODE::HuffmanNode> r, std::string bString){
        string bitString = bString;
        NODE::HuffmanNode node =*r;
        if(node.letter != rootChar ){
            char c = node.letter;
            codetable[c] = bitString;

        }else{
            createCodeTable(rootChar, node.linkLeft, bitString+"0"); //recursive call
            createCodeTable(rootChar, node.linkRight, bitString+"1");
        }
    }

    std::string HuffmanTree::compress(const std::string filename){
       ofstream out;
       out.open("../output/"+filename+".txt");
        std::string outString = "";
        for(const auto& c: characters){
            outString = outString+codetable[c];
        }
        out.write(outString.c_str(), outString.length());
        out.close();
        //cout << outString <<endl;

        out.open("../output/"+filename+".hdr");
        //outString = "";
        out << "field count: "<<codetable.size()<<"\n";
        for( auto& pair: codetable){
            //outString = pair.first+": "+pair.second+"\n";
            out << pair.first<<':'<<pair.second<<'\n';
        }
        
        out.close();
        return outString;
    }
    string HuffmanTree::strToBinary(string s) 
    {    
    std::string bin = "";     
    int n = s.length(); 
    for (int i = 0; i <= n; i++) 
    { 
        // convert each char to 
        // ASCII value 
        int val = int(s[i]); 
  
        // Convert ASCII value to binary 
        bin = ""; 
        while (val > 0) 
        { 
            (val % 2)? bin.push_back('1') : 
                       bin.push_back('0'); 
            val /= 2; 
        } 
        reverse(bin.begin(), bin.end()); 
  
       // cout << bin ; 
        //cout <<bin[0];
    } 
    return bin;
} 

int HuffmanTree::bitPack(std::string outputBits, std::ofstream &ofs, std::string filename){
            ofs.open(filename, ios::binary);
            //../output/"+filename+"Binary"
    
            int length = outputBits.length();
            for (auto i = 0; i < length; i+=8){
                unsigned char byte = 0;
                std::string byteString = "";
                if(i+8 < length){byteString = outputBits.substr(i, i+8);} //take 1 byte chunks of the output bit buffer
                else{byteString = outputBits.substr(i, length);}
                for(unsigned b = 0; b != 8; ++b){ //loop through each bit of the string of bits
                    if(b<byteString.length()){
                        byte |= (byteString[b]&1) << b; //and with 1 and shift left by b
                    }
                    else{
                        byte |= 1 << b; //bitwise operations to pack
                     }
                }
                ofs.put(byte);
            }
            int outputPosition = ofs.tellp();
            int bytesWritten = outputPosition+1;
            //cout << bytesWritten << endl;
            ofs.close();

            ofs.open("../output/"+filename+"BinaryHeader.hdr", ios::binary);
            ofs << bytesWritten*8;
            ofs.close();
            return bytesWritten;
}

std::string HuffmanTree::unpack(std::string filename){
            std::string recoveredString = "";
            ifstream ifs;

            ifs.open(filename+"BinaryHeader.hdr");
            if (!ifs){
                return "File not found";
            }
            int bits=0;
            ifs >> bits;
            ifs.close();

            ifs.open(filename+"Binary", ios::binary);
            //std::string buffer;
             char buffer[bits/8];
            ifs.read(buffer, sizeof(buffer));
           // ifs >> buffer; //load bits into string buffer
            //cout << buffer<<endl;
            bitset<8> byte;
            std::string bitstring;

            for(int i=0; i <bits/8; i++){ //loop number of bytes times
                byte = buffer[i];
                bitstring = byte.to_string();
                std::string reverse;
                for(int j = bitstring.length()-1; j>=0; j--){ //reverse the string and add to the final string
                    reverse +=bitstring[j];
                }
                recoveredString += reverse;
            }
        return recoveredString;


}
   
}

 

