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

vector<pll> sol;
map<ll,ll> banyak_x, banyak_y;

int main(){
	ll n, m, r, k;
	scll(n);
	scll(m);
	ll dp_y[n];
	ll dp_x[m];
	scll(r);
	scll(k);
	ll i, j;
	ll hit = min(r,n-r+1);
	ll cnt_y = 0;
	for (i = 0, j = n-1; i <= j; ++i, --j){
		cnt_y = min(cnt_y+1,hit);
		dp_y[i] = dp_y[j] = cnt_y;
	}
	for (i = 0; i < n; ++i){
		++banyak_y[dp_y[i]];
	}
	hit = min(r,m-r+1);
	ll cnt_x = 0;
	for (i = 0, j = m-1; i <= j; ++i, --j){
		cnt_x = min(cnt_x+1,hit);
		dp_x[i] = dp_x[j] = cnt_x;
	}
	for (i = 0; i < m; ++i){
		++banyak_x[dp_x[i]];
	}
	ll z;
	ll MAX_X = 320;
	ll MAX_Y = 320;
	for (i = cnt_y; MAX_Y-- && i >= 1; --i){
		for (j = cnt_x; MAX_X-- && j >= 1; --j){
			sol.pb(mp(i*j,banyak_x[j]*banyak_y[i]));
		}
		MAX_X = 320;
	}
	sort(ALL(sol));
	reverse(ALL(sol));
	ld res = 0;
	for (i = 0; k > 0; ++i){
		if (k >= sol[i].se){
			res += sol[i].fi*sol[i].se;
			k -= sol[i].se;
		} else {
			res += sol[i].fi*k;
			k = 0;
		}
	}
	ld tot = (n-r+1)*(m-r+1);
	cout << setprecision(10) << fixed << res/tot << endl;
	return 0;
}