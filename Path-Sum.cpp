#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left,* right;
    TreeNode(int data){
        val = data;
        left = right = NULL;
    }
};

bool hasPathSum(TreeNode *root, int targetSum){
    if (root == NULL){
        return false;
    }
    if (root->left == NULL && root->right == NULL){
        return root->val == targetSum;
    }
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(9);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    //           5          <----
    //        /    \
    //       1      4       <----
    //      / \    / \
    //     N   2  3   6     <----
    //          \
    //           9          <----

    int target = 12;

    bool ans = hasPathSum(root, target);
    // ans -> true
    cout<<ans<<endl;
}