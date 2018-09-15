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
#endif
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///******************************************START******************************************
struct EDGE{
 ll u,v,cost;
}edge[N];
bool compare(EDGE a,EDGE b){
  return a.cost<b.cost;
 }
 int path[N];
void root(int n){
   for(int i=0;i<=n;i++)
       path[i]=i;
}
int findUnion(int x){
   if(path[x]==x) return x;
    return path[x]=findUnion(path[x]);

}
ll mst(int n,int m){
    root(n);
    sort(edge,edge+m,compare);
 ll ans=0;int c=0;
 for(int i=0;i<m;i++){
      int u=findUnion(edge[i].u);
      int v=findUnion(edge[i].v);
      if(u!=v){
        ans+=edge[i].cost;
        path[u]=v;
        c++;
        if(c==n-1) break;
      }

   }
   return ans;
}
int main()
{
       int n=nxt(),m=nxt();
       f(i,0,m){
          int u=nxt(),v=nxt(),c=nxt();
          edge[i].u=u;
          edge[i].v=v;
          edge[i].cost=c;

       }
       cout<<mst(n,m)<<endl;

      return 0;
}

