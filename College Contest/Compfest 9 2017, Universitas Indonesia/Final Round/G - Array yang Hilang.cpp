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

const ll MD = 1e9 + 7;

unordered_map<ll, ll> data_factor[100001];
unordered_map<ll, ll> sekarang;
bool isPrime[100001];
vll prime;
ll fact[105001];
ll invfact[105001];

ll modpow(ll A, ll B, ll MOD){
	ll res = 1;
	while (B){
		if (B%2){
			--B;
			res *= A;
			res %= MOD;
		}
		if (B){
			B /= 2;
			res *= A;
			res %= MOD;
			res *= A;
			res %= MOD;
		}
	}
	return res;
}

ll C(ll A, ll B){
	return (((fact[A]*invfact[A-B])%MD)*invfact[B])%MD;
}

void fillFact(){
	fact[0] = fact[1] = 1;
	for (ll i = 2; i <= 105000; ++i){
		fact[i] = fact[i-1]*i;
	}
}

void fillInverseFact(){
	invfact[0] = invfact[1] = 1;
	for (ll i = 2; i <= 105000; ++i){
		invfact[i] = modpow(fact[i], MD-1, MD);
	}
}

void merge(unordered_map<ll,ll>& a, unordered_map<ll,ll>& b){
	for (auto& it : b){
		a[it.first] += it.second;
	}
}

void createPrime(){
	SET(isPrime, true);
	isPrime[0] = isPrime[1] = false;
	for (ll i = 2; i <= 100000; ++i){
		if (isPrime[i]){
			prime.pb(i);
			for (ll j = 2; j*i <= 100000; ++j){
				isPrime[i*j] = false;
			}
		}
	}
}

void preCompute(){
	ll tmp;
	for (auto& it : prime){
		for (ll i = 1; i*it <= 100000; ++i){
			tmp = i*it;
			while (!(tmp%it)){
				++data_factor[i*it][it];
				tmp /= it;
			}
		}
	}
}

int main(){
	createPrime();
	preCompute();
	fillFact();
	fillInverseFact();
	ll T;
	scll(T);
	while (T--){
		ll N, tmp;
		ll res = 1;
		scll(N);
		sekarang.clear();
		while (N--){
			scll(tmp);
			merge(sekarang, data_factor[tmp]);
		}
		for (auto& it : sekarang){
			res *= C(it+N-1,N-1);
			res %= MD;
		}
		cout << res << endl;
	}
	return 0;
}