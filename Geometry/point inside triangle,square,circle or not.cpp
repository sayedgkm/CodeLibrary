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
#define        N                               200010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             9e9+100
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
double  area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
bool insideTriangle( int x, int y,int x1, int y1, int x2, int y2, int x3, int y3)
{
   double A = area (x1, y1, x2, y2, x3, y3);
   double  A1 = area (x, y, x2, y2, x3, y3);
   double  A2 = area (x1, y1, x, y, x3, y3);
   double  A3 = area (x1, y1, x2, y2, x, y);
   return (A == A1 + A2 + A3);
}
bool insideCircle(int x,int y,int cx,int cy,int r) {
   double dist=(cx-x)*(cx-x)+(cy-y)*(cy-y);
   return dist<=r*r;
}
bool insideSquare(int x,int y,int lx,int ly,int l) {   ///lx,ly is the lower left corner of square
    if(x>=lx&&x<=lx+l&&y>=ly&&y<=ly+l) return true;
    return false;
}
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int test=nxt();
   while(test--) {
      int q=nxt();
      set<pii>st;
      FOR(i,0,q) {
         char c[2];
         scanf("%s",c);
        int x1,y1,x2,y2,x3,y3;
        if(c[0]=='T')  {
            x1=nxt();
            y1=nxt();
            x2=nxt();
            y2=nxt();
            x3=nxt();
            y3=nxt();
        } else  {
             x1=nxt();
            y1=nxt();
            x2=nxt();
        }
        FOR(j,-110,110) {
        FOR(k,-110,110) {
            if(c[0]=='T'){
             if(insideT(j,k,x1,y1,x2,y2,x3,y3)) st.insert(pii(j,k));
            }
            else if(c[0]=='C'){
                    //cout<<5<<endl;
                    if(insideC(j,k,x1,y1,x2)) st.insert(pii(j,k));
            }
             else {
                    if(insideS(j,k,x1,y1,x2)) st.insert(pii(j,k));
             }
          }
        }
      }
     printf("%d\n",(int)st.size());
   }

return 0;
}

