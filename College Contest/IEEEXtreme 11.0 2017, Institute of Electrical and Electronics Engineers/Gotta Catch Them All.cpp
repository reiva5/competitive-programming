// Bismillaahirrahmaanirrahiim
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
#define mp make_pair
#define eb emplace_back
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

#define cost fi
#define i fi
#define j se

class pasangan{
	public:
		ll have;
		pll P;
		pasangan(ll A, pll B) : have(A), P(B) {};
};

class custom_cmp{
	public:
		bool operator() (pasangan a, pasangan b){
			return a.have < b.have;
		}
};

#define special pair<ll, pll>

class new_com{
	public:
		bool operator() (special a, special b){
			return a.fi < b.fi;
		}
};

bool visited[300][300];
ll COST[300][300];
ll SELAMAT[300][300];

priority_queue<pasangan, vector<pasangan>, custom_cmp> pq;
priority_queue<pair<ll, pll>, vector< pair<ll, pll> >, new_com> qq;

int main(){
	RESET(visited);
	SET(COST, -1e9);
	ll N, M;
	scll(N); scll(M);
	ll c[N][M];
	for (ll i = 0; i < N; ++i){
		for (ll j = 0; j < M; ++j){
			scll(c[i][j]);
		}
	}
	COST[0][0] = 0;
	for (ll i = 0; i < N; ++i){
		for (ll j = 0; j < M; ++j){
			if (i != 0){
				if (j != 0){
					COST[i][j] = c[i][j] + max(COST[i][j-1],COST[i-1][j]);
				} else {
					COST[i][j] = c[i][j] + COST[i-1][j];
				}
			} else {
				if (j != 0){
					COST[i][j] = c[i][j] + COST[i][j-1];
				} else {
					COST[i][j] = c[i][j];
				}
			}
		}
	}
	for (ll i = 0; i < N; ++i){
		for (ll j = 0; j < M; ++j){
			cerr << COST[i][j] << " ";
		}
		cerr << endl;
	}
	RESET(visited);
	qq.push(mp(0,mp(0,0)));
	while (!qq.empty()){
		special hehe = qq.top();
		qq.pop();
		if (!visited[hehe.se.i][hehe.se.j]){
			visited[hehe.se.i][hehe.se.j] = true;
			SELAMAT[hehe.se.i][hehe.se.j] = hehe.fi;
			pll P = hehe.se;
			if (P.i < N-1 && !visited[P.i+1][P.j]){
				qq.push(mp(min(COST[P.i+1][P.j],hehe.fi),mp(P.i+1,P.j)));
			}
			if (P.j < M-1 && !visited[P.i][P.j+1]){
				qq.push(mp(min(COST[P.i][P.j+1],hehe.fi),mp(P.i,P.j+1)));
			}
		}
	}
	if (SELAMAT[N-1][M-1] < 1){
		SELAMAT[N-1][M-1] *= -1;
		cout << SELAMAT[N-1][M-1]+1 << endl;
	} else {
		cout << 1 << endl;
	}
	return 0;
}