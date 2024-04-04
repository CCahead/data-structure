#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>g(numCourses,vector<int>(numCourses,INT_MIN)); // 代表边之间的关系？
        vector<int>d(numCourses,0); //INT_MIN代表没有入度 我们着重需要记录入度的关系
        vector<int>visited(numCourses,0);
        queue<int>q;
        vector<int>res;
        for(auto e:prerequisites){
            g[e[1]][e[0]]=1; //这个用来统计边关系
            d[e[0]]++; //用来统计入度情况
        }
        for(int i=0;i<numCourses;i++){
            if(!d[i]){
                q.emplace(i);
            }//把没有入度的节点加入到队列当中来
        }
        while(!q.empty()){
            int node = q.front(); //current 
            visited[node]=1;
            q.pop();
            res.push_back(node);
            for(int i=0;i<numCourses;i++){
                if(!visited[i]&&g[node][i]!=INT_MIN){
                    // check the next node i: 
                    // there's a relation: node->i
                    d[i]--;
                    if(d[i]==0){
                        q.emplace(i);
                        visited[i]=1;
                    }
                }
            }
        }
        return res;
        
    }
}; 
// 0--1--3
//  --2--3


int main(){
    Solution s;
    int numCourses=4;
    // vector<vector<int>>prequisities(numCourses,vector<int>(2));
 //{[1,0],[2,0],[3,1],[3,2]};
    
    vector<vector<int>>prequisities={{1,0},{2,0},{3,1},{3,2}};
    // for(auto &e:prequisities){
    //     cout<<e[0]<<" "<<e[1]<<endl;
    // }
    vector<int>res = s.findOrder(numCourses,prequisities);
    for(auto e:res){
        cout<<e<<" ";
    }
}