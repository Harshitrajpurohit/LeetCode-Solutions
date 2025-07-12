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

void find(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&ans){
    if (!root)
        return;

    if (p->val <= root->val && q->val >= root->val){
        ans = root;
        return;
    }

    find(root->left, p, q, ans);
    find(root->right, p, q, ans);
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
    TreeNode *ans = root;
    if (p->val < q->val){
        find(root, p, q, ans);
    }
    else
        find(root, q, p, ans);

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

    TreeNode* p = root->right->left;
    TreeNode* q = root->right;
    TreeNode* ans = lowestCommonAncestor(root,p,q);
    cout<<ans->val<<endl;
    // ans -> 15
}