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
multiset<pii> st;
multiset<int> adj[N];
vector<int> euler_cycle; /// 0 based node
void find_cycle(int u) {
    while(adj[u].size()) {
        int it = *adj[u].begin();
        int x= min(u,it);
        int y =max(u,it);
        adj[u].erase(adj[u].find(it));
        adj[it].erase(adj[it].find(u));
        find_cycle(it);
    }
    euler_cycle.pb(u);

}
int degree[N];
bool is_euler_cycle(int n) {
    for(int i =0;i<n;i++) {
        if(degree[i]%2) return false;
    }
    return true;
}
bool is_euler_path(int n) {
    int odd = 0;
    int even = 0;
    for(int i =0;i<n;i++){
        if(degree[i]%2==0) even++;
        else odd++;
    }
    return odd==2;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    int m = nxt();
    for(int i = 0;i<m;i++) {
        int a= nxt();
        int b = nxt();
        adj[a].insert(b);
        adj[b].insert(a);
        degree[a]++;
        degree[b]++;

    }
    if(is_euler_cycle(n)){
        cout<<"cycle found"<<endl;
        find_cycle(0);
        reverse(ALL(euler_cycle));
        for(auto it: euler_cycle ) {

            cout<<it<<" ";
        }
        cout<<endl;
    }
    else if(is_euler_path(n)){
        cout<<"path found"<<endl;
        int a = -1;
        int b = -1;
        for(int i = 0;i<n;i++){
            if(degree[i]%2){
                if(a==-1) a= i;
                else b = i;
            }
        }
        find_cycle(a);
        reverse(ALL(euler_cycle));
        for(auto it: euler_cycle ) {

            cout<<it<<" ";
        }
        cout<<endl;

    } else {
        cout<<"Not found"<<endl;
    }





    return 0;
}
