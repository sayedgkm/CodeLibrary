// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               100010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
using namespace std;
int dx[]= {0,0,1,-1,-1,-1,1,1};
int dy[]= {1,-1,0,0,-1,1,1,-1};
template < class T> inline T gcd(T a, T b) {
    while(b) {
        a%=b;
        swap(a,b);
    }
    return a;
}
template <typename T> string NumberToString ( T Number ) {
    ostringstream ss;
    ss << Number;
    return ss.str();
}
inline int nxt() {
    int aaa;
    scanf("%d",&aaa);
    return aaa;
}
inline ll lxt() {
    ll aaa;
    scanf("%lld",&aaa);
    return aaa;
}
template <class T> inline T bigmod(T p,T e,T m) {
    T ret = 1;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret * p) % m;
        p = (p * p) % m;
    }
    return (T)ret;
}
#define sayed
#ifdef sayed
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif
struct debugger {
    template<typename T> debugger& operator , (const T& v) {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
///******************************************START******************************************
#define  gray  1
#define  white 0
#define  black 2
vector<int> adj[N];
int disc[N],low[N],color[N],visited[N];
int counter=1;
int root;
int artpoint(int s,int p) {
    disc[s]=low[s]=counter++;  ///discovery time and lowest back edge extension
    color[s]=gray;
    int child=0; ///only for root.
    for(int i=0; i<adj[s].size(); i++) {
        int t=adj[s][i];
        if(t==p)  ///don't go to parent
            continue;

        if(color[t]==white) {   ///Tree Edge
            child++;
            artpoint(t,s);
            if(s==root&&child>1) {  ///for root articulation point is different case
                if(!visited[s])
                    printf("Art point :%d\n",s);
                visited[s]=1;
            }
            if(disc[s]<=low[t]&&s!=root) {
                if(!visited[s])
                    printf("Art point :%d\n",s);  ///S is Articulation point for t
                visited[s]=1;
            }
            low[s]=min(low[s],low[t]);
        } else if(color[t]==gray) {         ///Back Edge
            low[s]=min(low[s],disc[t]);
        }
    }

}
int main() {
    // freopen("out.txt","w",stdout);

    int n=nxt();
    int m=nxt();
    while(m--) {
        int a,b;
        a=nxt();
        b=nxt();
        adj[a].pb(b);
        adj[b].pb(a);

    }
    f(i,1,n+1) {
        if(!color[i]) {
            root =i;
            artpoint(i,-1);
        }
    }

    return 0;
}

