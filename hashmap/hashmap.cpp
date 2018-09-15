//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
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
#define        eps                             1e-9
#define        debug(x)                        cerr << #x << " is " << x << endl;
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
///******************************************START******************************************

 struct hashmap{
    public:
    static const int mod=1000003;
//    int nextprime(int n){
//      for(; ;n++){
//        bool f=0;
//        for(int i=2;i*i<=n;i++) {
//            if(n%i==0) f=1;
//            break;
//         }
//           if (!f) return n;
//       }
//     }
//
//    hashmap(){}
//    hashmap(int m){
//          mod=nextprime(m);
//     }
     vector<ll> *key= new vector<ll > [mod+1];
     vector<ll> *val= new vector<ll > [mod+1];
     inline int pos(ll x){
         int newx=x%mod;
         FOR(i,0,key[newx].size()) if(key[newx][i]==x) return i;
         return -1;
     }
    void add(ll x,ll v){
        int newx=x%mod;
        int i=pos(x);
        if(i==-1) {
            key[newx].pb(x);
            val[newx].pb(v);
        } else {
           val[newx][i]+=v;
        }
    }
    void insert(ll x,ll v){
          int newx=x%mod;
        int i=pos(x);
        if(i==-1) {
            key[newx].pb(x);
            val[newx].pb(v);
        } else {
           val[newx][i]=v;
        }
    }
    ll find(ll x){
        int newx=x%mod;
        int i=pos(x);
        if(i==-1) {
           return 0;
        } else {
           return val[newx][i];
        }
    }
      void erase(ll x){
         int newx=x%mod;
        int i=pos(x);
        if(i!=-1) {
           val[newx][i]=0;
        }
      }
   void clear() {
     FOR(i,0,mod+1) key[i].clear(),val[i].clear();
   }
};
int main(){
    #ifdef sayed
     // freopen("in.txt","r",stdin);
     //freopen("out.txt","w",stdout);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);


return 0;
}

