#include<iostream>
#include<vector>
#include<queue>

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

// answer starts here -----------------

vector<int> rightSideView(TreeNode *root){
    if (!root)
        return {};

    queue<TreeNode *> q;

    q.push(root);
    vector<int> ans;

    while (!q.empty()){
        int size = q.size();
        int cnt = 0;
        for (int i = 0; i < size; i++){
            TreeNode *node = q.front();

            q.pop();

            if (cnt == size - 1)
                ans.push_back(node->val);

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);

            cnt++;
        }
    }
    return ans;
}

// answer ends here -----------------

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

    vector<int> ans = rightSideView(root);

    for(auto it:ans){
        cout<<it<<" ";
    }
    // ans ->  5 4 6 9
    return 0;
}