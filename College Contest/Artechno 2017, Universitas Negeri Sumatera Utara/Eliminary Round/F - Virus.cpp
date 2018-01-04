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

#define i fi
#define j se

char M[16][16];
void bfs(pll P){
	queue<pll> q;
	q.push(P);
	while (!q.empty()){
		pll p = q.front();
		q.pop();
		if (p.i > 0 && M[p.i-1][p.j] == 'x'){
			q.push(mp(p.i-1,p.j));
			M[p.i-1][p.j] = 'o';
		}
		if (p.j > 0 && M[p.i][p.j-1] == 'x'){
			q.push(mp(p.i,p.j-1));
			M[p.i][p.j-1] = 'o';
		}
		if (p.i < 15 && M[p.i+1][p.j] == 'x'){
			q.push(mp(p.i+1,p.j));
			M[p.i+1][p.j] = 'o';
		}
		if (p.j < 15 && M[p.i][p.j+1] == 'x'){
			q.push(mp(p.i,p.j+1));
			M[p.i][p.j+1] = 'o';
		}
	}
}

int main(){
	for (ll i = 0; i < 16; ++i){
		for (ll j = 0; j < 16; ++j){
			do {
				scc(M[i][j]);
			} while (M[i][j] == '\n' || M[i][j] == ' ');
		}
	}
	for (ll i = 0; i < 16; ++i){
		for (ll j = 0; j < 16; ++j){
			if (M[i][j] == 'o'){
				bfs(mp(i,j));
			}
		}
	}
	ll cnt = 0;
	for (ll i = 0; i < 16; ++i){
		for (ll j = 0; j < 16; ++j){
			cnt += M[i][j] == 'o';
		}
	}
	cout << cnt << endl;
	return 0;
}