
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) 
        :key(k),left(nullptr),right(nullptr)
    {
	}
    
};

// Function to build the binary search tree with the least search cost
Node* buildOptimalBST(const vector<int>& keys, const vector<double>& probabilities) {
    int n = keys.size();
    vector<vector<double>> cost(n + 1, vector<double>(n + 1, 0.0));
    vector<vector<int>> root(n, vector<int>(n, 0));

    // Initialize the diagonal elements of the cost matrix
    for (int i = 0; i < n; i++) {
        cost[i][i] = probabilities[i];
        root[i][i] = i;
    }

    // Calculate the cost and root values for different subtrees
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            // Calculate the cost of each possible root in the current subtree
            for (int r = i; r <= j; r++) {
                double c = ((r > i) ? cost[i][r - 1] : 0) +
                           ((r < j) ? cost[r + 1][j] : 0) +
                           (probabilities[r]);

                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }

    // Build the optimal binary search tree using the root values
    queue<pair<Node*, pair<int, int>>> q;
    Node* root_node = new Node(keys[root[0][n - 1]]);
    q.push(make_pair(root_node, make_pair(0, n - 1)));

    while (!q.empty()) {
        pair<Node*, pair<int, int>> curr = q.front();
        q.pop();

        Node* curr_node = curr.first;
        int i = curr.second.first;
        int j = curr.second.second;

        int r = root[i][j];

        if (r > i) {
            curr_node->left = new Node(keys[root[i][r - 1]]);
            q.push(make_pair(curr_node->left, make_pair(i, r - 1)));
        }

        if (r < j) {
            curr_node->right = new Node(keys[root[r + 1][j]]);
            q.push(make_pair(curr_node->right, make_pair(r + 1, j)));
        }
    }

    return root_node;
}

// Function to perform inorder traversal of the binary search tree
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}

int main() {
    int ch;
    vector<int> keys;
    vector<double> probabilities;
    Node* root;

    while (true) {
        cout << "Select the operation \n1.Add Nodes \n3.Build tree using given data \n3.Display Tree \n4.Exit program" << endl;
        cin >> ch;
        switch (ch) {
            case 1:
                double p;
                int k;
                cout << "Enter your key : " << endl;
                cin >> k;
                cout << "Enter your probabilty : " << endl;
                cin >> p;
                keys.push_back(k);
                probabilities.push_back(p);
                cout << "Node added" << endl;
                break;
            case 2:
                root = buildOptimalBST(keys, probabilities);
                cout << "Tree created" << endl;
                break;
            case 3:
                cout << "Inorder Traversal of Optimal BST: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}
