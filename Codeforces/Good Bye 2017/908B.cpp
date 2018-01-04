/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define Good using
#define Bye namespace
#define Y2017 std
#define cepet {ios_base::sync_with_stdio(nullptr);cin.tie(nullptr);}

/* ================= */

	Good Bye Y2017;

/* ================= */

/* MACROS FOR TYPE */
typedef long l;
typedef long double ld;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;

/* MACROS FOR PRINT */
#define nl printf("\n")
#define sp printf(" ")

/* MACROS FOR FUNCTION AND METHOD */
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define eb emplace_back
#define RESET(x) memset((x), 0, sizeof(x))
#define SET(x,y) for(ll _je = sizeof(x)/sizeof(x[0]); _je--;) x[_je] = y
#define SQR(x) (x)*(x)
#define CUBE(x) SQR(x)*(x)
#define ALL(x) (x).begin(), (x).end()
#define ALLSIZE(x,n) (x), (x)+(n)

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

ll it[4];
bool any[4];
bool allDiffer(){
	RESET(any);
	for (ll i = 0; i < 4; ++i){
		any[it[i]] = true;
	}
	return any[0] && any[1] && any[2] && any[3];
}

ll n, m;
string M[100];
string pindah;
vector<int> MOVE;

pll start, keluar;

#define i fi
#define j se

bool valid(){
	pll now = start;
	ll x, z = 0, i, j;
	for (z = 0; z < MOVE.size()-1; ++z){
		x = MOVE[z];
		i = now.i;
		j = now.j;
		if (it[x] == 0){
			now = mp(i+1,j);
		} else if (it[x] == 1){
			now = mp(i-1,j);
		} else if (it[x] == 2){
			now = mp(i,j+1);
		} else {
			now = mp(i,j-1);
		}
		if (now.i < 0 || now.i >= n || now.j < 0 || now.j >= m || M[now.i][now.j] == '#'){
			return 0;
		} else if (M[now.i][now.j] == 'E'){
			return 1;
		}
	}
	x = MOVE[z];
	i = now.i;
	j = now.j;
	if (it[x] == 0){
		now = mp(i+1,j);
	} else if (it[x] == 1){
		now = mp(i-1,j);
	} else if (it[x] == 2){
		now = mp(i,j+1);
	} else {
		now = mp(i,j-1);
	}
	if (now.i < 0 || now.i >= n || now.j < 0 || now.j >= m || M[now.i][now.j] == '.' || M[now.i][now.j] == '#' || M[now.i][now.j] == 'S'){
		return 0;
	} else {
		return 1;
	}
}

ll cnt = 0;
int main(){
	scll(n);
	scll(m);
	for (ll i = 0; i < n; ++i){
		cin >> M[i];
	}
	for (ll i = 0; i < n; ++i){
		for (ll j = 0; j < m; ++j){
			if (M[i][j] == 'S'){
				start = mp(i,j);
			} else if (M[i][j] == 'E'){
				keluar = mp(i,j);
			}
		}
	}
	RESET(it);
	cin >> pindah;
	for (auto& x : pindah){
		MOVE.pb(x-48);
	}
	for (it[0] = 0; it[0] < 4; ++it[0]){
		for (it[1] = 0; it[1] < 4; ++it[1]){
			for (it[2] = 0; it[2] < 4; ++it[2]){
				for (it[3] = 0; it[3] < 4; ++it[3]){
					if (allDiffer()){
						if (valid()){
							++cnt;
						}
					}
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}