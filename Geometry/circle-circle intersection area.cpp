
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
#define        N                               100010
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
 long double distance(long double x1,long double y1,long double x2,long double y2){
   long  double dx=x1-x2;
    long double dy=y1-y2;
    return sqrt(dx*dx+dy*dy);

 }
long double intersectionArea(long double x1,long double y1,long double r1,long double x2,long double y2,long double r2){
   long double dist=distance(x1,y1,x2,y2);
    if(dist+eps>=r1+r2) return 0.0;
       long  double mn=min(r1,r2);
      if(fabs(r1-r2)+eps>=dist){
        return pi*mn*mn;
      }
    long  double angle1=acos((dist*dist+r1*r1-r2*r2)/(2*r1*dist));
        angle1*=2.0;
    long double angle2=acos((dist*dist+r2*r2-r1*r1)/(2*r2*dist));
        angle2*=2.0;
    long double area=r1*r1*angle1-r1*r1*sin(angle1);
    area+=r2*r2*angle2-r2*r2*sin(angle2);
    return area*0.5;
}
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    ll x1=lxt(),y1=lxt(),r1=lxt();
    ll x2=lxt(),y2=lxt(),r2=lxt();
    cout<<setprecision(20)<<intersectionArea(x1,y1,r1,x2,y2,r2)<<endl;

return 0;
}
