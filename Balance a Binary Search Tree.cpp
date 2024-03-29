/*https://leetcode.com/problems/balance-a-binary-search-tree/description/*/

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
void inorder(TreeNode* root,vector<int>&in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->val);
    inorder(root->right,in);
}
TreeNode* inordertobst(int s,int e,vector<int>inorderVal){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    TreeNode* root=new TreeNode(inorderVal[mid]);
    root->left=inordertobst(s,mid-1,inorderVal);
    root->right=inordertobst(mid+1,e,inorderVal);
    return root;
}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorderVal;
        inorder(root,inorderVal);
        int n=inorderVal.size();
        return inordertobst(0,n-1,inorderVal);
    }
};
