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
#define SET(x,y) for(int _je = sizeof(x)/sizeof(x[0]); _je--;) x[_je] = y

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

ll dp[256][2][5005];
int main(){
	string A;
	cin >> A;
	RESET(dp);
	dp[A[0]][0][0] = 1;
	for (ll i = 1; i < A.size(); ++i){
		if (A[i] == 'a'){
			dp['a'][0][i] = dp['a'][0][i-1] + 1;
			dp['b'][0][i] = dp['b'][0][i-1];
		} else {
			dp['a'][0][i] = dp['a'][0][i-1];
			dp['b'][0][i] = dp['b'][0][i-1] + 1;
		}
	}
	dp[A.back()][1][A.size()-1] = 1;
	for (ll i = (ll) A.size()-2; i >= 0; --i){
		if (A[i] == 'a'){
			dp['a'][1][i] = dp['a'][1][i+1] + 1;
			dp['b'][1][i] = dp['b'][1][i+1];
		} else {
			dp['a'][1][i] = dp['a'][1][i+1];
			dp['b'][1][i] = dp['b'][1][i+1] + 1;
		}
	}
	ll MAX = -1;
	for (ll i = 0; i < A.size(); ++i){
		for (ll j = i; j < A.size(); ++j){
			ll huhu = 0;
			ll banyak_b = dp['b'][0][j];
			if (i > 0){
				huhu += dp['a'][0][i-1];
				banyak_b -= dp['b'][0][i-1];
			}
			huhu += dp['a'][1][j];
			huhu += banyak_b;
			MAX = max(MAX, huhu);
		}
	}
	cout << MAX << endl;
	return 0;
}