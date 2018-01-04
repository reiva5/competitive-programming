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
#define SET(x,y) for(int _je = sizeof(x)/sizeof(x[0]); _je--;) x[_je] = y

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

#define i fi
#define j se

ll n, m, k;
char M[1005][1005];
pll A, B;
ll VAL[1005][1005];
ll visited[1005][1005];
queue<special> q;

void bfs(pll A){
	q.push(mp(0,A));
	special tmp;
	int i, j;
	int cnt;
	while (!q.empty()){
		tmp.fi = q.front().fi;
		tmp.se.i = q.front().se.i;
		tmp.se.j = q.front().se.j;
		q.pop();
		if (!visited[tmp.se.i][tmp.se.j]){
			visited[tmp.se.i][tmp.se.j] = true;
			VAL[tmp.se.i][tmp.se.j] = tmp.fi;
			//cerr << tmp.se.i << " " << tmp.se.j << endl;
 			//cerr << tmp.fi << endl;
			cnt = k;
			for (i = tmp.se.i+1; i < n && cnt-- && M[i][tmp.se.j] != '#' && VAL[i][tmp.se.j] >= tmp.fi+1; ++i){
				if (VAL[i][tmp.se.j] > tmp.fi+1){
					VAL[i][tmp.se.j] = tmp.fi+1;
					q.push(mp(tmp.fi+1,mp(i,tmp.se.j)));
				}
			}
			cnt = k;
			for (i = tmp.se.i-1; i >= 0 && cnt-- && M[i][tmp.se.j] != '#' && VAL[i][tmp.se.j] >= tmp.fi+1; --i){
				if (VAL[i][tmp.se.j] > tmp.fi+1){
					VAL[i][tmp.se.j] = tmp.fi+1;
					q.push(mp(tmp.fi+1,mp(i,tmp.se.j)));
				}
			}
			cnt = k;
			for (j = tmp.se.j+1; j < m && cnt-- && M[tmp.se.i][j] != '#' && VAL[tmp.se.i][j] >= tmp.fi+1; ++j){
				if (VAL[tmp.se.i][j] > tmp.fi+1){
					VAL[tmp.se.i][j] = tmp.fi+1;
					q.push(mp(tmp.fi+1,mp(tmp.se.i,j)));
				}
			}
			cnt = k;
			for (j = tmp.se.j-1; j >= 0 && cnt-- && M[tmp.se.i][j] != '#' && VAL[tmp.se.i][j] >= tmp.fi+1; --j){
				if (VAL[tmp.se.i][j] > tmp.fi+1){
					VAL[tmp.se.i][j] = tmp.fi+1;
					q.push(mp(tmp.fi+1,mp(tmp.se.i,j)));
				}
			}
		}
	}
}

int main(){
	RESET(visited);
	cin >> n >> m >> k;
	for (ll i = 0; i < n; ++i){
		for (ll j = 0; j < m; ++j){
			cin >> M[i][j];
			VAL[i][j] = 1e9;
		}
	}
	cin >> A.fi >> A.se;
	--A.fi;
	--A.se;
	cin >> B.fi >> B.se;
	--B.fi;
	--B.se;
	bfs(A);
	if (VAL[A.fi][A.se] != 1e9 && VAL[B.fi][B.se] != 1e9){
		cout << abs(VAL[A.fi][A.se]-VAL[B.fi][B.se]) << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}