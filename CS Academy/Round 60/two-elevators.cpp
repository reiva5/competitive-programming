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

int main(){
	ll N;
	scll(N);
	pll data[N+5];
	ll E[2];
	scll(E[0]);
	scll(E[1]);
	for (ll i = 0; i < N; ++i){
		scll(data[i].fi);
		scll(data[i].se);
	}
	ll cnt[4];
	RESET(cnt);
	for (ll i = 0; i < N; ++i){
		cnt[0] += (E[0] >= data[i].fi && data[i].fi > data[i].se);
		cnt[1] += (E[0] <= data[i].fi && data[i].fi < data[i].se);
		cnt[2] += (E[1] >= data[i].fi && data[i].fi > data[i].se);
		cnt[3] += (E[1] <= data[i].fi && data[i].fi < data[i].se);
	}
	cout << max(cnt[1]+cnt[2],cnt[0]+cnt[3]) << endl;
	return 0;
}