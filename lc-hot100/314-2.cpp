#include <bits/stdc++.h>

using namespace std;
bool compare(int a,int b){
    return a>b; // 以降序方式排列
}


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                // unordered_map<int,int>::iterator it;
                // for(it=hashtable.begin();it!=hashtable.end();++it){
                //     cout<<it->first<<":"<<it->second<<endl;
                // }
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};


void test(){
     // Note that the array is sorted
    int gfg[] = { 7, 6, 7, 6, 6, 6, 5, 5,4};
 
    vector<int> v(gfg, gfg + 9); // 5 5 5 6 6 6 7 7
    sort(v.begin(),v.end());
    for(auto e:v){
        cout<<e<<" ";
    }
    vector<int>::iterator lower, upper;
    lower = lower_bound(v.begin(), v.end(), 6);
    upper = upper_bound(v.begin(), v.end(), 6);
 
    cout << "lower_bound for 6 at index "
         << (lower - v.begin()) << '\n';
    cout << "upper_bound for 6 at index "
         << (upper - v.begin()) << '\n';
 
}
int main(){
    // test();
    // vector<int>v={1,2,0,-1};
    // int a[]={1,2,3,0};
    // sort(a,a+3,compare);
    // sort(v.begin(),v.end(),compare);
    // for(auto e:v){
    //     cout<<e<<" ";
    // }
    // cout<<endl;
    // vector<int>::iterator lower=lower_bound(v.begin(),v.end(),0); //>=1的第一个元素
    
    // cout<<"index:"<< lower-v.begin()<<endl;
    // for(int i=0;i<=3;i++){
    //     cout<<a[i]<<" ";
    // }

    Solution s;
    vector<int>nums={3,3};
    int target=6;
    vector<int>res=s.twoSum(nums,target);
    for(auto e:res){
        cout<<e<<" ";
    }
}