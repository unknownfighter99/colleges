#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

class BinaryTree {
public:
    Node* constructTree(char[]);
    void displayInorder(Node*);
    void nonRecPostorder(Node*);
};

Node* createNode(char);
bool isOperator(char);
void deleteTree(Node*);

Node* BinaryTree::constructTree(char prefix[]) {
    stack<Node*> st;

    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        if (!isOperator(prefix[i])) {
            Node* t = createNode(prefix[i]);
            st.push(t);
        }
        else {
            Node* t = createNode(prefix[i]);
            t->left = st.top();
            st.pop();
            t->right = st.top();
            st.pop();
            st.push(t);
        }
    }

    Node* root = st.top();
    st.pop();
    return root;
}

void BinaryTree::displayInorder(Node* root) {
    if (root != NULL) {
        displayInorder(root->left);
        cout << root->data;
        displayInorder(root->right);
    }
}

void BinaryTree::nonRecPostorder(Node* root) {
    if (root == NULL)
        return;

    stack<Node*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        Node* current = st1.top();
        st1.pop();
        st2.push(current);

        if (current->left)
            st1.push(current->left);
        if (current->right)
            st1.push(current->right);
    }

    while (!st2.empty()) {
        Node* node = st2.top();
        st2.pop();
        cout << node->data;
    }
}

Node* createNode(char value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool isOperator(char value) {
    if (value == '+' || value == '-' || value == '*' || value == '/')
        return true;
    return false;
}

void deleteTree(Node* node) {
    if (node == NULL)
        return;

    deleteTree(node->left);
    deleteTree(node->right);
    cout <<endl<<"Deleting node : " << node->data<<endl;
    delete node;
}

int main() {
    char prefix[20];
    BinaryTree bt;
    
    cout << "Enter prefix expression: ";
    cin >> prefix;

    Node* root = bt.constructTree(prefix);
    cout << "Inorder Sequence: ";
    bt.displayInorder(root);

    cout << "\nPostorder Traversal (Non-Recursive): ";
    bt.nonRecPostorder(root);

    deleteTree(root);
    return 0;
}
