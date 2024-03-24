#include <iostream>
#include <algorithm>
using namespace std;
#define N 8
int res=0;
int loc[N+1]={};
int q[N+1][N+1];
bool islocated(int row,int col){
    for(int i=1;i<=row-1;i++){
        if(loc[i]==col){
            return true;
        }
        if((abs(row-i)==abs(col-loc[i]))||((row+col)==(loc[i]+i))){
            return true;
        }
    }
    return false;
}
void dfs(int x){
    if(x==N+1){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
            cout<<q[i][j]<<" ";
        }cout<<endl;
        }
        cout<<++res<<endl;
        
    }else{
        
        for(int i=1;i<=N;i++){
            if(!islocated(x,i)){
                loc[x]=i;
                q[x][i]=1;
                dfs(x+1);
                loc[x]=0;
                q[x][i]=0;
            }
        }
    }

}

int main(){
    dfs(1);
    // cout<<res;
}