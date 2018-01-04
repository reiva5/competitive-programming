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

const ll MD = 1e9+7;

vector<char> data;
ll dp[5005][5005];
int main(){
	RESET(dp);
	ll N;
	scll(N);
	for (ll i = 0; i < N; ++i){
		char cc;
		cin >> cc;
		data.pb(cc);
	}
	ll res = 0;
	ll cnt = 0;
	dp[0][0] = 1;
	for (ll i = 1; i < N; ++i){
		if (data[i-1] == 'f'){
			for (ll j = 1; j <= 5000; ++j){
				dp[i][j] = dp[i-1][j-1];
			}
			++cnt;
		} else {
			ll sum = 0;
			for (ll j = 0; j <= cnt; ++j){
				sum += dp[i-1][j];
				sum %= MD;
			}
			dp[i][0] = sum;
			for (ll j = 1; j <= cnt; ++j){
				dp[i][j] = dp[i][j-1] - dp[i-1][j-1];
				dp[i][j] %= MD;
				if (dp[i][j] < 0){
					dp[i][j] += MD;
				}
			}
		}
	}
	for (ll i = 0; i <= cnt; ++i){
		res += dp[N-1][i];
		res %= MD;
	}
	if (res < 0){
		res += MD;
	}
	cout << res%MD << endl;
	return 0;
}