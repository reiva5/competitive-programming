/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define Jehian using
#define Norman namespace
#define Saviero std
#define cepet {ios_base::sync_with_stdio(0);cin.tie(0);}

Jehian Norman Saviero;

/* MACROS FOR TYPE */
typedef long l;
typedef long double ld;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;

/* MACROS FOR PRINT */
#define nl printf("\n")
#define sp printf(" ")

/* MACROS FOR FUNCTION AND METHOD */
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define eb emplace_back
#define RESET(x) memset((x), 0, sizeof(x))
#define SET(x,y) for(int _je = sizeof(x)/sizeof(x[0]); _je--;) x[_je] = y
#define SQR(x) (x)*(x)
#define CUBE(x) SQR(x)*(x)
#define ALL(x) (x).begin(), (x).end()
#define ALLSIZE(x,n) (x), (x)+(n)

/* MACROS FOR ATTRIBUTE */
#define fi first
#define se second

/* MACROS FOR SCAN */
#define scc(x) scanf("%c", &x)
#define scd(x) scanf("%Lf", &x)
#define scf(x) scanf("%f", &x)
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%ld", &x)
#define scll(x) scanf("%lld", &x)
#define scld(x) scanf("%Lf", &x)
#define scui(x) sci(x)
#define scul(x) scl(x)
#define scull(x) scll(x)

bool isprime[1000005];
vll prima;

void sieve(){
	SET(isprime,1);
	isprime[0] = isprime[1] = 0;
	for (ll i = 2; i <= 1000000; ++i){
		if (isprime[i]){
			prima.pb(i);
			for (ll j = 2; i*j <= 1000000; ++j){
				isprime[i*j] = false;
			}
		}
	}
}

ll powMod(ll a, ll b, ll MD){
	ll res = 1;
	for (; b; b>>=1, a = SQR(a)%MD){
		if (b & 1) res = (res*a)%MD;
	}
	return res;
}

ll fact[1000005];
int main(){
	sieve();
	ll T;
	scll(T);
	while (T--){
		ll tmp;
		scll(tmp);
		if (!isprime[tmp]){
			vll::iterator low = lower_bound(ALL(prima), tmp);
			ll ans = prima[low-prima.begin()];
			//(n-1)! % 
			ll MD = ans;
			ll res = ans-1;
			for (ll i = ans-1; i > tmp; --i){
				res *= powMod(i,MD-2,MD);
				res %= MD;
			}
			cout << res << endl;
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}