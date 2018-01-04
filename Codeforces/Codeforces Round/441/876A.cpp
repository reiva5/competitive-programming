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

bool visited[256];
int main(){
	RESET(visited);
	ll res[3];
	ll N, ro, _or, er, re, oe, eo;
	scll(N); scll(ro); scll(re); scll(oe);
	RESET(res);
	RESET(visited);
	visited['r'] = true;
	for (int i = 1; i < N; ++i){
		if (visited['r']){
			cerr << "r" << endl;
			visited['r'] = false;
			if (ro < re){
				visited['o'] = true;
				res[0] += ro;
			} else {
				visited['e'] = true;
				res[0] += re;
			}
		} else if (visited['o']){
			cerr << "o" << endl;
			visited['o'] = false;
			if (ro < oe){
				visited['r'] = true;
				res[0] += ro;
			} else {
				visited['e'] = true;
				res[0] += oe;
			}
		} else {
			cerr << "e" << endl;
			visited['e'] = false;
			if (oe < re){
				visited['o'] = true;
				res[0] += oe;
			} else {
				visited['r'] = true;
				res[0] += re;
			}			
		}
	}
	cout << res[0] << endl;
	return 0;
}