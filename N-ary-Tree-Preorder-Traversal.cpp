#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// answer starts from here

class Solution {
public:
    void pre(Node* root, vector<int> &ans) {
        if (!root) return;
        ans.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++) {
            pre(root->children[i], ans);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> ans;
        pre(root, ans);
        return ans;
    }
};

// answer ends here

int main() {
    // Example N-ary tree:
    //        1
    //      / | \
    //     3  2  4
    //    / \
    //   5   6

    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node3 = new Node(3, {node5, node6});
    Node* node2 = new Node(2);
    Node* node4 = new Node(4);
    Node* root = new Node(1, {node3, node2, node4});

    Solution sol;
    vector<int> ans = sol.preorder(root);

    cout << "Preorder Traversal: ";
    for (int val : ans) {
        cout << val << " ";
    }

    return 0;
}
