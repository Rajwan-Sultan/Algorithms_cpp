#include <bits/stdc++.h>
using namespace std;
// Building Teams --> CSES
/* 

Through graph coloring we can get a bipartite graph which divides into two teams and

5 3

1 2
1 3
4 5

Output: 1 2 2 1 2
1(1)--2(2)
|
3(2)

4(1)--5(2)
 */

const int N=2e5+5;
vector<int> graph[N];
int vis[N];

int color[N];

bool dfs(int src){
    // cout<<src<<" ";
    vis[src] =1;

    for(auto it:graph[src]){
        if(!vis[it])
        {// assign different color to adjacent nodes
            if(color[src]==1) color[it] =2;
            else color[it] =1;
            
            bool is_bicolorable=dfs(it);
            if(!is_bicolorable) return false;
        }
        else{
            //check if color is same or different
            if(color[src]==color[it]) return false;
        }
    }
    return true;
}

int main()
{
    int n,e;cin>>n>>e;
    while(e--){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);

    }

    // int src=0;
    // dfs(src);
    bool is_bicolorable = true;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            color[i]=1;
            bool ok=dfs(i);
            if(!ok){
                is_bicolorable=false;
                break;
            }
        }
    }
    if(!is_bicolorable) cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i=1;i<=n;i++){
            cout<<color[i]<<" ";
    }
    cout<<endl;
    }
    return 0;
}