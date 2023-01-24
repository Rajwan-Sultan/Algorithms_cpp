#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int> graph[N];
int vis[N];
/* 
5 3
1 2
3 1
4 5
Output: DAG
5 4
1 2
3 1
4 5
5 4
Output: Not DAG
   
    */

bool dfs(int src){

    vis[src] =1;
    for(auto it:graph[src]){
        if(!vis[it]){// if a node is visited
        bool found=dfs(it);
        if(found) return true;
        }
        else if(vis[it]==1){// if a node is paused
            return true;
        }
        else if(vis[it]==2) continue;// if a node is done
    }
    vis[src] =2;//Done
    return false;
}

int main()
{
    int n,e,mx=INT_MIN,mn=INT_MAX;
    cin >> n >> e;
    while (e--) 
    {
        int x,y;cin >> x >> y;
        graph[x].push_back(y);
        mn=min(mn,min(x,y));
        mx=max(mx,max(x,y));
    }

    bool found=false;
    for (int i = mn; i <= mx; i++)
    {
        if(!vis[i]){
        bool x=false;
        x=dfs(i);
        if(x) { 
            found=true; 
            break;
            }
        }

    }
    if(found) cout<<"Not DAG"<<endl;
    else cout<<"DAG"<<endl;
    return 0;
}