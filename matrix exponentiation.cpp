#include <bits/stdc++.h>
#define        ll                              long long
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
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
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

struct matrix{
  ll mat[10][10];
  int row,clm;
  matrix(){
     memset(mat,0,sizeof mat);
  }
  matrix(int a,int b){
       row=a;clm=b;
     memset(mat,0,sizeof mat);
  }
  void identity(){
      for(int i=0;i<row;i++) mat[i][i]=1;
  }
  void print(){
    for(int i=0;i<row;i++){
        for(int j=0;j<clm;j++) printf("%lld ",mat[i][j]);
        printf("\n");
    }
  }
}base(2,2),ans(2,2);
matrix mul(matrix a,matrix b){
    matrix c;
    c.row=a.row;
    c.clm=b.clm;
    for(int i=0;i<c.row;i++)
     for(int j=0;j<c.clm;j++){
         c.mat[i][j]=0;
         for(int k=0;k<a.clm;k++)
              c.mat[i][j]=(c.mat[i][j]+(a.mat[i][k]%M*b.mat[k][j]%M)%M)%M;
     }
     return c;
}
matrix power(matrix p,ll e){
     matrix ret(p.row,p.clm);
     ret.identity();
     while(e){
     if(e&1) ret=mul(p,ret);
     p=mul(p,p);
     e>>=1;
   }
   return ret;
}
int main(){
     // freopen("out.txt","w",stdout);
    matrix temp(4,4);
    temp.mat[0][1] = temp.mat[0][2]= temp.mat[0][3]=1;
    temp.mat[1][2]=1;
    temp.mat[2][0]=1;
    temp.mat[3][1]=1;
    temp.mat[3][2]=1;
    temp.print();
    temp = power(temp,3);
    temp.print();

    base.mat[0][0]=base.mat[0][1]=base.mat[1][0]=1;
    matrix ans=power(base,12);
    cout<<ans.mat[0][0]<<endl;
    cout<<ans.mat[1][0]<<endl;
    ans.print();
return 0;
}
