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

vll MAX;
int main(){
	ll M, S;
	scll(M);
	scll(S);
	if (M > 1){
		ll MIN[M];
		ll tmp = S;
		ll cZero = 0;
		for (ll i = 0; i < M; ++i){
			if (tmp >= 9){
				MAX.pb(9);
				tmp -= 9;
			} else {
				MAX.pb(tmp);
				tmp = 0;
				++cZero;
			}
		}
		if (tmp != 0 && cZero != M){
			cout << -1 << " " << -1 << endl;
		} else {
			ll tmp = S-1;
			MIN[0] = 1;
			for (ll i = 1; i < M; ++i){
				MIN[i] = 0;
			}
			for (ll i = M-1; i >= 1; --i){
				if (tmp >= 9){
					MIN[i] += 9;
					tmp -= 9;
				} else if (tmp >= 0){
					MIN[i] += tmp;
					tmp = 0;
				}
			}
			if (tmp >= 0 && tmp < 9){
				MIN[0] += tmp;
				tmp = 0;
			} else {
				cout << -1 << " " << -1 << endl;
				return 0;
			}
			for (ll i = 0; i < M; ++i){
				cout << MIN[i];
			}
			cout << " ";
			for (ll i = 0; i < M; ++i){
				cout << MAX[i];
			}
			cout << endl;
		}
	} else if (M == 1 && S < 10){
		cout << S << " " << S << endl;
	} else {
		cout << -1 << " " << -1 << endl;
	}
	return 0;
}