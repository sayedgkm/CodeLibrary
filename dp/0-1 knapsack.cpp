#include <bits/stdc++.h>
#define        ll                    long long
#define        pii                   pair<int,int>
#define        mem(a,x)              memset(a,x,sizeof(a))
#define        N                     1000010
#define        M                     1000000007
#define        pi                    acos(-1.0)
using namespace std;
int dp[100][10000];int weight[100],cost[100];
bool taken[100][10000];
int knapsack(int n,int cap){
    for(int i=1;i<=n;i++){
        for(int w=1;w<=cap;w++){
            if(w>=weight[i]){
                if(cost[i]+dp[i-1][w-weight[i]]>dp[i-1][w]){
                    taken[i][w]=1;
                } else taken[i][w]=0;
                dp[i][w]=max(cost[i]+dp[i-1][w-weight[i]],dp[i-1][w]);
            }
            else {
                dp[i][w]=dp[i-1][w];
                taken[i][w]=0;
            }

        }
    }

    return dp[n][cap];
}
void printItem(int item,int total){
    while(item>0){
        if(taken[item][total]){
            printf("%d ",item);          /// printing i'th item
            total-=weight[item];
            item--;
        } else item--;

   }

}
int main()
{
    int n,cap;cin>>n>>cap;
    for(int i = 1;i<=n;i++){
        cin>>weight[i]>>cost[i];
    }
    int res=knapsack(n,cap);
    cout<<res<<endl;
    printItem(n,cap);

return 0;
}
