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
int dx[]= {0,0,1,-1,-1,-1,1,1};
int dy[]= {1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos) {
    return n |((T)1<<pos);
    }
template < class T> inline T bitoff(T n,T pos) {
    return n & ~((T)1<<pos);
    }
template < class T> inline T ison(T n,T pos) {
    return (bool)(n & ((T)1<<pos));
    }
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
    scanf("%I64d",&aaa);
    return aaa;
    }
inline double dxt() {
    double aaa;
    scanf("%lf",&aaa);
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
vector<int>primes;
int mark[(N/32)+2];
void sieve(int n) {
    primes.push_back(2);
    for(int i=3; i*i<=n; i+=2)
        if(ison(i>>5,i&31)==0) /// i&31 = i%32
            for(int j = i*i; j <= n; j += i * 2)
                mark[j>>5] |=1<<(j&31) ;
    for (int i = 3; i <= n; i += 2)
        if (ison(i>>5,i&31)==0) primes.push_back(i);
    }

int main() {
    //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    sieve(100);
    for(int i=0;i<primes.size();i++)  cout<<primes[i]<<endl;
}

