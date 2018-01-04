/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define Lost using
#define In namespace
#define Colour std
#define cepet {ios_base::sync_with_stdio(0);cin.tie(0);}

Lost In Colour;

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

const ll SIZE = 1e5+5;
ll dp_max_kiri[SIZE];
ll dp_min_kanan[SIZE];

int main(){
	SET(dp_min_kanan, -1);
	SET(dp_max_kiri, 1e18+9);
	ll N;
	scll(N);
	ll data[N];
	for (ll i = 0; i < N; ++i){
		scll(data[i]);
	}
	dp_max_kiri[0] = data[0];
	for (ll i = 1; i < N; ++i){
		dp_max_kiri[i] = max(dp_max_kiri[i-1],data[i]);
	}
	dp_min_kanan[N-1] = data[N-1];
	for (ll i = N-2; i >= 0; --i){
		dp_min_kanan[i] = min(dp_min_kanan[i+1], data[i]);
	}
	ll cnt = 0;
	if (data[0] < dp_min_kanan[1]){
		// cerr << "oke" << endl;
		// cerr << data[0] << " < " << dp_min_kanan[1] << endl;
		++cnt;
	}
	for (ll i = 1; i < N-1; ++i){
		if (dp_max_kiri[i-1] <= data[i] && data[i] < dp_min_kanan[i+1]){
			// cerr << "oke" << endl;
			// cerr << dp_max_kiri[i-1] << " <= " << data[i] << " < " << dp_min_kanan[i+1] << endl;
			++cnt;
		}
	}
	if (dp_max_kiri[N-2] <= data[N-1]){
		// cerr << "oke" << endl;
		// cerr << dp_min_kanan[N-2] << " " << data[N-1] << endl;
		++cnt;
	}
	cout << cnt << endl;
	return 0;
}