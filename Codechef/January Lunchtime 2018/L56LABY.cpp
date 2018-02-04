/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define Jehian using
#define Norman namespace
#define Saviero std
#define cepet {ios_base::sync_with_stdio(0);cin.tie(0);}

Jehian Norman Saviero;

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
#define SET(x,y) for(int _je = sizeof(x)/sizeof(x[0]); _je--;) x[_je] = y
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
#define special pair<ll,pll>

bool visit[1005][1005];
ll val[1005][1005];
priority_queue<special, vector<special>, less<special> > q;

int main(){
	ll T;
	scll(T);
	while (T--){
		ll n, m;
		scll(n);
		scll(m);
		RESET(visit);
		RESET(val);
		for (ll i = 0; i < n; ++i){
			for (ll j = 0; j < m; ++j){
				scll(val[i][j]);
				if (val[i][j] > 0){
					++val[i][j];
					q.push(mp(val[i][j],mp(i,j)));
				} else if (val[i][j] < 0){
					visit[i][j] = true;
				}
			}
		}
		ll i, j, harga;
		i = q.top().se.fi;
		j = q.top().se.se;
		visit[i][j] = true;
		while (!q.empty()){
			i = q.top().se.fi;
			j = q.top().se.se;
			harga = q.top().fi;
			q.pop();
			if (harga > 1) {
				--harga;
				if (i > 0 && !visit[i-1][j]){
					val[i-1][j] = harga;
					visit[i-1][j] = true;
					q.push(mp(harga,mp(i-1,j)));
				}
				if (i < n - 1 && !visit[i+1][j]){
					val[i+1][j] = harga;
					visit[i+1][j] = true;
					q.push(mp(harga,mp(i+1,j)));
				}
				if (j > 0 && !visit[i][j-1]){
					val[i][j-1] = harga;
					visit[i][j-1] = true;
					q.push(mp(harga,mp(i,j-1)));
				}
				if (j < m - 1 && !visit[i][j+1]){
					val[i][j+1] = harga;
					visit[i][j+1] = true;
					q.push(mp(harga,mp(i,j+1)));
				}
			}
		}
		for (ll i = 0; i < n; ++i){
			for (ll j = 0; j < m; ++j){
				if (val[i][j] > 0){
					printf("Y");
				} else if (val[i][j] == 0){
					printf("N");
				} else {
					printf("B");
				}
			}
			printf("\n");
		}
	}
	return 0;
}