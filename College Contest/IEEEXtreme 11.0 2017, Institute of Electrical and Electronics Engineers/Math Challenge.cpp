// Bismillaahirrahmaanirrahiim
/* Author   : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define jehian using
#define mau namespace
#define libur std
#define cepet {ios_base::sync_with_stdio(0);cin.tie(0);}

jehian mau libur;
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
#define nl printf("\n");
#define sp printf(" ");

/* MACROS FOR FUNCTION AND METHOD */
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define RESET(x) memset((x), 0, sizeof(x))
#define SET(x,y) memset((x), (y), sizeof(x))

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


const ll N = 2e6 + 6, mod = 1e9 + 7;

ll modPow(ll b, ll p){
	ll ret = 1;
	for (; p; p >>= 1, b = (b * b) % mod){
		if (p & 1) ret = (ret * b) % mod;
	}
	return ret;
}

ll gcdExtended(ll a, ll b, ll *x, ll *y);
 
ll gcdExtended(ll a, ll b, ll *x, ll *y){
	if (a == 0){
		*x = 0, *y = 1;
		return b;
	}

	ll x1, y1;
	ll gcd = gcdExtended(b%a, a, &x1, &y1);

	*x = y1 - (b/a) * x1;
	*y = x1;

	return gcd;
}

ll modInverse(ll a, ll m){
	ll x, y;
	ll g = gcdExtended(a, m, &x, &y);
	if (g != 1){
		return -1;
	} else {
		ll res = (x%m + m) % m;
		return res;
	}
}

ll C(ll n, ll k){
	ll MIN = min(k,n-k);
	ll pembagi = 1;
	ll tmp;
	ll cnt_p = 0;
	for (ll i = 1; i <= MIN; ++i){
		if (i%2){
			pembagi *= i;
			pembagi %= (mod-1);
		} else {
			tmp = i;
			while (!(tmp%2)){
				++cnt_p;
				tmp /= 2;
			}
			pembagi *= tmp;
			pembagi %= (mod-1);
		}
	}
	ll MAX = max(k,n-k);
	ll pembilang = 1;
	for (ll i = MAX+1; i <= n; ++i){
		if (i%2){
			pembilang *= i;
			pembilang %= (mod-1);
		} else {
			tmp = i;
			while (!(tmp%2) && cnt_p){
				--cnt_p;
				tmp /= 2;
			}
			pembilang *= tmp;
			pembilang %= (mod-1);
		}
	}
	return (modInverse(pembagi,mod-1)*pembilang)%(mod-1);
}

int main(){
	ll T;
	scll(T);
	while (T--){
		ll a, b, c;
		scll(a), scll(b), scll(c);
		ll res = modPow(a,C(b,c));
		res %= mod;
		while (res < 0){
			res += mod;
		}
		cout << res << endl;
	}
	return 0;
}