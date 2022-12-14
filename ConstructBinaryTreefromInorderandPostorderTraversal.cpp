/*https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/*/
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
int findPos(vector<int>&in,int ele,int n){
    for(int i=0;i<n;i++){
        if(in[i]==ele){
            return i;
        }
    }
    return -1;
}
TreeNode* solve(vector<int>&in,vector<int>&post,int &index,int inorderstart,int inorderend,int n){
if(inorderend<0 || inorderstart>inorderend){
    return NULL;
}
int curr=post[index];
index--;
int pos=findPos(in,curr,n);
TreeNode* root=new TreeNode(curr);
root->right=solve(in,post,index,pos+1,inorderend,n);
root->left=solve(in,post,index,inorderstart,pos-1,n);
return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderindex=inorder.size()-1;
        TreeNode* ans=solve(inorder,postorder,postorderindex,0,inorder.size()-1,inorder.size());
        return ans;
    }
};
