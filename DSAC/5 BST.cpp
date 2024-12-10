#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
    int data;
    node *l, *r;
};

class BST {
    node *root;

public:
    BST() {
        root = NULL;
    }

    void create() {
        int i, n, x, arr[40], k, flag, cnt = 0;
        cout << "\nEnter number of elements of BST: ";
        cin >> n;
        for (i = 0; i < n; i++) {
            cout << "\nEnter DATA: ";
            cin >> x;
            flag = 0;
            for (k = 0; k < cnt; k++) {
                if (x == arr[k]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                cout << "\nNumber is duplicate number!";
            } else {
                arr[cnt++] = x;
                insert(x);
            }
        }
    }

    void insert(int x) {
        node *p, *n, *t;
        n = new node;
        n->l = n->r = NULL;
        n->data = x;
        if (root == NULL) {
            root = n;
        } else {
            t = root;
            while (t != NULL) {
                p = t;
                if (x < t->data) {
                    t = t->l;
                } else {
                    t = t->r;
                }
            }
            if (x < p->data) {
                p->l = n;
            } else {
                p->r = n;
            }
        }
    }

    void display(node *t) {
        if (t != NULL) {
            display(t->l);
            cout << "\t" << t->data;
            display(t->r);
        }
    }

    void disp1() {
        display(root);
    }

    void display_leaf(node *t) {
        if (t != NULL) {
            if (t->l == NULL && t->r == NULL) {
                cout << "\t" << t->data;
            }
            display_leaf(t->l);
            display_leaf(t->r);
        }
    }

    void disp_leaf() {
        display_leaf(root);
    }

    int search(int x) {
        node *t = root;
        while (t != NULL) {
            if (x == t->data) {
                return 1;
            } else if (x < t->data) {
                t = t->l;
            } else {
                t = t->r;
            }
        }
        return 0;
    }

    node *copy(node *T) {
        node *p = NULL;
        if (T != NULL) {
            p = new node;
            p->data = T->data;
            p->l = p->r = NULL;
            p->l = copy(T->l);
            p->r = copy(T->r);
        }
        return p;
    }

    void copy1() {
        node *T;
        T = copy(root);
        cout << "\nCopied Tree: ";
        display(T);
    }

    void mirrorimg(node *t) {
        node *temp;
        if (t != NULL) {
            temp = t->l;
            t->l = t->r;
            t->r = temp;
            mirrorimg(t->l);
            mirrorimg(t->r);
        }
    }

    void mirrorimg1() {
        mirrorimg(root);
    }

    void delete1(int x) {
        node *t = root, *p = NULL, *tsucc;
        if (root == NULL) {
            cout << "\nTree is Empty!";
            return;
        }
        while (t != NULL && t->data != x) {
            p = t;
            if (x < t->data) {
                t = t->l;
            } else {
                t = t->r;
            }
        }
        if (t == NULL) {
            cout << "\nData not found!";
            return;
        }

        // Case 1: Node to be deleted has no children (leaf node)
        if (t->l == NULL && t->r == NULL) {
            if (root->data == x) {
                root = NULL;
            } else if (p->l == t) {
                p->l = NULL;
            } else {
                p->r = NULL;
            }
            delete t;
        }
        // Case 2: Node to be deleted has only one child (left or right)
        else if (t->l == NULL || t->r == NULL) {
            node *child = (t->l != NULL) ? t->l : t->r;
            if (root == t) {
                root = child;
            } else if (p->l == t) {
                p->l = child;
            } else {
                p->r = child;
            }
            delete t;
        }
        // Case 3: Node to be deleted has two children
        else {
            p = t;
            tsucc = t->r;
            while (tsucc->l != NULL) {
                p = tsucc;
                tsucc = tsucc->l;
            }
            t->data = tsucc->data;
            if (p->l == tsucc) {
                p->l = tsucc->r;
            } else {
                p->r = tsucc->r;
            }
            delete tsucc;
        }
    }
};

int main() {
    BST b;
    int ch, a, c, d;
    while (1) {
        cout << "\n**********MENU**********\n";
        cout << "1. Create\n2. Display\n3. Search\n4. Mirror Image\n5. Display Copy\n6. Delete\n7. Display Leaf Nodes\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                b.create();
                break;
            case 2:
                b.disp1();
                break;
            case 3:
                cout << "\nEnter element to search: ";
                cin >> a;
                c = b.search(a);
                if (c == 1) {
                    cout << "\nElement Found";
                } else {
                    cout << "\nElement not found";
                }
                break;
            case 4:
                b.mirrorimg1();
                cout << "\nTree after mirror image: ";
                b.disp1();
                break;
            case 5:
                b.copy1();
                break;
            case 6:
                cout << "\nEnter element to delete: ";
                cin >> d;
                b.delete1(d);
                cout << "\nTree after deletion: ";
                b.disp1();
                break;
            case 7:
                b.disp_leaf();
                break;
            case 8:
                exit(0);
                break;
            default:
                cout << "\nInvalid choice!";
                break;
        }
    }
    return 0;
}

