#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

struct node
{
    char label[10];
    int ch_count;
    struct node *child[10];
} *root;

class BST
{
public:
    void create_tree();
    void display(node *r1);
    BST()
    {
        root = NULL;
    }
};

void BST::create_tree()
{
    int tbooks, tchapters, i, j, k;
    root = new node();
    cout << "Enter name of book: ";
    cin >> root->label;
    cout << "Enter no. of chapters in book: ";
    cin >> tchapters;
    root->ch_count = tchapters;

    for (i = 0; i < tchapters; i++)
    {
        root->child[i] = new node;
        cout << "Enter Chapter name: ";
        cin >> root->child[i]->label;
        cout << "Enter no. of sections in Chapter " << root->child[i]->label << ": ";
        cin >> root->child[i]->ch_count;

        for (j = 0; j < root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "Enter Section " << j + 1 << " name: ";
            cin >> root->child[i]->child[j]->label;
        }
    }
}

void BST::display(node *r1)
{
    int i, j, k, tchapters;
    if (r1 != NULL)
    {
        cout << "\n-----Book Hierarchy-----";
        cout << "\nBook title: " << r1->label;
        tchapters = r1->ch_count;

        for (i = 0; i < tchapters; i++)
        {
            cout << "\n  Chapter " << i + 1 << ": " << r1->child[i]->label;
            cout << "\n  Sections:";

            for (j = 0; j < r1->child[i]->ch_count; j++)
            {
                cout << "\n    " << r1->child[i]->child[j]->label;
            }
        }
        cout << endl;
    }
}

int main()
{
    int choice;
    BST bst;

    while (1)
    {
        cout << "-----------------" << endl;
        cout << "Book Tree Creation" << endl;
        cout << "-----------------" << endl;
        cout << "1. Create" << endl;
        cout << "2. Display" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bst.create_tree();
            break;
        case 2:
            bst.display(root);
            break;
        case 3:
            cout << "End of program" << endl;
            exit(1);
        default:
            cout << "Wrong choice" << endl;
        }
    }
}
