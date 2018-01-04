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
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define eb emplace_back
#define RESET(x) memset((x), 0, sizeof(x))
#define SET(x,y) for(int _je = sizeof(x)/sizeof(x[0]); _je--;) x[_je] = y
#define SQR(x) (x)*(x)
#define CUBE(x) SQR(x)*(x)

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
#define special pair<ll,pll>

unordered_map<ll,ll> banyak_faktor[1000005];
bool prima[1000005];
vll prime;
ll D, tmp;
ll mod = 1e9 + 7;

ll powmod(ll b, ll p){
	ll ret = 1;
	for (; p; p >>= 1, b = (b * b) % mod){
		if (p & 1) ret = (ret * b) % mod;
	}
	return ret;
}

ll N = 2000006;
ll cnt[2000006];
ll fac[2000006], inv[2000006];

ll C(ll n, ll k) {
	assert(!(n < k || k < 0));
	return (((fac[n] * inv[k]) % mod) * inv[n-k]) % mod;
}


int main(){
	fac[0] = inv[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = (1LL * fac[i-1] * i) % mod;
		inv[i] = powmod(fac[i], mod - 2);
		assert((fac[i] * inv[i] % mod) == 1);
	}
	SET(prima,1);
	prima[0] = prima[1] = false;
	for (ll i = 2; i <= 1000000; ++i){
		if (prima[i]){
			banyak_faktor[i][i] = 1;
			for (ll j = 2; i*j <= 1000000; ++j){
				prima[i*j] = false;
				D = i*j;
				tmp = D;
				while (tmp%i == 0){
					++banyak_faktor[D][i];
					tmp /= i;
				}
			}
		}
	}
	ll T;
	scll(T);
	for (ll i = 0; i < T; ++i){
		ll A, B;
		scll(A);
		scll(B);
		ll ans = 1;
		for (auto it : banyak_faktor[A]){
			ans = (ans * C(it.second + B-1, B-1) % mod) % mod;
		}
		ans %= mod;
		ll TMP = ans*powmod(2,B-1);
		TMP %= mod;
		printf("%lld\n", TMP);
	}
	return 0;
}