 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               200010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                              (1e9)+1000
#define        eps                             1e-9
#define        ALL(x)                          x.begin(),x.end()
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
#ifdef sayed
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " is " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " is " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************

/*
    all nodes are completely renamed
    BC contains the block-cut tree
    NN is total nodes in BCT
    u in original graph is in node[u] in BCT
    if ap[u] == true, then u is articulation point in original graph
    if cut[u] == true, then u is a cut node in BCT, else this represents a biconnected component
*/


int disc[N], low[N], parent[N], ap[N];
int node[N], cut[N];
vector<int> A[N], BC[N];
stack< pair<int, int> >_stack;
vector<int> _temp;
int NN;

void extract_biconnected_component(int u = -1, int v = -1)
{
    int id = ++NN;
    _temp.clear();

    while (!_stack.empty())
    {
         pair<int, int>  t = _stack.top();
        _stack.pop();
        _temp.push_back(t.first), _temp.push_back(t.second);
        if (t == make_pair(u, v)) break;
    }

    sort(_temp.begin(), _temp.end());
    _temp.erase(unique(_temp.begin(), _temp.end()), _temp.end());

    for (int i=0; i<_temp.size(); i++)
    {
        int u = _temp[i];
        if (ap[u])
        {
            if (node[u] == -1) node[u] = ++NN;
            cut[node[u]] = true;

            BC[node[u]].push_back(id);
            BC[id].push_back(node[u]);
        }
        else node[u] = id;
    }
}

void dfs_visit(int u)
{
    static int time = 0;
    int children = 0;

    disc[u] = low[u] = ++time;

    for (int i=0; i<A[u].size(); i++)
    {
        int v = A[u][i];
        if (disc[v] == -1)
        {
            _stack.push(make_pair(u, v));
            children++;
            parent[v] = u;
            dfs_visit(v);

            low[u]  = min(low[u], low[v]);
            if ((parent[u] == -1 && children > 1) || (parent[u] != -1 && low[v] >= disc[u]))
            {
                ap[u] = true;
                extract_biconnected_component(u, v);
            }
        }
        else if (v != parent[u] && disc[v] < disc[u])
        {
            _stack.push(make_pair(u, v));
            low[u]  = min(low[u], disc[v]);
        }
    }

    if (parent[u] == -1) extract_biconnected_component();
}

void block_cut(int n)
{
    int i, j, k;
    NN = 0;
    for (i=0; i<n; i++) {
        disc[i] = -1;
        ap[i] = 0;
        parent[i] = -1;
        node[i] = -1;
        cut[i] = 0;
    }
    for (i=0; i<n; i++) if (disc[i] == -1) dfs_visit(i);
}

int main()
{
    int n, m, i, j, k;

    n= nxt();
    m = nxt();
    for(int i =0;i<m;i++) {
        int a= nxt();
        int b = nxt();
        A[a].pb(b);
        A[b].pb(a);
    }
    block_cut(n);
    for(int i = 1;i<=n;i++) {
        debug(ap[i],node[i],cut[i]);
    }


    return 0;
}
