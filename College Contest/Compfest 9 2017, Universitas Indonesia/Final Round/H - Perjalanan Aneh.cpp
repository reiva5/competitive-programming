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

#define id fi
#define t se

class triple{
	public:
		ll id;
		ll B;
		ll X;
		triple(ll A, ll B, ll C) : id(A), B(B), X(C) {};
};

class custom_cmp{
	public:
		bool operator() (pll a, pll b){
			return a.se > b.se;
		}
};

const ll defSize = 1e5+5;

priority_queue<pll, vector<pll>, custom_cmp> pq;
vector< triple > go[defSize];
bool visited[defSize];
ll COST[defSize];

void KOSONGKAN(ll N){
	for (ll i = 0; i <= N; ++i) go[i].clear();	
}

ll CONVERT(ll B, ll X, ll t){
	if (B-X*t <= 1){
		return t+1;
	} else if (X == 0){
		return t + (B-X*t);
	} else {
		t = (B-1)/X;
		while (B-X*t > 1){
			++t;
		}
		return t+1;
	}
}

ll T;
ll t;
ll N, M;
ll U, V, B, X;
pll tmp;

int main(){
	scll(T);
	while (T--){
		RESET(visited);
		SET(COST, -1);
		scll(N), scll(M);
		KOSONGKAN(N);
		for (ll i = 0; i < M; ++i){
			scll(U), scll(V), scll(B), scll(X);
			go[U].pb(triple(V,B,X));
			go[V].pb(triple(U,B,X));
		}
		pq.push(mp(1,0));
		while (!pq.empty() && COST[N] == -1){
			tmp = pq.top();
			pq.pop();
			if (!visited[tmp.id]){
				visited[tmp.id] = true;
				COST[tmp.id] = tmp.t;
				for (ll i = 0; i < go[tmp.id].size(); ++i){
					if (!visited[go[tmp.id][i].id]){
						B = go[tmp.id][i].B;
						X = go[tmp.id][i].X;
						t = tmp.t;
						pq.push(mp(go[tmp.id][i].id,CONVERT(B,X,t)));
					}
				}
			}
		}
		while (!pq.empty()) pq.pop();
		cout << COST[N] << endl;
	}
	return 0;
}