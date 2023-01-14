/*https://leetcode.com/problems/reorganize-string/description/*/

class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>maxi;
        map<char,int>m;
        for(auto i:s){
            m[i]++;
        }
        for(auto i:m){
            maxi.push({i.second,i.first});
        }
    string ans="";
    auto block=maxi.top();
    maxi.pop();
    ans+=block.second;
    block.first--;
    while(maxi.size()>0){
     auto temp=maxi.top();
     maxi.pop();
     ans+=temp.second;
     temp.first--;
     if(block.first>0 ){
         maxi.push({block.first,block.second});
     }
     block=temp;
    }
    if(block.first>0){
        return"";
    }
    return ans;
    }
};
