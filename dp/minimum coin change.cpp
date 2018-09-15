// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        take1(a);                       scanf("%d",&a);
#define        take2(a,b);                     scanf("%d%d",&a,&b);
#define        take3(a,b,c);                   scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);                 scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                             pair<int,int>
#define        mem(a,x)                        memset(a,x,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
using namespace std;
int dp[100];
int main()
{
	for(int i=0;i<100;i++) dp[i] =1100000; int path[100] = { 0 };
	dp[0] = 0;
	int coin[] = {3,5}; int value = 16;   ///how many minimum number of coins needed to make value
	int numberofcoin=2;
	for(int i=0;i<numberofcoin;i++){
		for(int j=coin[i];j<=value;j++){
			if (dp[j - coin[i]] + 1<dp[j]){
				path[j] = coin[i];
			    dp[j]=dp[j-coin[i]]+1;
			}
        }
	}
	int p = value;  int index = value;
	while (p){

		cout << path[index] << " ";
		p -= path[index];
		index -= path[index];
  }
	puts("");
	cout << dp[value] << endl;
	return 0;
}
