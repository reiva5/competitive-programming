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

#define i fi
#define j se

int _M[3][1000][1000];
bool visited[3][1000][1000];

ll N, M;
queue<pll> q;

void bfs0(ll i, ll j){
	pll P;
	q.push(mp(i,j));
	while (!q.empty()){
		P = q.front();
		visited[0][P.i][P.j] = true;
		q.pop();
		if (P.i > 0 && _M[0][P.i-1][P.j] && !visited[0][P.i-1][P.j]){
			visited[0][P.i-1][P.j] = true;
			q.push(mp(P.i-1,P.j));
		}
		if (P.i < N-1 && _M[0][P.i+1][P.j] && !visited[0][P.i+1][P.j]){
			visited[0][P.i+1][P.j] = true;
			q.push(mp(P.i+1,P.j));
		}
		if (P.j > 0 && _M[0][P.i][P.j-1] && !visited[0][P.i][P.j-1]){
			visited[0][P.i][P.j-1] = true;
			q.push(mp(P.i,P.j-1));
		}
		if (P.j < M-1 && _M[0][P.i][P.j+1] && !visited[0][P.i][P.j+1]){
			visited[0][P.i][P.j+1] = true;
			q.push(mp(P.i,P.j+1));
		}
	}
}

void bfs1(ll i, ll j){
	pll P;
	q.push(mp(i,j));
	while (!q.empty()){
		P = q.front();
		q.pop();
		visited[1][P.i][P.j] = true;
		if (P.i > 0 && P.j > 0 && _M[1][P.i-1][P.j-1] && !visited[1][P.i-1][P.j-1]){
			visited[1][P.i-1][P.j-1] = true;
			q.push(mp(P.i-1,P.j-1));
		}
		if (P.i < N-1 && P.j < M-1 && _M[1][P.i+1][P.j+1] && !visited[1][P.i+1][P.j+1]){
			visited[1][P.i+1][P.j+1] = true;
			q.push(mp(P.i+1,P.j+1));
		}
		if (P.j > 0 && P.i < N-1 && _M[1][P.i+1][P.j-1] && !visited[1][P.i+1][P.j-1]){
			visited[1][P.i+1][P.j-1] = true;
			q.push(mp(P.i+1,P.j-1));
		}
		if (P.j < M-1 && P.i > 0 && _M[1][P.i-1][P.j+1] && !visited[1][P.i-1][P.j+1]){
			visited[1][P.i-1][P.j+1] = true;
			q.push(mp(P.i-1,P.j+1));
		}
	}
}

void bfs2(ll i, ll j){
	pll P;
	q.push(mp(i,j));
	while (!q.empty()){
		P = q.front();
		visited[2][P.i][P.j] = true;
		q.pop();
		if (P.i > 0 && _M[2][P.i-1][P.j] && !visited[2][P.i-1][P.j]){
			visited[2][P.i-1][P.j] = true;
			q.push(mp(P.i-1,P.j));
		}
		if (P.i < N-1 && _M[2][P.i+1][P.j] && !visited[2][P.i+1][P.j]){
			visited[2][P.i+1][P.j] = true;
			q.push(mp(P.i+1,P.j));
		}
		if (P.j > 0 && _M[2][P.i][P.j-1] && !visited[2][P.i][P.j-1]){
			visited[2][P.i][P.j-1] = true;
			q.push(mp(P.i,P.j-1));
		}
		if (P.j < M-1 && _M[2][P.i][P.j+1] && !visited[2][P.i][P.j+1]){
			visited[2][P.i][P.j+1] = true;
			q.push(mp(P.i,P.j+1));
		}
		if (P.i > 0 && P.j > 0 && _M[2][P.i-1][P.j-1] && !visited[2][P.i-1][P.j-1]){
			visited[2][P.i-1][P.j-1] = true;
			q.push(mp(P.i-1,P.j-1));
		}
		if (P.i < N-1 && P.j < M-1 && _M[2][P.i+1][P.j+1] && !visited[2][P.i+1][P.j+1]){
			visited[2][P.i+1][P.j+1] = true;
			q.push(mp(P.i+1,P.j+1));
		}
		if (P.j > 0 && P.i < N-1 && _M[2][P.i+1][P.j-1] && !visited[2][P.i+1][P.j-1]){
			visited[2][P.i+1][P.j-1] = true;
			q.push(mp(P.i+1,P.j-1));
		}
		if (P.j < M-1 && P.i > 0 && _M[2][P.i-1][P.j+1] && !visited[2][P.i-1][P.j+1]){
			visited[2][P.i-1][P.j+1] = true;
			q.push(mp(P.i-1,P.j+1));
		}
	}
}

int main(){
	ll T;
	ll cnt[3];
	char tmp;
	scll(T);
	while (T--){
		RESET(visited);
		scll(N); scll(M);
		swap(N,M);
		for (ll i = 0; i < N; ++i){
			scc(tmp);
			for (ll j = 0; j < M; ++j){
				scc(tmp);
				_M[0][i][j] = tmp-48;
				_M[2][i][j] = _M[1][i][j] = _M[0][i][j];
			}
		}
		RESET(cnt);
		for (ll i = 0; i < N; ++i){
			for (ll j = 0; j < M; ++j){
				if (!visited[0][i][j] && _M[0][i][j]){
					bfs0(i,j);
					++cnt[0];
				}
				if (!visited[1][i][j] && _M[1][i][j]){
					bfs1(i,j);
					++cnt[1];
				}
				if (!visited[2][i][j] && _M[2][i][j]){
					bfs2(i,j);
					++cnt[2];
				}
			}
		}
		printf("%lld %lld %lld\n", cnt[0], cnt[1], cnt[2]);
	}
	return 0;
}