#include <iostream>
using namespace std;


struct Node {
    int key;
    Node *left, *right, *p;
    Node(int k = 0 ) : key(k) , left(nullptr), right(nullptr), p(nullptr) {}
};

struct BST {
    Node *root;
    Node *NIL;

    BST(){
        NIL = new Node(); // case where all is NULL 
        NIL -> left = NIL -> right = NIL -> p = NIL;
        root = NIL;
    }


    void TREE_INSERT(int k) {
        Node* z = new Node(k);
        z->left = z->right = NIL;

        Node* y = NIL;
        Node* x = root;
        while (x != NIL) {
            y = x;
            if (z->key < x->key) x = x->left;
            else                 x = x->right;
        }
        z->p = y;
        if (y == NIL)            root = z;           // tree was empty
        else if (z->key < y->key) y->left = z;
        else                      y->right = z;
    }

Node* TREE_SEARCH(int k) const {
        Node* x = root;
        while (x != NIL && x->key != k)
            x = (k < x->key) ? x->left : x->right;
        return x;
    }

Node* TREE_MINIMUM(Node* x) const {
    while (x-> left != NIL ) x = x->left;
    return x;
     
}

void TRANSPLANT(Node* u , Node* v){
    if (u->p == NIL) root = v;
    else if (u== u->p->left) u->p->left = v;
    else u->p->right = v;
    if (v != NIL) v->p = u->p;

}

void TREE_DELETE(int k){
    Node* z = TREE_SEARCH(k);
    if(z == NIL) return;
    if (z -> left == NIL){
        TRANSPLANT(z,z->right);
    } else if (z -> right == NIL){
        TRANSPLANT(z,z->left);
    } else {
        Node* y = TREE_MINIMUM(z->right);
        if (y->p != z){
            TRANSPLANT(y,y->right);
            y->right = z->right;
            y->right->p = y;
        }
        TRANSPLANT(z,y);
        y->left = z->left;
        y->left->p = y;
    }
    delete z;
    }

    void INORDER(Node* x) const {
        if (x!=NIL){INORDER(x->left); cout<<x->key<<"\n"; INORDER(x->right);}
    }

    void PREORDER(Node* x) const {
        if (x!=NIL){cout<<x->key<<"\n"; PREORDER(x->left); PREORDER(x->right);}
    }

void POSTORDER(Node* x) const {
        if (x!=NIL){POSTORDER(x->left); POSTORDER(x->right); cout<<x->key<<"\n"; }
    }


    ~BST(){CLEAR(root);delete NIL;}
    void CLEAR(Node* x) {if (x==NIL) return; CLEAR(x->left); CLEAR(x->right); }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    BST T;
    string s;
    while (getline(cin, s)) {
        if (s.empty()) continue;
        if (s == "e") break;

        if (s == "oin")   { T.INORDER(T.root);   continue; }
        if (s == "opre")  { T.PREORDER(T.root);  continue; }
        if (s == "opost") { T.POSTORDER(T.root); continue; }

        char cmd = s[0];
        int key = stoi(s.substr(1));
        if (cmd == 'i') T.TREE_INSERT(key);
        else if (cmd == 'd') T.TREE_DELETE(key);
    }
    return 0;
}


   

    