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

bool compare(TreeNode* root, TreeNode *subRoot){
    if(root==NULL && subRoot==NULL)return true;
    if(root==NULL || subRoot==NULL)return false;

    if(root->val!=subRoot->val)return false;
    return compare(root->left, subRoot->left) && compare(root->right, subRoot->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(!root)return false;
    if(compare(root, subRoot)){
        return true;;
    }
    return isSubtree(root->left, subRoot)|| isSubtree(root->right, subRoot);
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

    TreeNode *subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(3);
    subRoot->right = new TreeNode(6);
    //          4          <----
    //        /   \
    //       3     6       <----
    bool ans = isSubtree(root, subRoot);
    // ans -> true
    cout<<ans<<endl;
}