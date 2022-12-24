/*https://leetcode.com/problems/search-in-a-binary-search-tree/description/*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* res=root;
        while(res!=NULL) {
            if(res->val==val) return res;
            else if(res->val>val) res=res->left;
            else res=res->right;
        }
        return res;
    }
};
