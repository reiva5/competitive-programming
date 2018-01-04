/* Author	: Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define jehian using
#define mau namespace
#define libur std
#define cepet {ios_base::sync_with_stdio(0);cin.tie(NULL);}

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

/* MACROS FOR FUNCTION */
#define pb push_back
#define mp make_pair
#define eb emplace_back

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

bool res[100100];
vll prime;
bool isPrime[35001];

void sieve(){
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	for (ll i = 2; i <= 35000; ++i){
		if (isPrime[i]){
			prime.pb(i);
			for (ll j = 2; i*j <= 35000; ++j){
				isPrime[i*j] = false;
			}
		}
	}
}

int main(){
	sieve();
	ll T;
	scll(T);
	while (T--){
		memset(res, true, sizeof res);
		ll N, M;
		scll(M); scll(N);
		for (ll j = 0; j < prime.size(); ++j){
			for (ll k = M + ((prime[j]-M%prime[j]))%prime[j]; k <= N; k += prime[j]){
				if (k > 35000 || !isPrime[k]){
					res[k-M] = false;
				}
			}
		}
		for (ll i = M; i <= N; ++i){
			if (res[i-M] && i != 1){
				printf("%lld\n", i);
			}
		}
		nl;
	}
	return 0;
}