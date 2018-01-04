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

int main(){
	ll sum = 0; 
	ll i, j;
	ll diff = INT_MAX;
	ll n;
	scll(n);
	ll data[n];
	for (i = 0; i < n; ++i){
		data[i] = i+1;
	}

	for (i = 0; i < n; ++i){
		sum += data[i];
	}

	bool dp[n+1][sum+1];

	for (i = 0; i <= n; ++i){
		dp[i][0] = true;
	}

	for (i = 1; i <= sum; ++i){
		dp[0][i] = false;
	}

	for (i = 1; i <= n; ++i){
		for (j = 1; j <= sum; ++j){
			dp[i][j] = dp[i-1][j];

			if (data[i-1] <= j){
				dp[i][j] |= dp[i-1][j-data[i-1]];
			}
		}
	}


	for (j = sum/2; j >= 0; --j){
		if (dp[n][j] == true){
			diff = sum-2*j;
			break;
		}
	}
	cout << diff << endl;
	return 0;
}