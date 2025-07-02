#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int data){
        val = data;
        left = right = NULL;
    }
};

// ans starts here

// using recursion
void postOrder(TreeNode *root, vector<int> &ans){
    if (!root)
        return;

    postOrder(root->left, ans);
    postOrder(root->right, ans);
    ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode *root){
    vector<int> ans;
    postOrder(root, ans);
    return ans;
}


// ans ends here

int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    vector<int> ans = postorderTraversal(root);

    for_each(ans.begin(), ans.end(), [](int x)
             { cout << x << " "; });
    // ans -> 1 3 6 4 5 
    return 0;
}