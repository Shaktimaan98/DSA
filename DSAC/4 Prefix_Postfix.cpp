#include<iostream>
#include<stdlib.h>
#include<ctype.h>
using namespace std;

struct node {
    char data;
    node *l, *r;
};

class stack {
    node* data[100]; // Increased size for stack to handle larger expressions
    int top;

public:
    stack() {
        top = -1;
    }

    int isempty() {
        return top == -1;
    }

    void push(node* p) {
        data[++top] = p;
    }

    node* pop() {
        if (isempty()) {
            cout << "Stack underflow!" << endl;
            return NULL;
        }
        return data[top--];
    }
};

class exptree {
public:
    node* root;
    
    exptree() {
        root = NULL;
    }

    void create() {
        int i;
        char post[100]; // Increased size for the postfix expression input
        node *p;
        stack s;
        
        cout << "\nEnter Postfix Expression: ";
        cin >> post;

        for (i = 0; post[i] != '\0'; i++) {
            p = new node;
            p->data = post[i];
            p->l = p->r = NULL;

            if (isalnum(p->data)) {
                s.push(p);
            } else {
                p->r = s.pop();
                p->l = s.pop();
                s.push(p);
            }
        }
        root = s.pop();
    }

    void rec_in(node* t) {
        if (t != NULL) {
            rec_in(t->l);
            cout << t->data;
            rec_in(t->r);
        }
    }

    void rec_pre(node* t) {
        if (t != NULL) {
            cout << t->data;
            rec_pre(t->l);
            rec_pre(t->r);
        }
    }

    void non_rec_in() {
        node* t = root;
        stack s;

        while (t != NULL || !s.isempty()) {
            if (t != NULL) {
                s.push(t);
                t = t->l;
            } else {
                t = s.pop();
                cout << t->data;
                t = t->r;
            }
        }
    }

    void non_rec_pre() {
        node* t = root;
        stack s;

        while (t != NULL || !s.isempty()) {
            if (t != NULL) {
                cout << t->data;
                s.push(t);
                t = t->l;
            } else {
                t = s.pop();
                t = t->r;
            }
        }
    }
};

int main() {
    exptree E;
    int ch;

    while (1) {
        cout << "\n********MENU**********";
        cout << "\n1. Create\n2. Recursive Inorder\n3. Recursive Preorder\n4. Non-Recursive Inorder\n5. Non-Recursive Preorder\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            E.create();
            break;
        case 2:
            cout << "Recursive Inorder: ";
            E.rec_in(E.root);
            cout << endl;
            break;
        case 3:
            cout << "Recursive Preorder: ";
            E.rec_pre(E.root);
            cout << endl;
            break;
        case 4:
            cout << "Non-Recursive Inorder: ";
            E.non_rec_in();
            cout << endl;
            break;
        case 5:
            cout << "Non-Recursive Preorder: ";
            E.non_rec_pre();
            cout << endl;
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }
}

