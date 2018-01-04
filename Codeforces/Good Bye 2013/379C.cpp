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

ll data[300010];
ll sol[300010];
pll hehe[300010];
bool cmp(pll a, pll b){
	return a.fi < b.fi || (a.fi == b.fi && a.se < b.se);
}
int main(){
	ll N;
	scll(N);
	ll MIN = 1;
	for (ll i = 0; i < N; ++i){
		scll(hehe[i].fi);
		hehe[i].se = i;
	}
	sort(hehe,hehe+N,cmp);
	for (ll i = 0; i < N; ++i){
		sol[hehe[i].se] = max(hehe[i].fi,MIN);
		if (MIN < hehe[i].fi){
			MIN = hehe[i].fi;
		}
		++MIN;
	}
	for (ll i = 0; i < N; ++i){
		cout << sol[i] << " ";
	}
	return 0;
}