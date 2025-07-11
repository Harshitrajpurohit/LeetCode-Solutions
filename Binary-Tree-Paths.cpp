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


void path(TreeNode *root, string s, vector<string> &ans){
    if (!root){
        return;
    }
    if (!root->left && !root->right){
        s += to_string(root->val);
        ans.push_back(s);
    }
    else{
        s += to_string(root->val);
        s += "->";
    }

    path(root->left, s, ans);
    path(root->right, s, ans);
}
vector<string> binaryTreePaths(TreeNode *root){
    vector<string> ans;
    path(root, "", ans);
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

    vector<string> ans = binaryTreePaths(root);
    cout<<"[";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"]";
    // ans -> ["9->5->6->8","9->13->12","9->13->18"]
}