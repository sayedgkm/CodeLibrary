// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                    long long
#define        f(x,y,z)              for(int x=y;x<z;x++)
#define        take1(a);             int a;scanf("%d",&a);
#define        take2(a,b);           int a;int b;scanf("%d%d",&a,&b);
#define        take3(a,b,c);         int a;int b;int c;scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);       int a;int b;int c;int d;scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                   pair<int,int>
#define        mem(a,x)              memset(a,x,sizeof(a))
#define        N                     1000010
#define        M                     1000000007
#define        pi                    acos(-1.0)
using namespace std;
string a,b,c;int lena,lenb,ans; int dp[2005][2005];
int mini(int xx,int yy,int zz){
   return min(xx,min(yy,zz));
}
int edit(int i,int j){
   for(int i=0;i<=lena;i++){
        for(int j=0;j<=lenb;j++){
             if(i==0) dp[i][j]=j;
                else if(j==0) dp[i][j]=i;
                   else if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
                      else {
                dp[i][j]=mini(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1);
       }
    }
 }


return dp[lena][lenb];

}
int main()
{
    take1(test);
    while(test--){
            f(i,0,2005){
            dp[0][i]=dp[i][0]=0;
            }
  cin>>a>>b;
  lena=a.length();
  lenb=b.length();
  cout<<edit(0,0)<<endl;
    }
return 0;
}

