/*https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/*/


class Solution {
public:
int countNodes(ListNode* head){
    int cnt=0;
    ListNode* temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
TreeNode* sortedll(ListNode* &head,int n){
    if(n<=0 || head==NULL){
        return NULL;
    }
    TreeNode* left=sortedll(head,n/2);
   TreeNode *root=new TreeNode(head->val);
  root->left=left;
    head=head->next;
    root->right=sortedll(head,n-n/2-1);
    return root;
}
    TreeNode* sortedListToBST(ListNode* head) {
        int n=countNodes(head);
           return sortedll(head,n);
    }
};
