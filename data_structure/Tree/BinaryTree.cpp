#include"BinaryTree.h"

BinaryTree& BinaryTree::operator=(initializer_list<int> v) {
    if (!v.size()) return *this;
    auto t = v.begin();
    root = new Node(*t);
    t++;
    queue<Node*> q({root});
    while (1) {
        Node* p = q.front();  q.pop();
        p->left = new Node(*t);
        t++;
        if (t == v.end()) break;
        q.push(p->left);
        
        p->right = new Node(*t);
        t++;
        if (t == v.end()) break;
        q.push(p->right);
    }
    return *this;
}
BinaryTree::BinaryTree(initializer_list<int> v) {
    if (!v.size()) return;
    auto t = v.begin();
    root = new Node(*t);
    t++;
    queue<Node*> q({root});
    while (1) {
        Node* p = q.front();  q.pop();
        p->left = new Node(*t);
        t++;
        if (t == v.end()) break;
        q.push(p->left);
        
        p->right = new Node(*t);
        t++;
        if (t == v.end()) break;
        q.push(p->right);
    }
}
void BinaryTree::build(Node*& p, const Node* q) {
    if (!q) return;
    p = new Node(q->val);
    build(p->left, q->left);
    build(p->right, q->right);
}
BinaryTree::BinaryTree(const BinaryTree& other) {
    build(root, other.root);
}
BinaryTree::BinaryTree(BinaryTree&& other) {
    root = other.root;
    other.root = nullptr;
}

void BinaryTree::visitFR(Node* p) {
    if (!p) return;
    cout << p->val << endl;
    visitFR(p->left);  visitFR(p->right);
}
void BinaryTree::visitFR() {
    visitFR(root);
}

void BinaryTree::visitMR(Node* p) {
    if (!p) return;
    visitMR(p->left);  
    cout << p->val << endl;
    visitMR(p->right);
}
void BinaryTree::visitMR() {
    visitMR(root);
}

void BinaryTree::visitLR(Node* p) {
    if (!p) return;
    visitLR(p->left);  
    visitLR(p->right);
    cout << p->val << endl;
}
void BinaryTree::visitLR() {
    visitLR(root);
}

void BinaryTree::visitFST() {
    stack<Node*> st;
    Node* p = root;
    while (p || st.size()) {
        while (p) {
            cout << p->val << endl;
            st.push(p);
            p = p->left;
        }
        p = st.top()->right;  st.pop();
    }
}
void BinaryTree::visitMST() {
    stack<Node*> st;
    Node* p = root;
    while (p || st.size()) {
        while (p) {
            st.push(p);
            p = p->left;
        }
        p = st.top();  st.pop();
        cout << p->val << endl;
        p = p->right;
    }
}
void BinaryTree::visitLST() {
    stack<Node*> st;
    Node* p = root, * pre = nullptr;
    while (p || st.size()) {
        while (p) {
            st.push(p);
            p = p->left;
        }
        p = st.top();  st.pop();
        if (p->right == nullptr || pre == p->right) {
            cout << p->val << endl;
            pre = p;
            p = nullptr;
        } else {
            st.push(p);
            p = p->right;
        }
    }
}



ThreadTree& ThreadTree::operator=(initializer_list<int> v) {
    if (!v.size()) return *this;
    auto t = v.begin();
    root = new Node(*t);
    t++;
    queue<Node*> q({root});
    while (1) {
        Node* p = q.front();  q.pop();
        p->left = new Node(*t);
        t++;
        if (t == v.end()) break;
        q.push(p->left);
        
        p->right = new Node(*t);
        t++;
        if (t == v.end()) break;
        q.push(p->right);
    }
    Node* pre = nullptr;
    build(root, pre);
    pre->rF = 1;
    pre->right = nullptr;
    return *this;
}
ThreadTree::ThreadTree(initializer_list<int> v) {
    if (!v.size()) return;
    auto t = v.begin();
    root = new Node(*t);
    t++;
    queue<Node*> q({root});
    while (1) {
        Node* p = q.front();  q.pop();
        p->left = new Node(*t);
        t++;
        if (t == v.end()) break;
        q.push(p->left);
        
        p->right = new Node(*t);
        t++;
        if (t == v.end()) break;
        q.push(p->right);
    }
    Node* pre = nullptr;
    build(root, pre);
    pre->rF = 1;
    pre->right = nullptr;
}

void ThreadTree::build(Node* p, Node*& pre) {
    if (p == nullptr) return;
    build(p->left, pre);
    if (p->left == nullptr) {
        p->left = pre;
        p->lF = 1;
    }
    if (pre && pre->right == nullptr) {
        pre->right = p;
        pre->rF = 1;
    }
    pre = p;
    build(p->right, pre);
}

ThreadTree::Node* ThreadTree::findFirst(Node* p) {
    while (!p->lF) p = p->left;
    return p;
}
ThreadTree::Node* ThreadTree::findNext(Node* p) {
    if (p->rF) return p->right;
    return findFirst(p->right);
}
void ThreadTree::visit() {
    for (Node* p = findFirst(root); p; p = findNext(p)) cout << p->val << endl;
}
