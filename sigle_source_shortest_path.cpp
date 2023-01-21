#include <bits/stdc++.h>
using namespace std;


/* 

Only for unweighted graphs. Do BFS and count level

M---D---K---A
|   |   |
Z   S  | 
 \----/

0---1----2----3
    |    |
    |    |
    5----4
Input:
6 6
0 1
1 2
2 3
1 5
2 4
5 4
0
Output:
node 0 -> level: 0
node 1 -> level: 1
node 2 -> level: 2
node 3 -> level: 3
node 4 -> level: 3
node 5 -> level: 2
 */

const int N=1e5;
int vis[N];
int lvl[N];
vector<int> graph[N];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    lvl[src] = 0;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(auto i:graph[f]){
            if(!vis[i]){
                vis[i] = 1;
                lvl[i]=lvl[f]+1;
                q.push(i);
            }
        }
    }
}


int main()
{
    int n,edges,mn=INT_MAX,mx=INT_MIN;
    cin >> n >> edges;
    while(edges--){
        int x,y;cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        mn=min(mn,min(x,y));
        mx=max(mx,max(x,y));
    }

    int src;cin >> src;
    bfs(src);
    for(int i=mn;i<=mx;i++){
        cout<<"node "<<i<<" -> level: "<<lvl[i]<<endl;
    }
    return 0;

}