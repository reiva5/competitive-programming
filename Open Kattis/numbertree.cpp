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
typedef pair<double,double> pd;
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
#define scld(x) cin >> x;
#define scui(x) sci(x)
#define scul(x) scl(x)
#define scull(x) scll(x)

ll pow(ll a, ll b){
	ll res = 1;
	while (b--){
		res *= a;
	}
	return a;
}

int main(){
	int N;
	sci(N);
	char c;
	ll res = pow(2,N+1)-1;
	scc(c);
	ll pengurang = 1;
	ll LEFTMOST = res;
	while (scc(c) != EOF){
		if (c == 'R' || c == 'L'){
			res -= ((LEFTMOST-res)+pengurang);
		}

		if (c == 'R'){
			--res;
		}
		LEFTMOST -= pengurang;
		pengurang *= 2;
	}
	cout << res << endl;
	return 0;
}