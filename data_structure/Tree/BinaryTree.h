#include<iostream>
#include<queue>
#include<stack>
#include<initializer_list>
using namespace std;

struct BinaryTree {
    BinaryTree() = default;
    BinaryTree(initializer_list<int>);
    BinaryTree(const BinaryTree&);
    BinaryTree(BinaryTree&&);
    BinaryTree& operator=(initializer_list<int>);

    void visitFR();
    void visitMR();
    void visitLR();

    void visitFST();
    void visitMST();
    void visitLST();
private:
    struct Node {
        Node(Node* left, Node* right, int val): left(left), right(right), val(val) {}
        Node(int val): val(val) {}

        Node* left = nullptr, * right = nullptr;
        int val = 0;
    };

    Node* root = nullptr;

    void build(Node*&, const Node*);

    void visitFR(Node*);
    void visitMR(Node*);
    void visitLR(Node*);
};


struct ThreadTree {
    ThreadTree() = default;
    ThreadTree(initializer_list<int>);
    ThreadTree& operator=(initializer_list<int>);
    
    void visit();
private:
    struct Node {
        Node(Node* left, Node* right, int val): left(left), right(right), val(val) {}
        Node(int val): val(val) {}
        Node() = default;

        Node* left = nullptr, * right = nullptr;
        bool lF = 0, rF = 0;
        int val = 0;
    };

    Node* root = nullptr;

    void build(Node*, Node*&);
    Node* findFirst(Node*);
    Node* findNext(Node*);
};