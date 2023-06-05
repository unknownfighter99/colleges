// Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given.After constructing a binary tree – i.Insert new node, ii.Find number of nodes in longest path from root, iii.Minimum data value found in the tree, iv.Change a tree so that the roles of the left and right pointers are swapped at every node, v.Search a value

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

class BST {
   public:
    Node* root;
    BST() {
        root = NULL;
    }
    void insertValue() {
        cout << "Enter the value" << endl;
        int tempValue;
        cin >> tempValue;
        if (root == NULL) {
            root = new Node(tempValue);
        } else {
            insertNode(tempValue, root);
        }
        cout << "Value added successfully" << endl;
    }

    Node* insertNode(int value, Node* node) {
        if (node == NULL) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertNode(value, node->left);
        } else {
            node->right = insertNode(value, node->right);
        }
    }

    int findLongestPathRecursive(Node* node) {
        if (node == NULL) return 0;
        int leftPath = findLongestPathRecursive(node->left);
        int rightPath = findLongestPathRecursive(node->right);
        return max(leftPath, rightPath) + 1;
    }

    int findMinValueRecursive(Node* root) {
        if (root == NULL) return INT_MAX;
        if (root->left == NULL) return root->data;
        return findMinValueRecursive(root->left);
    }

    void swapRolesRecursive(Node* node) {
        if (node == NULL) return;
        swapRolesRecursive(node->left);
        swapRolesRecursive(node->right);
        swap(node->left, node->right);
    }

    void searchValue() {
        cout << "Enter the value" << endl;
        int tempValue;
        cin >> tempValue;
        searchValueRecursive(this->root, tempValue);
    }

    void searchValueRecursive(Node* root, int value) {
        if (root == NULL) {
            cout << "Value not Found" << endl;
            return;
        } else if (root->data == value) {
            cout << "Value Found" << endl;
        } else if (value < root->data) {
            searchValueRecursive(root->left, value);
        } else {
            searchValueRecursive(root->right, value);
        }
    }

    void printTreeRecursive(Node* root) {
        if (root == NULL) return;
        printTreeRecursive(root->left);
        cout << root->data << " ";
        printTreeRecursive(root->right);
    }
};

int main() {
    BST t;
    int ch;
    string ans;
    while (true) {
        cout << "\n1)Insert new node \n2)number of nodes in longest path \n3)minimum \n4) mirror \n5) search \n6) display tree" << endl;
        cin >> ch;
        switch (ch) {
            case 1:
                t.insertValue();
                break;
            case 2:
                cout << "The longest path is this tree is " << t.findLongestPathRecursive(t.root) << endl;
                break;
            case 3:
                cout << "The minimum value is " << t.findMinValueRecursive(t.root) << endl;
                break;
            case 4:
                t.swapRolesRecursive(t.root);
                t.printTreeRecursive(t.root);
                break;
            case 5:
                t.searchValue();
                break;
            case 6:
                cout << "\n***************INORDER**************" << endl;
                t.printTreeRecursive(t.root);
                break;
            case 7:
                exit(0);
            default:
                cout << "Enter the correct option: " << endl;
                break;
        }
    }
    return 0;
}