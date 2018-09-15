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
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T on(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
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
int dp[55][1005];
int n,k;
ll go(int egg,int floor){
    if(egg==1) return floor;
    if(floor<=1) return floor;
    if(dp[egg][floor]!=-1) return dp[egg][floor];
    ll p;ll mn=inf;
    for(int i=1;i<=floor;i++){   /// protita floor theke try korchi..
/// jodi i'th floor theke dim vhange floor 1 to i-1 porjonto next dim(dim-1) diye
/// try korbo,jodi na vhange then dim ta diyei i+1 floor to next floor gulate try korbo
        p=max(go(egg-1,i-1),go(egg,floor-i)); ///jehetu worst case so duitar max
        mn=min(mn,p); /// worst case er minimum
    }
 return dp[egg][floor]=mn+1;
}
int go(int egg,int floor){
  for(int i=1;i<=floor;i++) dp[1][i]=i;
  for(int i=2;i<=egg;i++) {

     for(int j=1;j<=floor;j++){
          dp[i][j]=inf;
        for(int k=1;k<=j;k++){
        dp[i][j]=min(dp[i][j],1+max(dp[i-1][k-1],dp[i][j-k]));
        }
     }
  }
return dp[egg][floor];
}
int main(){
     // freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   // cin.tie(0);
   int test=nxt();
   while(test--){
        CLR(dp);
    int p=nxt();n=nxt();k=nxt();
        printf("%d %d\n",p,go(n,k));

   }

return 0;
}

