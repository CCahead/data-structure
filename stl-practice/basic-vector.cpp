#include <bits/stdc++.h>

using namespace std;


int main(){
    
    vector<int>v={1,3,3,3,2,4,4,4,5};

    vector<vector<int>>v2={{1,2},{2,3},{4,3}};
    for(auto e:v2){
        for(auto e1:e){
            cout<<e1<<" ";
        }
        cout<<endl;
    }
    vector<vector<int>>v3(10,vector<int>(5,0));
    for(auto e:v3){
        for(auto e1:e){
            cout<<e1<<" ";
        }
        cout<<endl;
    }

}