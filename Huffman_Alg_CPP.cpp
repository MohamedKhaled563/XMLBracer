#include<iostream>
#include<unordered_map>
#include<queue>
#include <fstream>
#include<windows.h>
#include <sstream>
//#include<mainwindow.h>
using namespace std;
struct ourNode {
    char Ch;
    int Freq;
    ourNode* Left;
    ourNode* Right;
    ourNode(char ch, int freq, ourNode* left, ourNode* right) {
        Ch = ch;
        Freq = freq;
        Left = left;
        Right = right;
    }
};

struct Compare {
    bool operator()(ourNode* Left, ourNode* Right) {
        return Left->Freq > Right->Freq;
    }
};

ourNode* CreateOurNode(char ch, int freq, ourNode* left, ourNode* right) {
    ourNode* NewNode = new ourNode(ch, freq, left, right);
    return NewNode;
}

void Encoding(ourNode* Root, string Str, unordered_map<char, string>& HuffmanCode) {
    if (Root == nullptr) {
        return;
    }

    if (!Root->Left && !Root->Right) {
        HuffmanCode[Root->Ch] = Str;
    }
    Encoding(Root->Left, Str + '0', HuffmanCode);
    Encoding(Root->Right, Str + '1', HuffmanCode);
}
string BuildHuffmanTree(string Text) {
    unordered_map<char, int> FreqOfChars;
    for (char ch : Text) {
        FreqOfChars[ch]++;
    }

    priority_queue<ourNode*, vector<ourNode*>, Compare> HuffmanTree;
    for (auto pair : FreqOfChars) {
        HuffmanTree.push(CreateOurNode(pair.first, pair.second, nullptr, nullptr));
    }

    while (HuffmanTree.size() != 1) {

        ourNode* Left = HuffmanTree.top();
        HuffmanTree.pop();

        ourNode* Right = HuffmanTree.top();
        HuffmanTree.pop();

        int SUM = Left->Freq + Right->Freq;
        HuffmanTree.push(CreateOurNode('\0', SUM, Left, Right));
    }

    ourNode* Root = HuffmanTree.top();
    unordered_map<char, string> HuffmanCodes;
    Encoding(Root, "", HuffmanCodes);
    string Str = "";
    for (char Ch : Text) {
        Str += HuffmanCodes[Ch];
    }
    return Str;
}
int main()
{
    ifstream ReadFile("HuffInp.txt");
    stringstream buffer;
    buffer << ReadFile.rdbuf();
    string readData(buffer.str());
    ReadFile.close();
    string output = BuildHuffmanTree(readData);
    ofstream writeData;
    writeData.open("HuffRes.txt");
    writeData << output;
    writeData.clear();
    writeData.close();
    return 0;
}