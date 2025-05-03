

#include <iostream>
#include <iomanip>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Corrected Insert Function
node* insert(node* root, int value) {
    if (root == NULL) {
        return new node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to find height of BST
int height(node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// Function to find the minimum value in BST
int findMin(node* root) {
    if (root == NULL) {
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// Function to mirror the BST
void mirror(node* root) {
    if (root == NULL) {
        return;
    }
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

// Function to search for a value in BST
bool search(node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// *Inorder Traversal* (Left - Root - Right)
void inorder(node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// *Preorder Traversal* (Root - Left - Right)
void preorder(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// *Postorder Traversal* (Left - Right - Root)
void postorder(node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Display BST as a tree structure
void display(node* root, int space = 0, int level_gap = 5) {
    if (root == NULL)
        return;
    space += level_gap;
    display(root->right, space);
    cout << setw(space) << root->data << endl;
    display(root->left, space);
}

// Choice-based main function
int main() {
    node* root = NULL;
    int choice, value;
    do {
        cout << "\nBinary Search Tree Menu:";
        cout << "\n1. Insert Node";
        cout << "\n2. Find Height of Tree";
        cout << "\n3. Find Minimum Value";
        cout << "\n4. Mirror the Tree";
        cout << "\n5. Search for a Value";
        cout << "\n6. Inorder Traversal";
        cout << "\n7. Preorder Traversal";
        cout << "\n8. Postorder Traversal";
        cout << "\n9. Display BST as a Tree";
        cout << "\n10. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Height of the tree: " << height(root) << endl;
                break;
            case 3:
                cout << "Minimum value in BST: " << findMin(root) << endl;
                break;
            case 4:
                mirror(root);
                cout << "Tree has been mirrored!" << endl;
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                cout << (search(root, value) ? "Found" : "Not Found") << endl;
                break;
            case 6:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 7:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 8:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 9:
                cout << "Tree Structure:\n";
                display(root);
                cout << endl;
                break;
            case 10:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 10);

    return 0;
}
