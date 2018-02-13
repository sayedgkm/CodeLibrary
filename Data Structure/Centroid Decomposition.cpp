#include <bits/stdc++.h>
#define  ll         long long
#define  pb         push_back
#define  CLR(ar)    memset(ar,0,sizeof(ar))
#define  N          200010
using namespace std;
int subtree[N];
int del[N];
vector<int> adj[N];
vector<int> centroid_tree[N];
int root;      /// 0 based node
int total_node = 0;
void dfs(int u,int p = -1) {
    subtree[u] = 1;
    total_node++;
    for(int i = 0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(del[v]||v==p) continue;
        dfs(v,u);
        subtree[u] += subtree[v];
    }
}
int GetCenter(int u,int p=-1){
    for(int i = 0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if(del[v]||v==p) continue;
        if(subtree[v]>total_node/2) return GetCenter(v,u);
    }
    return u;
}

void decompose(int u,int p = -1) {
    del[u] = 1;
    for(int i = 0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(del[v]||v==p)  continue;
        total_node = 0;
        dfs(v);
        int c = GetCenter(v);
        centroid_tree[u].pb(c);
        centroid_tree[c].pb(u);
        decompose(c,u);
    }
}
void decompose_tree(int n){
    CLR(subtree);
    CLR(del);
    for(int i = 0;i<N;i++) centroid_tree[i].clear();
    dfs(0);
    root = GetCenter(0);
    decompose(root);
}

int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0)
    return 0;
}

