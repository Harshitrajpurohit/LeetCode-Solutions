#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int data){
        val=data;
        left=right=NULL;
    }
};

// ans starts here

// using recursion
void preOrder(TreeNode *root, vector<int> &ans){
    if (!root)
        return;

    ans.push_back(root->val);
    preOrder(root->left, ans);
    preOrder(root->right, ans);
}

vector<int> preorderTraversal(TreeNode *root){
    vector<int> ans;
    preOrder(root, ans);
    return ans;
}



// ans ends here

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);


    vector<int> ans = preorderTraversal(root);

    for_each(ans.begin(), ans.end(), [](int x){
        cout<<x<<" ";
    });
    // ans -> 5 1 4 3 6
    return 0;

}