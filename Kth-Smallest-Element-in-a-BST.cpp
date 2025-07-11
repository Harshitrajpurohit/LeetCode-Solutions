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

void check(TreeNode *root, int &k, int &ans){
    if (!root)return;

    check(root->left, k, ans);
    --k;
    if (k == 0){
        ans = root->val;
        return;
    }
    check(root->right, k, ans);
}
int kthSmallest(TreeNode *root, int &k){
    if (!root)return 0;
    int ans;
    check(root, k, ans);
    return ans;
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

    int k=2;
    int ans = kthSmallest(root,k);
    cout<<ans<<endl;
    // ans -> 6
}