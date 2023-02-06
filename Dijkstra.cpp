#include <bits/stdc++.h>
using namespace std;
/* 
! https://codeforces.com/problemset/problem/20/C
 */
int n,m;
const int N=1e5+5;
const long long INF=1e18;
vector<pair<int,int>> g[N];
int vis[N],parent[N];

void dijkstra(int src){
    vector<long long> d(N,INF);//(size,value)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    d[src]= 0;
    pq.push({0,src});// {distance,node}

    while (!pq.empty())
    {
        pair<int,int> head = pq.top();
        pq.pop();
        int selected_node = head.second;
        if (!vis[selected_node]){
            vis[selected_node]=1;// if u is not visited then make it visited
            for (auto i: g[selected_node])
            {
                int node=i.first;
                int cost=i.second;
                if(d[selected_node]+cost<d[node]){
                    d[node]=d[selected_node]+cost;
                    parent[node]=selected_node;
                    pq.push({d[node],node});
                }
            }
        }
    }
    
}

int main()
{

    cin >>n>>m;
    while(m--){
        int x,y,w;cin >>x>>y>>w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    int src=1;
    dijkstra(src);
    if(vis[n]==0){
        cout<<-1<<endl;
        return 0;
    }
    
    int current_node=n;
    vector<int> path;
    while (true)
    {
        path.push_back(current_node);
        if(current_node==src) break;
        current_node=parent[current_node];
    }
    
    reverse(path.begin(),path.end());
    for(int node:path){
        cout<<node<<" ";
    }

    return 0;
}