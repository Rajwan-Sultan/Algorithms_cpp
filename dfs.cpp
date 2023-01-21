#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int> graph[N];
int vis[N];

void dfs(int src){
    cout<<src<<" ";
    vis[src] =1;
    for(auto it:graph[src]){
        if(!vis[it])
        dfs(it);
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
0 1 2 3 4 5 
 */

int main()
{   int n,edges;
    cin >> n >> edges;
    while(edges--){
        int x,y;cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int src;cin >> src;
    dfs(src);

    return 0;
}