// Bismillaahirrahmaanirrahiim
/* Author	: Jehian Norman Saviero (@Reiva5) */
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

const int N = 2e6 + 6, mod = 1e9 + 7;

ll powmod(ll b, ll p) {
	ll ret = 1;
	for (; p; p >>= 1, b = (b * b) % mod)
		if (p & 1) ret = (ret * b) % mod;
	return ret;
}

int fp[N];
ll cnt[N];
ll fac[N], inv[N];

ll C(ll n, ll k) {
	assert(!(n < k || k < 0));
	return (((fac[n] * inv[k]) % mod) * inv[n-k]) % mod;
}

void pre(){
	for (int i = 0; i < N; i++)
	fp[i] = 0;
	fp[1] = 1;
	for (int i = 2; i < N; i++) if (fp[i] == 0) {
		for (int j = i; j < N; j += i){
			if (fp[j] == 0){
				fp[j] = i;
			}
		}
	}
	fac[0] = inv[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = (1LL * fac[i-1] * i) % mod;
		inv[i] = powmod(fac[i], mod - 2);
		assert((fac[i] * inv[i] % mod) == 1);
	}
}

ll pangkat_10[100100];

int main(){
	pre();
	pangkat_10[0] = 1;
	for (ll i = 1; i <= 100000; ++i){
		pangkat_10[i] = pangkat_10[i-1]*10;
		pangkat_10[i] %= mod;
	}
	ll N;
	scll(N);
	while (N--){
		ll N, A, tmp;
		scll(N);
		scll(A);
		string s;
		cin >> s;
		bool kembali = false;
		bool same = false;
		for (ll i = 1; i < s.size() && !same; ++i){
			same = s[0] == s[i];
		}
		if (s.size() == 1){
			same = false;
		}
		ll res = 0;
		if (same){
			ll hehe = 0;
			for (ll i = A+1; i <= N; ++i){
				ll n = N-i;
				ll tmp = (((n+1) * pangkat_10[n]) % mod) * C(N-A,i-A);
				cerr << tmp << endl;
				if (hehe % 2 == 0){
					res += tmp;
				} else {
					res -= tmp;
				}
				while (res < mod){
					res += mod;
				}
				res %= mod;
				++hehe;
			}
		} else {
			for (ll i = 1; A*i <= N; ++i){
				ll n = (N - A*i) + i;
				ll tmp = (((fac[n] * inv[(N - A*i)] % mod) * inv[i]) % mod * pangkat_10[N - A*i]) % mod;
				if (i % 2 != 0) {
					res += tmp;
				} else {
					res -= tmp;
				}
				while (res < mod){
					res += mod;
				}
				res %= mod;
			}
		}
		cout << ((pangkat_10[(kembali ? tmp : N)] - res) % mod) << endl;
	}
	return 0;
}