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
#define special pair<ll,pll>


int main(){
	pll A[2][2];
	for (ll i = 0; i < 2; ++i){
		for (ll j = 0; j < 2; ++j){
			scll(A[i][j].fi); scll(A[i][j].se);
		}
	}
	ll cnt[2];
	RESET(cnt);
	for (ll i = A[0][0].fi; i <= A[0][0].se; ++i){
		for (ll j = A[0][1].fi; j <= A[0][1].se; ++j){
			for (ll k = A[1][0].fi; k <= A[1][0].se; ++k){
				for (ll m = A[1][1].fi; m <= A[1][1].se; ++m){
					if (i+j != k+m){
						++cnt[i+j < k+m];
					}
				}
			}
		}
	}
	if (cnt[0] != cnt[1]){
		cout << (cnt[0] > cnt[1] ? "Gunnar" : "Emma") << endl;
	} else {
		cout << "Tie" << endl;
	}
	return 0;
}