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

deque<ll> hehe, sol;
vll data;
int main(){
	ll T;
	scll(T);
	ll cnt = 1;
	while (T--){
		hehe.clear();
		sol.clear();
		data.clear();
		ll N;
		scll(N);
		if (N & 1){
			hehe.pb((N-1)/2);			
			for (ll i = (N-1)/2-1; i >= 0; --i){
				hehe.pb(i);
				hehe.pf(i);
			}
		} else {
			for (ll i = N/2-1; i >= 0; --i){
				hehe.pb(i);
				hehe.pf(i);
			}
		}
		ll tmp;
		for (ll i = 0; i < N; ++i){
			scll(tmp);
			data.pb(tmp);
		}
		sort(ALL(data));
		reverse(ALL(data));
		for (ll i = 0; i < N; ++i){
			if (i & 1){
				sol.pb(data[i]);
			} else {
				sol.pf(data[i]);
			}
		}
		ll ANS = 0;
		for (ll i = 0; i < N; ++i){
			ANS += SQR(hehe[i]-sol[i]);
		}
		cout << "Case #" << cnt++ << ": " << ANS << endl;
	}
	return 0;
}