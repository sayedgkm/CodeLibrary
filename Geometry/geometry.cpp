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
#define        All(x)                          x.begin(),x.end()
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
struct point{
  double x,y;
  point(){}
  point(double xx,double yy) {x=xx,y=yy;}
}P[10];
struct vec{
  double x,y;
  vec(){}
  vec(point xx,point yy) {x=yy.x-xx.x,y=yy.y-xx.y;}

};
inline double dotproduct(vec a,vec b){
   return (a.x*b.x+a.y*b.y);
}
inline double crossproduct(vec a,vec b){
   return (a.x*b.y-a.y*b.x);
}
inline double norm_sq(vec a){
  return (a.x*a.x+a.y*a.y);
}
inline double angle(point A,point B,point C){ ///will return ccw angle between ABC in Radian
    vec BA(B,A),BC(B,C);
   double ans = atan2(BC.y,BC.x)-atan2(BA.y,BA.x);
   if(ans<0) ans+=2*pi;
   return ans;
}
inline double triangleArea(point a,point b,point c) {  /// Area without division by 2
    double area=a.x*b.y+b.x*c.y+c.x*a.y;
    area-=(b.x*a.y+c.x*b.y+a.x*c.y);
    return area;
}
inline double area(int n){  /// Area of n-gon without division by 2
    double A=0;
     P[n].x=P[0].x;
     P[n].y=P[0].y;
    for(int i=0;i<n;i++){
        A+=(P[i].x*P[i+1].y-P[i+1].x*P[i].y);
    }
    return A<0?-A:A;
}
inline double Distance(point a,point b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

inline double pointSegmentDistance(point C,point A,point B) { ///AB is line segment and c is point
   vec BA(B,A);
   vec AB(A,B);
   vec AC(A,C);
   vec BC(B,C);
   double dot = dotproduct(BA,AC);
   if(dot>=0) return Distance(A,C);
   dot = dotproduct(AB,BC);
   if(dot>=0) return Distance(B,C);
   return fabs(crossproduct(AB,AC)/sqrt(norm_sq(AB)));  /// magnitude of vector AB = sqrt(norm_sq(AB));
}

struct line { // Creates a line with equation ax + by + c = 0
    double a, b, c;
    line() {}
    line( point p1,point p2 ) {
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.x * p2.y - p2.x * p1.y;
    }
};

inline bool eq(double a, double b) { return fabs( a - b ) < eps; } //two numbers are equal

inline line findPerpendicularLine( line L, point P ) {
    line res; //line perpendicular to L, and intersects with P
    res.a = L.b, res.b = -L.a;
    res.c = -res.a * P.x - res.b * P.y;
    return res;
}

inline bool intersection(line L1, line L2, point &p ) {
    double det = L1.a * L2.b - L1.b * L2.a;
    if( eq ( det, 0 ) ) return false;
    p.x = ( L1.b * L2.c - L2.b * L1.c ) / det;
    p.y = ( L1.c * L2.a - L2.c * L1.a ) / det;
    return true;
}
inline double pointLineDistance( point P, line L ) {     /// using Distance formula,link https://www.intmath.com/plane-analytic-geometry/perpendicular-distance-point-line.php
    return fabs( L.a * P.x + L.b * P.y + L.c ) / sqrt( L.a * L.a + L.b * L.b );
}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);




  point a,b,c;
  a.x=1;
  a.y=0;
  b.x=0;
  b.y=0;
  c.x=0;
  c.y=1;
  line x = line(a,b);
    cout<<pointLineDistance(c,x)<<endl;
    cout<<pointSegmentDistance(c,a,b)<<endl;
    cout<<angle(c,b,a)*180/pi<<endl;
    cout<<atan2(1,0)*180/pi<<endl;

return 0;
}

