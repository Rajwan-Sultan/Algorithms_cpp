#include <bits/stdc++.h>
using namespace std;
/* Course Schedule (CSES) */
/* 
5 3
1 2
3 1
4 5
output:4 5 3 1 2(Possible because of DAG)


5 4
1 2
3 1
4 5
5 4
output: Impossible(It's not a DAG that's why it is impossible)
 */

const int N=2e5;
vector<int> graph[N];
int vis[N];
int vis1[N];
int done[N];
stack<int> st;

bool detect_cycles(int src){
    vis[src] = 1;
    for(int i:graph[src]){
        if(!vis[i]){
            bool found = detect_cycles(i);
            if(found) return true;
        }
        else if(vis[i] == 1) return true;
    }
    vis[src]=2;
    return false;
}

void dfs1(int src){
    vis1[src] =1;
    for(auto it:graph[src]){
        if(!vis1[it])
        dfs1(it);
    }
    if(!done[src])
    {
        st.push(src);
        done[src] =1;
    }
    // st.push(src);
}

int main()
{

    int n,e,mx=INT_MIN,mn=INT_MAX;cin >> n >> e;
    while (e--) 
    {
        int x,y;cin>>x>>y;
        graph[x].push_back(y);
        mx=max(mx,max(x,y));
        mn=min(mn,min(x,y));
    }

    bool found=false;
    for(int i=mn;i<=mx;i++){
        if(!vis[i]){
        bool x=false;
        x=detect_cycles(i);
        if(x){
            found=true;
            break;
        }
        }
    }

    if(found) cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i=mn; i<=mx;i++){
            if(!vis1[i]) dfs1(i);
        }
        while (!st.empty())
        {
            int f=st.top();
            cout<<f<<" ";
            st.pop();
        }
        
    }

    return 0;
}