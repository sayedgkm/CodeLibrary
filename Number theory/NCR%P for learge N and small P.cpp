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
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
///******************************************START******************************************
/// using strange factorial
/// will work in range n,r<=1e18 && MOD<=1e6 and MOD must be prime
ll countFact(ll n, ll p)
{
    ll k=0;
    while (n>=p)
    {
        k+=n/p;
        n/=p;
    }
    return k;
}
 /*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(ll n, ll MOD)
{
    return bigmod(n,MOD-2,MOD);
}

long long factMOD(ll n, ll MOD)
{
    long long res = 1;
    while (n > 0)
    {
        for (int i=2, m=n%MOD; i<=m; i++)
            res = (res * i) % MOD;
        if ((n/=MOD)%2 > 0)
            res = MOD - res;
    }
    return res;
}

long long ncr(ll n, ll r, ll MOD)
{

    if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
        return 0;

    return (factMOD(n, MOD) *
            ((InverseEuler(factMOD(r, MOD), MOD) *
            InverseEuler(factMOD(n-r, MOD), MOD)) % MOD)) % MOD;
}
/// using locus theorem*******************************************
/// using strange factorial
/// will work in range n,r<=1e18 && MOD<=1e6 and MOD must be prime
ll fact[N];

long long Smallncr(ll n, ll r, ll MOD)
{
   ll temp=fact[n];
   ll temp1=(fact[r]*fact[n-r])%MOD;

   temp1=bigmod(temp1,MOD-2,MOD);

   return (temp*temp1)%MOD;
}

long long Lucas(ll n, ll m, ll p)
{
    if (n==0 && m==0) return 1;
    ll ni = n % p;
    ll mi = m % p;
    if (mi>ni) return 0;
    return (Lucas(n/p, m/p, p) * Smallncr(ni, mi, p))%p;
}

long long NCR(ll n, ll r, ll MOD)
{
    fact[0]=fact[1]=1;
    for(int i=2;i<=MOD;i++) fact[i]=(fact[i-1]*i)%MOD;
    return Lucas(n, r, MOD);
}
///*****************************************************
/// will work in range n,r<=1e18 && MOD<=1e6 MOD can be prime or not prime
  ll fast_pow(ll a,ll p,ll Mod)
{
	ll ans=1ll;
	for (;p;p>>=1ll,a=a*a%Mod)
		if (p&1ll)
			ans=ans*a%Mod;
	return ans;
}
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if (!b) x=1,y=0;
	else exgcd(b,a%b,y,x),y-=a/b*x;
}
ll inv(ll a,ll b)
{
	if (!a) return 1ll;
	ll x=0,y=0;
	exgcd(a,b,x,y);
	x=(x%b+b)%b;
	if (!x) x+=b;
	return x;
}
ll Mul(ll n,ll p,ll pk)
{
	if (!n) return 1LL;
	ll ans=1ll;
	if (n/pk)
	{
		for (int i=2;i<=pk;++i)
			if (i%p) ans=ans*i%pk;
		ans=fast_pow(ans,n/pk,pk);
	}
	for (int i=2;i<=n%pk;++i)
		if (i%p) ans=ans*i%pk;
	return ans*Mul(n/p,p,pk)%pk;
}
ll C(ll n,ll m,ll p,ll pk,ll Mod)
{
	if (m>n) return 0;
	ll a=Mul(n,p,pk),b=Mul(m,p,pk),c=Mul(n-m,p,pk);
	ll k=0,ans;
	for (ll i=n;i;i/=p) k+=i/p;
	for (ll i=m;i;i/=p) k-=i/p;
	for (ll i=n-m;i;i/=p) k-=i/p;
	ans=a*inv(b,pk)%pk*inv(c,pk)%pk*fast_pow(p,k,pk)%pk;
	return ans*(Mod/pk)%Mod*inv(Mod/pk,pk)%Mod;
}
ll binomial(ll n,ll c,ll m){
    ll ans=0;
    for (ll x=m,i=2;i<=x;++i)
		if (x%i==0)
		{
			ll pk=1LL;
			while (x%i==0) pk*=i,x/=i;
			ans=(ans+C(n,c,i,pk,m))%m;
		}
    return ans;
}
///*******************************************************
long long C(int n, int r) {  /// O(r)
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);

 int n,r,p;
    while (~scanf("%d%d%d",&n,&r,&p))
    {
        printf("%lld\n",ncr(n,r,p));
    }

return 0;
}
