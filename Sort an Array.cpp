/*https://leetcode.com/problems/sort-an-array/description/*/

class Solution {
public:
void heapify(vector<int>&arr,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void buildHeap(vector<int>&arr,int n){
 for(int i=n/2-1;i>=0;i--){
 heapify(arr,n,i);
 }
}
    vector<int> sortArray(vector<int>& nums) {
        int size=nums.size();
       buildHeap(nums,size);
       for(int i=size-1;i>0;i--){
           swap(nums[0],nums[i]);
           heapify(nums,i,0);
       }
       return nums;
    }
};
