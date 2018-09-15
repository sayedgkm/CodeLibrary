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
int dp[105][105]; string x, y; string s[105][105];
void lcs(int a, int b){

	for (int i = 1; i <= a; i++) for (int j = 1; j <= b; j++){
		if (x[i - 1] == y[j - 1]){
			dp[i][j] = 1 + dp[i - 1][j - 1]; s[i][j] = s[i - 1][j - 1] + x[i - 1];
		}
		else {
			if (dp[i - 1][j] > dp[i][j - 1]){
				dp[i][j] = dp[i - 1][j]; s[i][j] = s[i - 1][j];
			}
			else {
				dp[i][j] = dp[i][j-1]; s[i][j] = s[i][j-1];
			}

		}
	}
}
int main()
{
	cin >> x >> y;
	lcs(x.length(), y.length());
	cout << dp[x.length()][y.length()] << endl;
	cout << s[x.length()][y.length()] << endl;

	return 0;
}
