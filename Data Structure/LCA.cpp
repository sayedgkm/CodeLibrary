#include <bits/stdc++.h>
#define  ll         long long
#define  pb         push_back
#define  CLR(ar)    memset(ar,0,sizeof(ar))
#define  SET(ar)    memset(ar,-1,sizeof(ar))
#define  N          200010
using namespace std;
vector<int>adj[N];
int table[32][N];  ///for sparse  table
int depth[N];     ///depth of each node from root
int parent[N];
void dfs(int s,int p,int d){
       parent[s]=p;
       depth[s]=d;
      for(int i=0;i<adj[s].size();i++){
         int t=adj[s][i];
         if(t==p) continue;
          dfs(t,s,d+1);
      }


}
void lca_init(int n){
   SET(table);
   for(int i=0;i<n;i++){
      table[0][i]=parent[i];
    }
    for(int i=1;(1<<i)<n;i++){
         for(int j=0;j<n;j++){
            if(table[i-1][j]!=-1)
                table[i][j]=table[i-1][table[i-1][j]];
        }
    }

}
int lca_query(int p,int q){  ///p && q are two nodes.
    if(depth[q]>depth[p])
        swap(p,q);
    int log=1;
    while((1<<log)<depth[p]) log++;
    for(int i=log;i>=0;i--){
        if(depth[p]-(1<<i)>=depth[q])  ///making same level of p and q
            p=table[i][p];
    }
    if(p==q)
        return p;
    for(int i=log;i>=0;i--){
        if(table[i][p]!=-1&&table[i][p]!=table[i][q])
            p=table[i][p],q=table[i][q];
    }
    return parent[p];

}




int main()
{
    // freopen("out.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
   dfs(0,-1,1);
   lca_init(n);
   while(1){
    int x,y;
    cin>>x>>y;
    cout<<lca_query(x,y)<<endl;
   }


      return 0;
}
/*
10 9
0 2
0 1
1 3
3 8
3 9
1 4
1 5
1 6
1 7
9 7
*/

