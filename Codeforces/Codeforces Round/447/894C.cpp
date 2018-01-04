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

bool ada[1000000];
ll gcd(ll a, ll b){
	if (a % b == 0){
		return b;
	} else {
		return gcd(b,a%b);
	}
}

int main(){
	RESET(ada);
	ll N;
	scll(N);
	ll data[N];
	for (ll i = 0; i < N; ++i){
		scll(data[i]);
		ada[data[i]] = true;
	}
	ll GCDAll = data[0];
	for (ll i = 0; i < N; ++i){
		GCDAll = gcd(GCDAll,data[i]);
	}
	ll GCD;
	bool found = !ada[GCDAll];
	if (!found){
		cout << 2*N << endl;
		string spasi = "";
		for (ll i = 0; i < N; ++i){
			cout << spasi << data[i] << " " << GCDAll; 
			spasi = " ";
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}