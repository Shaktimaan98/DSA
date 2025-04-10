#include <iostream>

using namespace std;

class node {
    node *left, *right;
    int data;
    bool rbit, lbit;

public:
    node() {
        left = NULL;
        right = NULL;
        rbit = lbit = 0;
    }

    node(int d) {
        left = NULL;
        right = NULL;
        rbit = lbit = 0;
        data = d;
    }

    friend class TBT;
};

class TBT {
    node *root; // Acts as a dummy node

public:
    TBT() {
        root = new node(9999);
        root->left = root;
        root->right = root;
        root->rbit = 1;
        root->lbit = 0;
    }

    void create();
    void insert(int data);
    node* inorder_suc(node *c);
    void inorder_traversal();
    node* preorder_suc(node *c);
    void preorder_traversal();
};

void TBT::preorder_traversal() {
    node *c = root->left;
    while (c != root) {
        cout << " " << c->data;
        c = preorder_suc(c);
    }
}

void TBT::inorder_traversal() {
    node *c = root->left;
    while (c->lbit == 1) {
        c = c->left;
    }
    while (c != root) {
        cout << " " << c->data;
        c = inorder_suc(c);
    }
}

node* TBT::inorder_suc(node *c) {
    if (c->rbit == 0)
        return c->right;
    else {
        c = c->right;
        while (c->lbit == 1)
            c = c->left;
        return c;
    }
}

node* TBT::preorder_suc(node *c) {
    if (c->lbit == 1)
        return c->left;
    while (c->rbit == 0)
        c = c->right;
    return c->right;
}

void TBT::create() {
    int n;
    cout << "\nEnter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int info;
        cout << "\nEnter data: ";
        cin >> info;
        this->insert(info);
    }
}

void TBT::insert(int data) {
    node *cur = root;
    while (true) {
        if (data < cur->data) {
            if (cur->lbit == 0) {
                node *p = new node(data);
                p->left = cur->left;
                p->lbit = cur->lbit;
                p->rbit = 0;
                p->right = cur;
                cur->lbit = 1;
                cur->left = p;
                cout << "\nInserted left: " << data;
                return;
            } else {
                cur = cur->left;
            }
        } else {
            if (cur->rbit == 0) {
                node *p = new node(data);
                p->right = cur->right;
                p->rbit = cur->rbit;
                p->lbit = 0;
                p->left = cur;
                cur->rbit = 1;
                cur->right = p;
                cout << "\nInserted right: " << data;
                return;
            } else {
                cur = cur->right;
            }
        }
    }
}

int main() {
    TBT t1;
    int value, choice;

    do {
        cout << "\n1. Create Tree\n2. Insert into tree\n3. Preorder\n4. Inorder\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                t1.create();
                break;
            case 2:
                cout << "\nEnter Number (data): ";
                cin >> value;
                t1.insert(value);
                break;
            case 3:
                cout << "\nPreorder traversal of TBT: ";
                t1.preorder_traversal();
                break;
            case 4:
                cout << "\nInorder traversal of TBT: ";
                t1.inorder_traversal();
                break;
            case 5:
            	cout<<"End of program";
                break;
            default:
                cout << "\nWrong choice!";
        }
    } while (choice != 5);

    return 0;
}
