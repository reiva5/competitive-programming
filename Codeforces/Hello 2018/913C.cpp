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

ll pow(ll a, ll b){
	ll res = 1;
	for (; b; b >>= 1, a = SQR(a)){
		if (b & 1) res *= a;
	}
	return res;
}

bool cmp(pll a, pll b){
	return a.fi*b.se > b.fi*a.se;
}

ll N, L;
ll data[32];
ll cost[32];
vector<pll> pas;
ll tmp_res = 1e18;
ll idx = -1;
ll i;


int main(){
	scll(N);
	scll(L);
	for (i = 1; i <= N; ++i){
		scll(cost[i]);
	}
	for (i = 1; i <= N; ++i){
		data[i] = pow(2,i-1);
	}
	for (i = 1; i <= N; ++i){
		if (L <= data[i]){
			idx = i;
			break;
		} else {
			pas.pb(mp(data[i],cost[i]));
		}
	}
	if (idx != -1){
		tmp_res = cost[idx];
		for (i = idx; i <= N; ++i){
			tmp_res = min(tmp_res,cost[i]);
		}
	}
	if (!pas.empty()){
		sort(ALL(pas),cmp);
		ll pay = 0;
		ll dp[pas.size()+1];
		SET(dp,1e18);
		for (ll i = 0; i < pas.size() && L > 0; ++i){
			pay += (L/pas[i].fi)*pas[i].se;
			L %= pas[i].fi;
			dp[i] = pay + ((L != 0)*pas[i].se);
		}
		cout << min(tmp_res, *min_element(dp,dp+pas.size())) << endl;
	} else {
		cout << tmp_res << endl;
	}
	return 0;
}