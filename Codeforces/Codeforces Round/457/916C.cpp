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

vll prime;
bool isprima[1000005];

int main(){
	SET(isprima, 1);
	isprima[0] = isprima[1] = false;
	for (ll i = 2; i < 1000005; ++i){
		if (isprima[i]){
			prime.pb(i);
			for (ll j = 2; i*j < 1000005; ++j){
				isprima[i*j] = false;
			}
		}
	}
	ll N, M;
	scll(N);
	scll(M);
	vll go[N+1];
	ll sum = 2*(N-1);
	ll perubahan = 0;
	while (!isprima[sum] || !isprima[perubahan+2]) {
		++sum;
		++perubahan;
	}
	cout << 2+perubahan << " " << sum << endl;
	ll sisa = M;
	for (ll i = 2; i <= N-1; ++i) {
		cout << 1 << " " << i << " " << 2 << endl;
		--sisa;
	}
	if (sisa == 1) {
		cout << 1 << " " << N << " " << 2+perubahan << endl;
	} else {
		for (ll i = 2; i <= N-1 && sisa > 1; ++i) {
			for (ll j = i+1; j <= N-1 && sisa > 1; ++j) {
				cout << i << " " << j << " " << 2 << endl;
				--sisa;
			}
		}
		if (sisa == 1) {
			cout << 1 << " " << N << " " << 2+perubahan << endl;
		} else {
			for (ll j = 1; j <= N-1 && sisa; ++j) {
				cout << j << " " << N << " " << 2+perubahan << endl;
				--sisa;
			}
		}
	}
	return 0;
}