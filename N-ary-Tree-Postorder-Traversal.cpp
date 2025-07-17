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
    void order(Node* root,vector<int> &ans){
        if(!root)return;
        for(auto i:root->children){
            order(i, ans);
        }
        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;
        order(root, ans);

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
    vector<int> ans = sol.postorder(root);

    cout << "Postorder Traversal: ";
    for (int val : ans) {
        cout << val << " ";
    }

    return 0;
}
