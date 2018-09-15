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
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
#define        eps                              1e-9
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
struct point {
    ll x,y;
};
point g;  /// g is left most point
ll triArea(point a,point b,point c) {
    ll area=a.x*b.y+b.x*c.y+c.x*a.y;
    area-=(b.x*a.y+c.x*b.y+a.x*c.y);
    return area;
}
ll dist(point a,point b) {
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool convexCompare(point a,point b) {
    ll area=triArea(g,a,b);
    if(area==0)  return dist(g,a)<dist(g,b);
     else return area>0;
}


point P[N];
int n,m;           /// given  n point in P[]
point hull[N];     /// After call convexHull() convex hull is ready in hull[]
                  /// with m points
void convexHull() {
    g=P[0];
    for(int i=0; i<n; i++) {
        if(P[i].x<g.x) g=P[i];
        else if(P[i].x==g.x&&P[i].y<g.y) g=P[i];
    }
    sort(P,P+n,convexCompare);
    int cur=0;
    if(n==1) {
        hull[cur]=(P[0]);
        cur++;
        m = cur;
        return;
    }
    if(n==2){
        hull[cur]=(P[0]);
        cur++;
        hull[cur]=(P[1]);
        cur++;
        m = cur;
        return;
    }
    hull[0]=P[0];
    hull[1]=P[1];
    hull[2]=P[2];
    cur=3;
    for(int i=3; i<n; i++) {
        ll area=triArea(hull[cur-2],hull[cur-1],P[i]);
        if(area>0) {
            hull[cur]=P[i];
            cur++;
        } else if(area==0) {
            /// Take action depending on which required
            hull[cur-1]=P[i];
        } else {
            cur--;
            i--;
        }
    }
    m=cur;
}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        P[i].x=nxt();
        P[i].y=nxt();
    }
    convexHull();
    puts("*********");
    for(int i=0;i<m;i++) cout<<hull[i].x<<" "<<hull[i].y<<endl;
return 0;
}
