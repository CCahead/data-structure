#include <bits/stdc++.h>

using namespace std;

void insert(vector<int>&nums,int n,int location){
    int tmp=nums[location];
    for(int i=n;i>=location;i--){
        nums[i]=nums[i-1];
    }
    nums[location]=nums[0];
}

int main(){
    int n;
    cin>>n;
    vector<int>v(60,0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    // for(int i=1;i<=n;i++){
    //     cout<<v[i]<<" ";
    // } 
    // cout<<endl;
    cin>>v[0];
    //新同学学好； 培二学位：训
    n++;

    int p,q,location;
    cin>>p>>q;
    if(p==1){
        location=q;
    }else{
        location=q+1;
    }
    
    insert(v,n,location);
    for(int i=1;i<=n;i++){
        cout<<v[i]<<" ";
    }
}


// 劳务 hr 技术面2 c++
// 22.9-23.10 od岗位通用 if 资面 
// 德科产品线 技术1 2面


