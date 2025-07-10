#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int data){
        val = data;
        left = right = NULL;
    }
};

vector<double> averageOfLevels(TreeNode *root){
    queue<TreeNode *> q;
    q.push(root);
    vector<double> ans;
    double sum = 0;
    int size;
    while (!q.empty()){
        size = q.size();
        sum = 0;
        for (int i = 0; i < size; i++){
            TreeNode *tp = q.front();
            q.pop();
            sum += tp->val;
            if (tp->left)
                q.push(tp->left);
            if (tp->right)
                q.push(tp->right);
        }
        ans.push_back(sum / size);
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

    vector<double> ans = averageOfLevels(root);
    for(double it: ans){
        cout<<it<<", ";
    }
    // ans -> [5, 2.5, 3.66667, 9]
}