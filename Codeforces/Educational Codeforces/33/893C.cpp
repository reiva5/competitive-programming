/* Author   : Jehian Norman Saviero (@Reiva5) */
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

vll go[100005];
ll cost[100005];
vll member[100005];
ll cnt = 0;
bool visited[100005];

void dfs(ll i){
	visited[i] = true;
	member[cnt].pb(i);
	for (auto it : go[i]){
		if (!visited[it]){
			member[cnt].pb(it);
			dfs(it);
		}
	}
}

int main(){
	RESET(visited);
	ll N, M, A, B;
	scll(N);
	scll(M);
	for (ll i = 1; i <= N; ++i){
		scll(cost[i]);
	}
	for (ll i = 0; i < M; ++i){
		scll(A);
		scll(B);
		go[A].pb(B);
		go[B].pb(A);
	}
	for (ll i = 1; i <= N; ++i){
		if (!visited[i]){
			dfs(i);
			++cnt;
		}
	}
	ll res = 0;
	for (ll i = 0; i < cnt; ++i){
		ll MIN = cost[member[i][0]];
		for (auto it : member[i]){
			MIN = min(MIN,cost[it]);
		}
		res += MIN;
	}
	cout << res << endl;
	return 0;
}