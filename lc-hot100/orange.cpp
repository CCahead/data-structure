#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res=0;
        n=grid.size();m=grid[0].size();
        visit.resize(n,vector<int>(m,0));
        time.resize(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    visit[i][j]=1;
                    q.emplace(make_pair(i,j));
                    
                }
            }
            
        }
        res=bfs(grid);
        return res;
    }
    int bfs(vector<vector<int>>&grid){
        int res=0;
        int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

        while(!q.empty()){
            auto org=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x=org.first+dx[i],y=org.second+dy[i];               
                if(x>=0&&x<n&&y>=0&&y<m&&visit[x][y]==0){
                    if(grid[x][y]==2){
                        visit[x][y]=1;
                        q.emplace(make_pair(x,y));
                    }else if(grid[x][y]==1){
                        grid[x][y]=2;
                        visit[x][y]=1;
                        time[x][y]=time[org.first][org.second]+1;
                        q.emplace(make_pair(x,y));     
                    }
                    
                }
            }
            
        }
        // 统计
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visit[i][j]==0&&grid[i][j]==1){
                    res= -1;
                    flag=true;
                    break;
                }
                if(grid[i][j]==2){
                    res=max(res,time[i][j]);
                }
            }
            if(flag){
                break;
            }
        }
        cout<<"time"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                cout<<time[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"grid:"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        return res;
        
    }
    queue<pair<int,int>>q;
    vector<vector<int>>visit;
    vector<vector<int>>time;
    int n,m;
};
int main(){
    // vector<vector<int>>grid={{2,1,1},{1,1,0},{0,1,1}};
     vector<vector<int>>grid={{2,1,1},{1,1,1},{0,1,2}};
    
    Solution s;
    cout<<s.orangesRotting(grid);
    
}