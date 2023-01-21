#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int vis[N];
vector<int> graph[N];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty()){
        int f=q.front();
        cout<<f<<" ";
        q.pop();
        for(auto i:graph[f]){
            if(!vis[i]){
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}
/* 

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
0 1 2 5 3 4
 */
int main()
{
    int n,edges;
    cin >> n >> edges;
    while(edges--){
        int x,y;cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int src;cin >> src;
    bfs(src);

    return 0;
}