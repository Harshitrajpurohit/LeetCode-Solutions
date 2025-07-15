#include<iostream>

using namespace std;

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int data)
    {
        val = data;
        left = right = NULL;
    }
};


void check(TreeNode *root, int &cnt){
    if (!root)return;

    if (root->left && root->left->left == NULL && root->left->right == NULL){
        cnt += root->left->val;
    }

    check(root->left, cnt);
    check(root->right, cnt);
}

int sumOfLeftLeaves(TreeNode *root){
    int cnt = 0;
    check(root, cnt);
    return cnt;
}




int main(){
    TreeNode *root = new TreeNode(9);
    root->left = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(8);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);

    //           9          <----
    //        /     \
    //       5      15       <----
    //      / \    /  \
    //     N   6  12  18     <----
    //          \
    //           8          <----

    int ans = sumOfLeftLeaves(root);
    cout<<ans<<endl;
    // ans -> 12
}