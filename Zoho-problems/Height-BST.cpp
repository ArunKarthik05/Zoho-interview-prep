#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int dfs( TreeNode* root ,int height ){
        if( !root->left && !root->right)
            return height;
        int leftH= 0, rightH =0;
        if( root->left )    leftH =  dfs( root->left, height+1);
        if( root->right )   rightH= dfs( root->right, height+1);
        return max(leftH,rightH);
    }
    int maxDepth(TreeNode* root) {
        if (!root) return 0; // Base case for empty tree 
        return dfs(root,1);
    }
};
int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);       
    Solution s;
    int ans = s.maxDepth(root);
    cout<<"Height of the BST is:"<<ans<<endl;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left;
    delete root;
    return 0;
}