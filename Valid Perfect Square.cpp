/*https://leetcode.com/problems/valid-perfect-square/description/*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        int s=1;
        int e=num;
        while(s<=e){
            long int  mid=s+(e-s)/2;
            if(mid*mid==num){
                return true;
            }
            else if(mid*mid>num){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return false;
    }
};
