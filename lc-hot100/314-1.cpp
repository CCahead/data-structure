#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>dp(nums.size());
        for(int i=0;i<=nums.size()-1;i++){
            if(dp[i-1]>0){
                dp[i]=dp[i-1]+nums[i];
            }else{
                dp[i]=nums[i];
            }
        }
        for(auto e:dp){
            cout<<e<<" ";
        }
        auto it=max_element(dp.begin(),dp.end());
        int res=*it;    
        return res ;
    }
};

// 5,4,-1,7,8
// 5 9 9 15 23 
// res=8 需要一个临时但愿来记录现在的值？

// [-2,1,-3,4,-1,2,1,-5,4]
// -2  1 1  4   2  3 4  2  2
// -2 -1 -2    1  3
// 之前和+现在<现在的话=>用现在的元素作为起点，之前和更新
// -2 1 -3  ==> 之前和-2，遇到1: presum=-1<1 所以把现在的元素1作为起点，之前和改为1，并从1重新开始计数
// 1-3 =-2 之前和+现在<之前和的话，保留之前和，但是数组还是写为1，即为之前和最大是为1的
// 然后看下一个： 之前和+现在<现在 所以之前和更新成4，位置也改成现在的位置，从4开始
// 再用一个二分查找找到2的初始位置即可 Olgn+On
int main(){
    Solution s;
    // vector<int>nums={5,4,-1,7,8};
    vector<int>nums={-2,1,-3,4,-1,2,1,-5,4};
    int a=s.maxSubArray(nums);
    cout<<a<<endl;
}