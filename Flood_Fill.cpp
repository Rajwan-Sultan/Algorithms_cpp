#include <bits/stdc++.h>
using namespace std;
// counting rooms

/* 
5 8
########
#..#...#
####.#.#
#..#...#
########

output:
3

 */
int n,m;
const int N=2002;
int vis[N][N],graph[N][N];
int dx[]={0,0,-1,1},dy[]={1,-1,0,0};

pair<int,int> find(){// ! Finds the valid cell
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            if(!vis[i][j]&&graph[i][j]==0) return {i,j};
    }
    return {-1,-1};
}

void  dfs(pair<int,int> src){
        int f=src.first,s=src.second;
        vis[f][s] =1;
    for(int i=0;i<4;i++){
        int x=f+dx[i];
        int y=s+dy[i];
        pair<int,int> adj={x,y};
        if(!vis[x][y] && (x>=0&&x<n && y>=0&&y<m) &&  (graph[x][y]!=-1))
        dfs(adj);
    }

}


// void bfs(pair<int,int> src){
//     queue<pair<int,int>> q;
//     q.push(src);
//     vis[src.first][src.second]=1;
//     while(!q.empty()){
//         pair<int,int> f=q.front();
//         q.pop();
//         int x=f.first,y=f.second;
//         for(int i=0;i<4;i++){
//             int n_x=x+dx[i],n_y=y+dy[i];
//             pair<int,int> adj={n_x,n_y};
//             if(!vis[n_x][n_y] && (n_x>=0&&n_x<n && n_y>=0&&n_y<m) &&  (graph[n_x][n_y]!=-1)){
//                 vis[n_x][n_y]=1;
//                 q.push(adj);
//             }
//         }
//     }
// }

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            if(s[j]=='#') graph[i][j] = -1;
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<graph[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }

    int ct=0;
    while(1){
        if(find()==pair<int,int>(-1,-1)){
            break;
        }
        dfs(find());
        // bfs(find());
        ct++;
    }
    cout<<ct<<endl;

    return 0;
}