#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<int>res;
        for(auto e:nums){
            // 查找是否存在key==e 若有，value++； 若无，插入value=1
            // https://www.geeksforgeeks.org/map-find-function-in-c-stl/?ref=lbp
            if(mp.find(e)!=mp.end()){
                mp[e]++;
            }else{
                mp.insert({e,1});
            }
        }
        // https://stackoverflow.com/questions/53920130/what-is-the-role-of-greater-int-in-set
        // https://stackoverflow.com/questions/19842035/how-can-i-sort-a-stdmap-first-by-value-then-by-key
        // 这里利用了set的一个性质：set会默认以ascend的方式对key进行排序，也可以在初始化的时候用greater
        // 用set<type,greater<type>>进行排序
        // 所以这里：set内是存储的<int,int>的pair，那greater类也要以pair<int,int>来初始化？（类模板）
        set<pair<int,int>,greater<pair<int,int>>>s;
        for(auto &kv:mp){
            s.emplace(kv.second,kv.first);
        }
        for(auto &vk:s){
            if(k<=0){
                break;
            }
            res.push_back(vk.second);
            k--;
        }
        return res;
    }
};

int main(){
    vector<int>nums = {1,1,1,2,2,3};
    int k = 2;

    Solution s;
    vector<int> res=s.topKFrequent(nums,k);
    
    for(auto e :res){
        cout <<e<<" ";
    }
}