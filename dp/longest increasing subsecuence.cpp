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
using namespace std;
int ar[N];
int tr[3*N];
int main()
{
    f(i,0,100000)
    tr[i]=1e7;
    tr[0]=-10;
    int ar[]= {0, 10, 9, 10, 8, 12, 14, 15, 6};
    int lis=0,maxi=0,el;
    f(i,1,9)
    {
        int low=1;
        int hi=8;
        int counter=0,mid;
        while(low<hi)
        {
            mid=(low+hi)/2;
            if(tr[mid]>ar[i])
                hi=mid;
            else
                low=mid+1;
        }
        tr[low]=ar[i];

        maxi=max(low,maxi);
    }

    cout<<maxi<<endl;
    f(i,0,100000)
    tr[i]=1e7;
    tr[0]=-10;
    lis=0,maxi=0,el;
    f(i,1,9)
    {
        el=lower_bound(tr+1,tr+9,ar[i])-tr;
        tr[el]=ar[i];
        maxi=max(maxi,el);
    }

    cout<<maxi<<endl;

    return 0;
}
/// printing LIS
/* #include<bits/stdc++.h>
#define N 100
using namespace std;
int main(){
 int n, a[N], b[N], f[N], answer=0;
   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i];
 for (int i=1; i<=n; i++){
     f[i]=lower_bound(b+1, b+answer+1, a[i])-b;
     answer=  max(answer, f[i]);
     b[f[i]]=a[i];
  }

  printf("%d\n", answer);

  vector<int> T;

  int require = answer;
  for (int i=n; i>=1; i--)
  if (f[i]==require){
     T.push_back(a[i]);
     require--;
  }
  // then print T with reversed order
  int i=T.size();
  while (i--) printf("%d ", T[i]);
  printf("\n");
}
*/

