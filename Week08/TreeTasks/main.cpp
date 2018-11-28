#include <iostream>
#include <fstream>

using namespace std;

struct node{
    int value;
    node* leftNode;
    node* rightNode;

    node(int value, node* newLeftNode = nullptr, node* newRightNode = nullptr)
        :value(value), leftNode(newLeftNode), rightNode(newRightNode){
    }
};

void insert(node*& root, int val){
    if (root == nullptr){
        root = new node(val);
    } if (root->value > val){
        insert(root->leftNode, val);
    } else if(root->value < val){
        insert(root->rightNode, val);
    }
}

void printAsc(node* root){
    if(root->leftNode != nullptr)
        printAsc(root->leftNode);
    cout << root->value << " ";
    if (root->rightNode != nullptr)
        printAsc(root->rightNode);
}

void printDesc(node* root){
    if (root->rightNode != nullptr)
        printDesc(root->rightNode);
    cout << root->value << " ";
    if(root->leftNode != nullptr)
        printDesc(root->leftNode);
}

void clean(node*& root){
    if(root->leftNode != nullptr)
        clean(root->leftNode);
    delete root;
    if (root->rightNode != nullptr)
        clean(root->rightNode);
}

int main(int argc, char* argv[]){

    const char* buffer = argv[1];
    ifstream file (buffer, ios::in);
    if(!file.good()){
        cerr << buffer << " write stream failed!" << endl;
        return -1;
    }
    int val = 0;
    file >> val;
    node* root = new node(val);
    while (!file.eof()){
        int val = 0;
        file >> val;
        insert(root, val);
    }
    /*
    node* root = new node(5);
    insert(root, 2);
    insert(root, 10);
    insert(root, 1);
    insert(root, 3);
    insert(root, 4);
    insert(root, 7);
    insert(root, 8);
    insert(root, 13);
    */
    printAsc(root);
    cout << endl;
    printDesc(root);
    clean(root);

    return 0;
}
