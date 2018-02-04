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

map<char,vi> idx[2];
string a, b;
ll L[5005][5005];

int main(){
	ll T;
	scll(T);
	while (T--){
		ll A, B;
		scll(A);
		scll(B);
		cin >> a >> b;
		string simple_a, simple_b;
		simple_a.pb(a[0]);
		simple_b.pb(b[0]);
		for (ll i = 0; i < a.size(); ++i){
			if (simple_a.back() != a[i]){
				simple_a += a[i];
			}
		}
		for (ll i = 0; i < b.size(); ++i){
			if (simple_b.back() != b[i]){
				simple_b += b[i];
			}
		}
		A = simple_a.size();
		B = simple_b.size();
		a = simple_a;
		b = simple_b;
		idx[0].clear();
		idx[1].clear();

		ll i, j;
		for (i = 0; i <= A; ++i){
			for (j = 0; j <= B; ++j){
				if (i == 0 || j == 0){
					L[i][j] = 0;
				} else if (a[i-1] == b[j-1]){
					L[i][j] = L[i-1][j-1] + 1;
				} else {
					L[i][j] = max(L[i-1][j], L[i][j-1]);
				}
			}
		}
		cout << (A+B-L[A][B]) << endl;
	}
	return 0;
}