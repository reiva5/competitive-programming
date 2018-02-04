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

#define MIN fi
#define MAX se

string X;
map<char, int> H;
pll dp[2][5005];

int main(){
	H['('] = 0;
	H[')'] = 1;
	cin >> X;

	pll LEFT, RIGHT;
	ll cnt = 0;

	for (ll i = 0; i < X.size(); ++i){
		// Initial State
		dp[H['(']][i].MIN = dp[H['(']][i].MAX = 0;
		dp[H[')']][i].MIN = dp[H[')']][i].MAX = 0;


		if (X[i] != ')'){
			dp[H['(']][i].MIN = dp[H['(']][i].MAX = 1;
			bool stop = false;
			ll iter = 1;
			for (ll j = i+1; j < X.size() && !stop; ++j){
				// DP Prosessing
				if (X[j] == '?'){
					dp[H['(']][j].MAX = dp[H['(']][j-1].MAX+1;
					dp[H[')']][j].MAX = dp[H[')']][j-1].MAX+1;
					dp[H['(']][j].MIN = dp[H['(']][j-1].MIN;
					dp[H[')']][j].MIN = dp[H[')']][j-1].MIN;
				} else {
					dp[H[X[j]]][j].MAX = dp[H[X[j]]][j-1].MAX+1;
					dp[H[X[j]]][j].MIN = dp[H[X[j]]][j-1].MIN+1;
					dp[!H[X[j]]][j].MAX = dp[!H[X[j]]][j-1].MAX;
					dp[!H[X[j]]][j].MIN = dp[!H[X[j]]][j-1].MIN;
				}
				if (iter & 1){
					// Cek validitas
					bool valid = false;
					LEFT = dp[H['(']][j];
					RIGHT = dp[H[')']][j];
					ll stok = (RIGHT.MAX-RIGHT.MIN);
					stop = LEFT.MIN + stok < RIGHT.MIN;
					ll selisih = abs(RIGHT.MAX-LEFT.MIN);
					ll passed = (selisih%2 == 0);
					if (!stop && passed){
						ll differ = abs(RIGHT.MIN-LEFT.MIN);
						if (0 <= differ && differ <= stok){
							valid = X[j] != '(';
							cnt += valid;							
						}
					}
				}
				++iter;
			}
		}
	}

	cout << cnt << endl;
	return 0;
}