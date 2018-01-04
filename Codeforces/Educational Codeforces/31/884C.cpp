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

vll go[100100];
ll group[100100];
bool visited[100100];
ll member[100100];

void dfs(ll idx, ll g){
	group[idx] = g;
	visited[idx] = true;
	for (ll i = 0; i < go[idx].size(); ++i){
		if (!visited[go[idx][i]]){
			dfs(go[idx][i], g);
		}
	}
}

vll solution;
ll res;
int main(){
	RESET(member);
	RESET(visited);
	RESET(group);
	ll N;
	ll tmp;
	scll(N);
	for (ll i = 1; i <= N; ++i){
		scll(tmp);
		go[i].pb(tmp);
	}
	ll cnt = 0;
	for (ll i = 1; i <= N; ++i){
		if (!visited[i]){
			visited[i] = true;
			group[i] = cnt;
			dfs(i, cnt);
			++cnt;
		}
	}
	for (ll i = 1; i <= N; ++i){
		++member[group[i]];
	}
	for (ll i = 0; i < cnt; ++i){
		solution.pb(member[i]);
	}
	sort(solution.begin(),solution.end());
	reverse(solution.begin(),solution.end());
	if (solution.size() > 1){
		ll tmp = solution[0] + solution[1];
		res = tmp*(tmp);
		for (ll i = 2; i < solution.size(); ++i){
			res += solution[i]*(solution[i]);
		}
		cout << res << endl;
	} else {
		cout << solution[0]*(solution[0]) << endl;
	}
	return 0;
}