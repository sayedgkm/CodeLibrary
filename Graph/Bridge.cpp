//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               100010
#define        M                               1000000007
#define        pia                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
#define sayed
#ifdef sayed
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///******************************************START******************************************


vector<int> adj[N];
int disc[N],low[N],color[N];
int counter=1;
int root;
void Bridge(int s,int p) {
    disc[s]=low[s]=counter++;  ///discovery time and lowest back edge extension
    color[s]=1;
    for(int i=0; i<adj[s].size(); i++) {
        int t=adj[s][i];
        if(t==p)  ///don't go to parent
            continue;
        if(!color[t]) {   ///Tree Edge
            Bridge(t,s);
            if(disc[s]<low[t])
                printf("Bridge : %d %d\n",s,t); ///s and t is a bridge
            low[s]=min(low[s],low[t]);
        } else               ///Back Edge
            low[s]=min(low[s],disc[t]);

    }

}
int main()
{
    // freopen("out.txt","w",stdout);

        int n=nxt();
        int m=nxt();
        while(m--){
            int a,b;
            a=nxt();
            b=nxt();
            adj[a].pb(b);
            adj[b].pb(a);

        }
        f(i,1,n+1){
          if(!color[i]){
                root =i;
               Bridge(i,-1);
          }
        }

      return 0;
}


