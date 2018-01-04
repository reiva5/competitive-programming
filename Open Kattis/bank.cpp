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
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define eb emplace_back
#define SQR(x) (x)*(x)
#define CUBE(x) SQR(x)*(x)
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


bool cmp(pll a, pll b){
	return a.fi > b.fi || (a.se < b.se && a.fi == b.fi);
}

ll dp[50];
ll val[10005];
ll waktu[10005];
vector<pll> data;
int main(){
	RESET(dp);
	ll N, T;
	scll(N); scll(T);
	ll W = 0;
	for (ll i = 0; i < N; ++i){
		scll(val[i]);
		scll(waktu[i]);
		data.pb(mp(val[i],waktu[i]));
	}
	sort(data.begin(),data.end(),cmp);
	for (ll i = 0; i < N; ++i){
		val[i] = data[i].fi;
		waktu[i] = data[i].se;
	}
	for (ll i = 0; i < N; ++i){
		bool found = false;
		for (ll j = 47; j >= 0 && !found; --j){
			if (j <= waktu[i]){
				if (dp[j] < val[i]){
					dp[j] = val[i];
					found = true;
				}
			}
		}
	}
	ll res = 0;
	for (ll i = 0; i <= 47; ++i){
		res += dp[i];
	}
	cout << res << endl;
	return 0;
}