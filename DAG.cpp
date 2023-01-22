#include <bits/stdc++.h>
using namespace std;

const int N=2e5;
vector<int> graph[N];
int vis[N];

bool detect_cycle(int src){
    vis[src] =1;
    for(auto it:graph[src]){
        if(!vis[it]){
        bool got_cycle= detect_cycle(it);
        if(got_cycle) return true;
        }
        else if(vis[it]==1){
            return true;
        }
    }
vis[src] =2;
return false;
}

int main()
{
    int n,e;
    cin >> n >> e;
    int mx=INT_MIN,mn=INT_MAX;
    while (e--)
    {
        int x,y;cin >> x >> y;
        graph[x].push_back(y);
        mx=max(mx,max(x,y));
        mn=min(mn,min(x,y));

    }
    bool cycle_exists = false;
    for(int i=mn;i<=mx;i++){
        if(!vis[i]){
            bool cycle=detect_cycle(i);
            if(cycle){
                cycle_exists=true;
                break;
            }
        }
    }

    if(cycle_exists) cout<<"Cycle detected"<<endl;
    else cout<<"No cycle detected(DAG)"<<endl;

    
    return 0;
}
/* 
Round trip 2(CSES)

4 5
1 3
2 1
2 4
3 2
3 4
Output: Cycle detected

4 4
1 3
2 1
2 4
3 4
Output: No cycle detected(DAG)

 */