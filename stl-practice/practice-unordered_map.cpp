#include <bits/stdc++.h>


using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<=nums.size()-1;i++){
            
            mp[i]=target-nums[i];
        }
        for(auto e=mp.begin();e!=mp.end();e++){
        cout<<e->first<<" "<<e->second<<endl;
    }
        return {};
    }
};
int main(){
    // unordered_map<int,int> mp;
    // mp[1]=2;
    // mp[2]=3;
    
    // for(auto e=mp.begin();e!=mp.end();e++){
    //     cout<<e->first<<" "<<e->second<<endl;
    // }


    vector<int>nums={2,7,11,15};
    Solution s;
    int target=9;
    vector<int>res = s.twoSum(nums,target);
}