#include <string>

#include <vector>
#include <iostream>

using namespace std;


void test1(){
    vector<string>v(10);
    v.push_back("H");
    v.push_back("E");
    v[0]="hello";
    v[1]=".";
    for(auto e:v){
        cout<<e;
    }
}
void test2(){
int n=3;
    vector<vector<string>>res(n,vector<string>(n));
    for(auto &e:res){
        for(int i=0;i<n;i++){
            e[i]=".";
        }
    }
    res[0][1]="Q";
    for(auto &e:res){
        for(int i=0;i<n;i++){
            cout<<e[i];
        }
        cout<<endl;
    }
}
void test3(){
    // ".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."
    // 1. 
    // 一个string： string[0]=".Q.." string[1]= "...Q"
    vector<vector<string>>arrstr;
    int loc[4]={2,4,1,3};
    string s[5];
    
    // for(int i=1;i<=4;i++){
    //     for(int i=1;i<=4;i++){
    //         if(loc[i]!=0){
    //             arrstr[]
    //         }
    //     }
    // }
}
int main(){
    // test2();
    test3();
}