#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> adj_list[N];
int visited[N];

bool bfs(int node){
    queue<pair<int, int>> q;
    q.push({node, -1});
    visited[node] = 1;
    while(!q.empty()){
        int val = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(int adj_node : adj_list[val]){
            if(!visited[adj_node]){
                q.push({adj_node, val});
                visited[adj_node] = 1;
            }
            else if(adj_node != parent){
                return true;
            }
        }
    }
    return false;
}




int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }


    bool found = false;


    for(int i=1; i<=n; i++){
        if(!visited[i]){
            bool got_cycle = bfs(i);
            if(got_cycle){
                found = true;
                break;
            }
        }
    }


    if(found)
        cout<<"Cycle Found"<<endl;
    else
        cout<<"DAG"<<endl;


    return 0;
}
