#include <bits/stdc++.h>

using namespace std;



int main(){
    // priority_queue<int,vector<int>,greater<int>>q;
    // q.emplace(1);
    // q.emplace(10);
    // int a=q.top();

    // cout<<a;

    unordered_map<int,int>mp;
    mp.insert(make_pair(1,0));
        mp.insert(make_pair(2,0));
    mp.insert(make_pair(-1,0));
    mp.insert(make_pair(3,-1));
    if(mp.find(3)!=mp.end()){
        cout<<mp[3];
    }

    vector<int>v={1,2,3,4,5};
    cout<< accumulate(v.begin(),v.begin()+4,0);
    // mp.bucket_size();
}