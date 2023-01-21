#include <bits/stdc++.h>
using namespace std;

/* 
we don't need to make any adjacency lists for this
we just need to check that:
    1.if a box is valid/within the maze
    2.if a box is forbidden/wall?
    3.if a box is visited
we can just go to up,down,left,right directions
Adjacent Cells
(x,y)-->r-->(x,y+1)
(x,y)-->l-->(x,y-1)
(x,y)-->u-->(x-1,y)
(x,y)-->d-->(x+1,y)

5 8
########
#.A#...#
#.##.#B#
#......#
########

# -> -1
. -> 0

Output:
9
 */
int n,m;
const int N=2002;
int maze[N][N],vis[N][N],lvl[N][N];
// direction array
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

bool is_inside(pair<int,int> cord){// is inside the maze
    int x=cord.first;
    int y=cord.second;
    if(x>=0&&x<n && y>=0&&y<m) return true;
    else return false;
}

bool is_safe(pair<int,int> cord){// is valid
    int x=cord.first;
    int y=cord.second;
    if(maze[x][y]==-1) return false;
    else return true;
}

void bfs(pair<int,int> src){
    queue<pair<int,int>> q;
    vis[src.first][src.second]=1;
    lvl[src.first][src.second]=0;
    q.push(src);

    while (!q.empty()){
    pair<int,int> f=q.front();
    q.pop();

    int x=f.first,y=f.second;

    // getting the adjacent node
    for(int i=0;i<4;i++){
        int new_x=x+dx[i];
        int new_y=y+dy[i];
        pair<int,int> adj_node={new_x,new_y};// adj_node

        // check if in the maze && is it safe && is not visited
        if(is_inside(adj_node) && is_safe(adj_node) && !vis[new_x][new_y]){
            vis[new_x][new_y]=1;
            lvl[new_x][new_y]=lvl[x][y]+1;
            q.push(adj_node);
        }
    }
    
    }
    
}


int main()
{

    cin >> n>>m;

    pair<int,int> src,dst;
    for(int i=0;i<n;i++){
        string input;
        cin >> input;
        for(int j=0;j<m;j++){
            if(input[j]=='#')
            maze[i][j]=-1;
            else if(input[j]=='A')
            src={i,j};
            else if(input[j]=='B')
            dst={i,j};
        }
    }
    // initializing the level as -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            lvl[i][j]=-1;
        }
        
    }
    

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //     cout<<maze[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }

    bfs(src);
    if(lvl[dst.first][dst.second]==-1)
    cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        cout<<lvl[dst.first][dst.second]<<endl;
    }

    return 0;
}