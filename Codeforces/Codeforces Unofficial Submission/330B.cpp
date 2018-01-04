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
#define mp make_pair
#define eb emplace_back

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

bool larang[1010][1010];

int main(){
	ll N, M;
	scll(N); scll(M);
	memset(larang, false, sizeof larang);
	for (ll i = 0; i < M; ++i){
		ll a, b;
		scll(a); scll(b);
		larang[a][b] = true;
		larang[b][a] = true;
	}
	bool found = false;
	ll idx = -1;
	for (ll i = 1; i <= N && !found; ++i){
		bool can = true;
		for (ll j = 1; j <= N && can; ++j){
			if (i != j){
				can = !larang[i][j];
			}
		}
		found = can;
		if (found){
			idx = i;
		}
	}
	cout << N-1 << endl;
	for (ll i = 1; i <= N; ++i){
		if (i != idx){
			cout << min(i,idx) << " " << max(i,idx) << endl;
		}
	}
	return 0;
}