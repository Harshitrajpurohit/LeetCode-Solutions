#include<iostream>
#include<vector>

using namespace std;


struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int data){
        val = data;
        left=right=NULL;
    }
};


// answer starts here -----------------
int flag = 1;
void check(TreeNode *root, long &left){
    if (!root)
        return;
    check(root->left, left);
    if (left >= root->val){
        flag = 0;
    }
    left = root->val;
    check(root->right, left);
}

bool isValidBST(TreeNode *root){
    long left = LONG_MIN;
    check(root, left);
    if (flag)
        return true;

    return false;
}
// answer ends here -----------------


int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

//           5
//        /    \
//       1      4
//      / \    / \
//     N   N  3   6

    cout<<isValidBST(root);
    // ans -> false;
    return 0;
}