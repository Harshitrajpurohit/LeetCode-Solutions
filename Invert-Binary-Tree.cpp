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

void invert(TreeNode* root){
    if(!root)return;

    if(!root->left && !root->right){
        return;
    }
    swap(root->left, root->right);
    invert(root->left);
    invert(root->right);
}

TreeNode* invertTree(TreeNode* root) {
    
    invert(root);
    return root;

}

// answer ends here -----------------

// Level order traversal
vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int size = q.size();
            vector<int> tp;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                tp.push_back(node->val);
                if(node->left != NULL)q.push(node->left);
                if(node->right != NULL)q.push(node->right);
            }
            ans.push_back(tp);
        }
        return ans;
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

    TreeNode* ans = invertTree(root);

    vector<vector<int>> vec = levelOrder(ans);

    for(int i = 0; i < vec.size(); i++) {
    cout << "[ ";
    for(int j = 0; j < vec[i].size(); j++) {
        cout << vec[i][j] << " ";
    }
    cout << "]";
    }


    return 0;
}