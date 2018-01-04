// Bismillaahirrahmaanirrahiim
/* Author	: Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define jehian using
#define mau namespace
#define libur std
#define cepet {ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);}

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


#define le fi
#define ri se

vll go[100005];
ld val[100005];
ll bef[100005];
bool visited[100005];

ld dfs(ll a){
	if (go[a].size()){
		ld res[2];
		RESET(res);
		int cnt = 0;
		for (auto it : go[a]){
			if (!visited[it]){
				visited[it] = true;
				res[cnt++] += (1.00 + dfs(it));
				visited[it] = false;
			}
		}
		if (cnt){
			val[a] = max((ld) res[0] / cnt,(ld) res[1] / cnt);
		} else {
			val[a] = 0;
		}
		return val[a];
	} else {
		val[a] = 0;
		return val[a];
	}
}

int main(){
	RESET(visited);
	for (ll i = 0; i < 100005; ++i){
		val[i] = -1;
	}
	ll T;
	scll(T);
	ll tmp = T - 1;
	while (tmp--){
		ll A, B;
		scll(A); scll(B);
		go[A].pb(B);
		go[B].pb(A);
	}
	val[1] = dfs(1);
	ll hehe = 0;
	for (ll i = 1; i <= T; ++i){
		hehe += val[i];
	}
	cout << setprecision(10) << fixed << (ld) hehe << endl;
	return 0;
}