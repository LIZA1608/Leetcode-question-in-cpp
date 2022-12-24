/*https://leetcode.com/problems/validate-binary-search-tree/description/*/

class Solution {
public:
    bool is_bst(TreeNode *root , long mini , long maxi)
    {
        if(root == NULL){
            return true;
        }
        if(root->val >= maxi || root->val <= mini){
            return false;
        }
        bool left= is_bst(root->left , mini , root->val) ;
        bool right= is_bst(root->right , root->val , maxi);
        return left&&right;
    }

    bool isValidBST(TreeNode* root) 
    {
        long mini = LONG_MIN;
        long maxi = LONG_MAX;
        return is_bst(root , mini , maxi);   
    }
};
