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

const ll MD = 1e9+7;
const ll MAX_SIZE = 2e5+10;

ll powMod(ll a, ll b){
	ll res = 1;
	for(; b; b >>= 1, a = SQR(a)%MD){
		if (b & 1){
			res = (res*a)%MD;
		}
	}
	return res;
}

ll fact[MAX_SIZE];
ll inv[MAX_SIZE];

void preCompute(){
	RESET(fact);
	RESET(inv);
	fact[0] = 1;
	for (ll i = 1; i <= 100000; ++i){
		fact[i] = fact[i-1]*i;
		fact[i] %= MD;
	}
	for (ll i = 0; i <= 100000; ++i){
		inv[i] = powMod(fact[i], MD-2);
	}
}

vll data;
int main(){
	preCompute();
	ll N, K;
	scll(N);
	scll(K);
	ll res = 0;
	ll tmp;
	data.pb(0);
	for (ll i = 0; i < K; ++i){
		scll(tmp);
		data.pb(tmp);
	}
	sort(ALL(data));
	for (ll i = 1; i <= K; ++i){
		res += (data[i]-data[i-1])*(N-data[i]+1);
		res %= MD;
	}
	cout << res << endl;
	return 0;
}