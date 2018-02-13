#include <bits/stdc++.h>
#define  ll         long long
#define  pb         push_back
#define  CLR(ar)    memset(ar,0,sizeof(ar))
#define  N          200010
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
int main()
{
#ifdef sayed
    // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    ordered_set x;
    x.insert(2);
    x.insert(-1);
    x.insert(-1);
    int n=2;
    cout<<*x.find_by_order(1)<<endl;   /// accessing by index
    cout<<x.order_of_key(3)<<endl;   /// how many Number are less than n
    /// rest of operation just like normal set


    return 0;
}
