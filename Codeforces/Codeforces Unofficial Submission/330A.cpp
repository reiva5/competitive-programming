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

set<pll> makan;

int main(){
	ll N, M;
	scll(N); scll(M);
	char cake[N][M], temp;
	for (ll i = 0; i < N; ++i){
		scc(temp);
		for (ll j = 0; j < M; ++j){
			scc(cake[i][j]);
		}
	}

	for (ll i = 0; i < N; ++i){
		set<pll> dat;
		bool benar = true;
		for (ll j = 0; j < M; ++j){
			benar = benar && cake[i][j] == '.';
			dat.insert(mp(i,j));
		}
		if (benar){
			makan.insert(dat.begin(),dat.end());
		}
	}

	for (ll j = 0; j < M; ++j){
		set<pll> dat;
		bool benar = true;
		for (ll i = 0; i < N; ++i){
			benar = benar && cake[i][j] == '.';
			dat.insert(mp(i,j));
		}
		if (benar){
			makan.insert(dat.begin(),dat.end());
		}
	}
	cout << makan.size() << endl;
	return 0;
}