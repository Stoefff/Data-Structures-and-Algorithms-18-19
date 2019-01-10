#include <iostream>
#include <vector>
#include <queue>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::queue;
using std::string;

struct Node{
    int value;
    Node* left;
    Node* right;

    Node(int value, Node* left = nullptr, Node* right = nullptr)
        :value(value), left(left), right(right){
    }

};

void bst_insert(Node*& root, int val){
    if (root == nullptr){
        root = new Node(val);
        return;
    }
    if (root->value == val){
        return; // Do nothing
    }
    if (root->value > val){
        bst_insert(root->left, val);
        return;
    }
    if (root->value < val){
        bst_insert(root->right, val);
        return;
    }
}

void bst_clear(Node*& root){
    if(root == nullptr){
        return;
    }
    bst_clear(root->left);
    bst_clear(root->right);
    delete root;
}

void print_bst_lrr(Node* root){
    if(root == nullptr){
        return;
    }
    print_bst_lrr(root->left);
    std::cout << " " << root->value << " ";
    print_bst_lrr(root->right);
}

// Pass begin and end index
void build_bst(Node*& root, vector<int>& arr){
    //
}

// More uncached cases
vector<Node*> calculatePath(Node* root, int val){
    vector<Node*> path;
    if (root->value == val){
        path.push_back(root);
        return path;
    }
    if (root->value < val){
        vector<Node*> path = calculatePath(root->left, val);
        path.insert(path.begin(), root);
        return path;
    }
    if (root->value > val){
        vector<Node*> path = calculatePath(root->right, val);
        path.insert(path.begin(), root);
        return path;
    }
}


Node* findPrevRec(Node* root, int val, queue<Node*>& wave, Node* prev = nullptr){
        if (wave.empty()){
            return nullptr;
        }
        if (root->value == val){
            return prev;
        }
        if (root->left){
            wave.push(root->left);
        }
        if (root->right){
            wave.push(root->right);
        }
        prev = wave.front();
        wave.pop();
        return findPrevRec(wave.front(), val, wave, prev);

}

Node* findPrev(Node* root, int val){
    queue<Node*> wave;
    wave.push(root);
    return findPrevRec(wave.front(), val, wave);
}

struct node {
    std::string studentName;
    node* next;

    node(string name, node* next = nullptr)
        :studentName(name), next(next){
    }

  };

 struct nameList {
     node* begin;
     node* end;
 };

 void list_push_back(node* student){
     // TO be continue
 }

int main() {

/*  Task 1
    vector<int> arr = {1, 3, 5, 6, 7, 9};
    Node* root = new Node(arr[0]);
    build_bst(root, arr);
    print_bst_lrr(root);
    bst_clear(root);
*/

// Task 3
/*
    Node* root = new Node(6);
    bst_insert(root, 4);
    bst_insert(root, 11);
    bst_insert(root, 2);
    bst_insert(root, 5);
    bst_insert(root, 8);


    print_bst_lrr(root);
    cout << endl;

    Node* prevNode = findPrev(root, 2);
    cout << prevNode->value << endl;

    bst_clear(root);
*/

    return 0;
}
