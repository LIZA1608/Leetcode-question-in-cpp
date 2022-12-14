/*https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/*/
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
TreeNode* buildTreeUtil(vector<int>&pre,vector<int>&in,int &index,int inorderstart,int inorderend,int size){
if(inorderend>=size || inorderstart>inorderend){
    return NULL;
}
int currele=pre[index];
index++;
TreeNode* root=new TreeNode(currele);
int pos=findPos(in,currele,size);

root->left=buildTreeUtil(pre,in,index,inorderstart,pos-1,size);
root->right=buildTreeUtil(pre,in,index,pos+1,inorderend,size);
return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderindex=0;
       TreeNode* ans= buildTreeUtil(preorder,inorder,preorderindex,0,inorder.size()-1,inorder.size());
        return ans;
    }
};
