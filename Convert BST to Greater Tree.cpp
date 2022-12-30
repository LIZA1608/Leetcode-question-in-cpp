/*https://leetcode.com/problems/convert-bst-to-greater-tree/description/*/


class Solution {
public:
void solve(TreeNode* root,vector<TreeNode*>&ans){
    if(root==NULL){
        return;
    }
    solve(root->left,ans);
    ans.push_back(root);
    solve(root->right,ans);
}

    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        if(root->left==NULL && root->right==NULL){
            return root;
        }
     vector<TreeNode*>ans;
     solve(root,ans);
     for(int i=0;i<ans.size();i++){
     int sum=0;
     for(int j=i+1;j<ans.size();j++){
     sum+=ans[j]->val;
     }
     ans[i]->val+=sum;
     }
     return root;   
    }
};
