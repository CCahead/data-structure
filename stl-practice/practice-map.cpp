#include <bits/stdc++.h>


using namespace std;


int main(){
    map<int,int>mp;

    mp.insert({1,1});
    mp.insert({1,2});
    mp.insert({2,3});

    auto it=mp.begin(); 
    
    mp.insert(it,{0,1});//从0号位置插入元素


    for (auto it=mp.begin();it!=mp.end();++it){
        cout<<it->first<<": "<<it->second<<endl;
    }
    // for (auto& [key, value]: mp) {
    //         std::cout << key << " => " << value << '\n';
    // } 

}