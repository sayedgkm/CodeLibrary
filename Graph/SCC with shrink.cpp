// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        take1(a);                       scanf("%d",&a);
#define        take2(a,b);                     scanf("%d%d",&a,&b);
#define        take3(a,b,c);                   scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);                 scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                             pair<int,int>
#define        mem(a,x)                        memset(a,x,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
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
#define gray 1
#define white 0
#define black 2
vector<int> adj[N]; int counter=1;
int disc[N],low[N]; ///disc[N] is discovery time;
vector<int> st;
int visited[N];
int cycle[N];
void tarjan(int u){
    disc[u]=low[u]=counter++;
    visited[u]=gray;
    st.pb(u);
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(visited[v]==white)
               tarjan(v);
        if(visited[v]==gray)   ///Back edge means gray to gray..so cycle found
              low[u]=min(low[u],low[v]);
         }
         if(low[u]==disc[u]){
            while(1){
                int x=st.back();
                st.pop_back();
                visited[x]=black;
                cycle[x]=u;
                if(x==u) break;
            }

    }

}
vector<int> dag[N];
void shrink(int node){
    for(int i=0;i<node;i++){
        for(int j=0;j<adj[i].size();j++){
            int t=adj[i][j];
            if(cycle[i]!=cycle[t]){
                dag[cycle[i]].pb(cycle[t]);
            }

        }

    }

}
void createDag(int n){
    counter=1; st.clear();
    for(int i=0;i<n;i++){
        disc[i]=low[i]=visited[i]=cycle[i]=0;
        dag[i].clear();
    }
    for(int i=0;i<n;i++){
        if(!visited[i]) tarjan(i);
    } shrink(n);
}
void printdag(int u){

    for(int i=0;i<dag[u].size();i++){
        int v=dag[u][i];
        printf("%d %d\n",u,v);
        printdag(v);
    }
}
int main()
{
    // freopen("out.txt","w",stdout);
    int n=nxt(),m=nxt();
    f(i,0,m){
       int a=nxt(),b=nxt();
       adj[a].pb(b);
    }
    tarjan(0);
    shrink(n);
    printdag(0);
  //  for(int i=0;i<=5;i++) cout<<cycle[i]<<" ";
    puts(" ");

      return 0;
}
/*7 9
  0 1
  2 1
  1 3
  3 2
  3 4
  4 5
  5 7
  7 6
  6 4 */


