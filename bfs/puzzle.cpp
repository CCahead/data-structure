#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;
#define N 110

int n,m;
int g[N][N];//地图信息
int d[N][N];//距离
PII q[N*N];//简化版queue，存放坐标信息
int bfs(){
    int tt=0,hh=0 ; //头 尾指针
    q[0]={0,0};//从0，0位置出发
    memset(d,-1,sizeof d);//初始化距离矩阵
    d[0][0]=0;//已经走过这个点
    int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};
    while(hh<=tt){//队列不空 
        auto t =q[hh++]; //取出队头元素
        for(int i=0;i<4;i++){
            int x=t.first+dx[i],y=t.second+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m//点有效
            &&g[x][y]==0&&d[x][y]==-1){//点可以走且未被访问过
                d[x][y]=d[t.first][t.second]+1;
                q[++tt]={x,y};
            }
        }
    }
    return d[n-1][m-1];
}
// 定义操作： 向上走: -1,0 ，向下走: 1,0 向左走 0,-1 向右走 0,1
// 0 A 0
// C x D  x: 2,2
// 0 B 0
//  x->A:2,2->1,2 向上走 -1,0 x->B 2,2->3,2
// 向左走： 2,2->2,1
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
            cin>>g[i][j];
    } 
    
    }
    cout<<bfs()<<endl;
    // queue<pair<int,int>>q;
    // q.emplace(make_pair(1,1));
    // auto a=q.front();
    // cout<<a.first<<" "<<a.second<<" "<<q.empty();
}



