/// Given a tree, every vertex has color.
///Query is how many vertices in
///subtree of vertex v are colored with color c?
int sz[maxn]; /// size of subtree
O(nlogn^2)
map<int, int> *cnt[maxn];
void dfs(int v, int p){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p){
           dfs(u, v);
           if(sz[u] > mx)
               mx = sz[u], bigChild = u;
       }
    if(bigChild != -1)
        cnt[v] = cnt[bigChild];
    else
        cnt[v] = new map<int, int> ();
    (*cnt[v])[ col[v] ] ++;
    for(auto u : g[v])
       if(u != p && u != bigChild){
           for(auto x : *cnt[u])
               (*cnt[v])[x.first] += x.second;
       }
    //now (*cnt[v])[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.

}
/// O(nlogn)
vector<int> *vec[maxn];
int cnt[maxn];
void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
           mx = sz[u], bigChild = u;
    for(auto u : g[v])
       if(u != p && u != bigChild)
           dfs(u, v, 0);
    if(bigChild != -1)
        dfs(bigChild, v, 1), vec[v] = vec[bigChild];
    else
        vec[v] = new vector<int> ();
    vec[v]->push_back(v);
    cnt[ col[v] ]++;
    for(auto u : g[v])
       if(u != p && u != bigChild)
           for(auto x : *vec[u]){
               cnt[ col[x] ]++;
               vec[v] -> push_back(x);
           }
    //now (*cnt[v])[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    // note that in this step *vec[v] contains all of the subtree of vertex v.
    if(keep == 0)
        for(auto u : *vec[v])
            cnt[ col[u] ]--;
}


///heavyLighttrics O(nlogn)

int cnt[N];
bool big[N];
int col[N];
int sz[N];
vector<int> adj[N];
void dfs(int u,int p=-1) {
    sz[u] = 1;
    for(auto it : adj[u]) {
        if(it==p) continue;
        dfs(it,u);
        sz[u] +=sz[it];
    }
}
void add(int u, int p, int x){
    cnt[ col[u] ] += x;
    for(auto v: adj[u])
        if(v != p && !big[v])
            add(v, u, x);
}
void dfs(int u, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto v : adj[u])
       if(v != p && sz[v] > mx)
          mx = sz[v], bigChild = v;
    for(auto v : adj[u])
        if(v != p && v != bigChild)
            dfs(v, u, 0);  // run a dfs on small childs and clear them from cnt
    if(bigChild != -1)
        dfs(bigChild, u, 1), big[bigChild] = 1;  // bigChild marked as big and not cleared from cnt
    add(u, p, 1);
    //now cnt[c] is the number of vertices in subtree of vertex u that has color c. You can answer the queries easily.
    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0)
        add(u, p, -1);
}
