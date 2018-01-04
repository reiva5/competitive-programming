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

ld dp[1000001];
string S;
int main(){
	cin >> S;
	RESET(dp);
	for (ld i = 1; i <= 1000000; ++i){
		dp[(int) i] = dp[(int) i-1] + log(i)/log(10.00);
	}
	for (ld i = 0; i <= 1000000; ++i){
		dp[(int) i] = floor(dp[(int) i]) + 1;
	}
	if (S.size() <= 7){
		ll num = 0;
		for (auto it : S){
			num = num*10 + it-48;
		}
		ll cmp = 1;
		for (ll i = 1; i <= 10; ++i){
			cmp *= i;
			if (cmp == num){
				cout << i << endl;
				return 0;
			}
		}
	} else {
		for (ll i = 0; i <= 1000000; ++i){
			if (dp[i] == S.size()){
				cout << i << endl;
				return 0;
			}
		}
	}
	return 0;
}