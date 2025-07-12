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


void check(TreeNode *root, int target, vector<vector<int>> &ans, vector<int> arr){
    if (!root)
        return;
    target = target - root->val;
    arr.push_back(root->val);
    if (target == 0 && !root->left && !root->right)
    {
        ans.push_back(arr);
    }
    check(root->left, target, ans, arr);
    check(root->right, target, ans, arr);
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum){
    vector<vector<int>> ans;
    vector<int> arr;
    check(root, targetSum, ans, arr);

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

    int targetSum = 28;
    vector<vector<int>> ans = pathSum(root, targetSum);
    cout<<"[";
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<"]";
    }
    cout<<"]";
    // ans -> [[9, 5, 6, 8]]
}