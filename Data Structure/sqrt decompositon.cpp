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

ll ar[N];
int block=600;
vector<ll>v[610];
void update(int pos,ll val)
{
    int blocknumber =pos/block;
    ll oldval=ar[pos];
    ar[pos]=val;
    int l=lower_bound(ALL(v[blocknumber]),oldval)-v[blocknumber].begin();
    //  cout<<l<<" "<<v[blocknumber].size()<<endl;
    v[blocknumber][l]=val;
    sort(ALL(v[blocknumber]));
    // puts("d");
}
ll query(int l,int r,ll k)
{
    int i;
    int res=0;

    for(i=l; i<=r&&i%block; i++)
    {
        res+=ar[i]<k;
    }

    for(; i+block-1<=r; i+=block)
    {
        int blocknumber =i/block;
        res+=lower_bound(ALL(v[blocknumber]),k)-v[blocknumber].begin();
    }
    for(; i<=r; i++)
    {
        res+=ar[i]<k;
    }

    return res;

}
int main()
{
#ifdef sayed
    // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n=nxt();
    int  m=nxt();
    int u=nxt();
    FOR(i,0,n)
    {
        ar[i]=nxt();
        v[i/block].pb(ar[i]);
    }
    FOR(i,0,block) sort(ALL(v[i]));
    while(m--)
    {

        int l=nxt();
        int r=nxt();
        int k=nxt();
        int pos=nxt();
        l--,r--,pos--;
        ll res=query(l,r,k);
        // debug(res);
        update(pos,(ll)(res*u)/(r-l+1));
    }
    FOR(i,0,n)printf("%lld\n",ar[i]);

    return 0;
}

