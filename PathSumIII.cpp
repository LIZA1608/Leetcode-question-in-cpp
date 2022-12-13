/*https://leetcode.com/problems/path-sum-iii/description/*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void solve(TreeNode* root,int k,vector<int>path,int &count){
    if(root==NULL){
        return;
    }
    path.push_back(root->val);
    solve(root->left,k,path,count);
    solve(root->right,k,path,count);
    int size=path.size();
    long long  sum=0;
    for(int i=size-1;i>=0;i--){
        sum+=path[i];
        if(sum==k){
            count++;
        }
    }
    path.pop_back();
}
    int pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        int count=0;
        solve(root,targetSum,path,count);
        return count;
    }
};
