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

ld dist(ld a, ld b){
	return abs(a-b);
}

int main(){
	ll N;
	ld R;
	scll(N);
	cin >> R;
	ll data[N];
	for (ll i = 0; i < N; ++i){
		scll(data[i]);
	}
	ld now[N];
	now[0] = R;
	cout << setprecision(10) << fixed << now[0];
	// cerr << endl;
	for (ll i = 1; i < N; ++i){
		bool benar = true;
		// cerr << "> " << i << endl;
		for (ll j = 0; j < i && benar; ++j){
			if (dist(data[i],data[j]) <= 2.00*R){
				benar = false;
				// cerr << data[i] << " " << data[j] << endl;
			}
		}
		if (benar){
			now[i] = R;
		} else {
			now[i] = R;
			ll idx = -1;
			for (ll j = 0; j < i; ++j){
				if (dist(data[i],data[j]) <= 2.00*R){
					now[i] = max(now[i],now[j]+sqrt(SQR(2.00*R)-SQR(dist(data[i],data[j]))));
				}
			}
			// cerr << "> jarak: " << sqrt(SQR(2.00*R)-SQR(dist(data[i],data[idx]))) << endl;
		}
		cout << setprecision(10) << fixed << " " << now[i];
	}
	cout << endl;
	return 0;
}