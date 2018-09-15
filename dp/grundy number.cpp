

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
#define        N                               1010
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
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
///******************************************START******************************************
int n,m;
int grundy[N][N];
int dp[505][505];   /// grundy number sample code
int go(int x,int y) {
    if(grundy[x][y]!=-1) return grundy[x][y];
    set<int> st;
    for(int i=0; i<6; i++) {
        int newx=x+dx[i];   /// moves can vary depend on problem
        int newy=y+dy[i];
        if(newx<0||newx>=N||newy<0||newy>=N) continue;
        st.insert(go(newx,newy));
    }
    int ret=0;
    while(st.find(ret)!=st.end()) ret++;
    return grundy[x][y]=ret;
}
int main() {
    SET(grundy);
   /* for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(grundy[i][j]==-1) go(i,j);
        }
    }*/
    int test=nxt();
    int cs=1;
    while(test--) {
        int nim=0;
        int n=nxt();
        while(n--) {
            int a=nxt(),b=nxt();
            nim^=go(a,b);
        }
        if(!nim) printf("Case %d: Bob\n",cs++);
        else printf("Case %d: Alice\n",cs++);
    }

    return 0;
}
