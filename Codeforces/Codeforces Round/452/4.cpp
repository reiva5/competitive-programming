/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define Lost using
#define In namespace
#define Colour std
#define cepet {ios_base::sync_with_stdio(0);cin.tie(0);}

Lost In Colour;

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

int main(){
	ll N;
	scll(N);
	ll MAX = N+(N-1);
	ll sol[10] = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 9999999999};
	ll pangkat_10[11];
	ll idx = -1;
	for (ll i = 0; i < 10; ++i){
		if (MAX < sol[i]){
			idx = i-1;
			break;
		}
	}
	if (idx == -1){
		cout << N*(N-1)/2 << endl;
		return 0;
	}
	ll res = 0;
	cerr << "> " << res << endl;
	pangkat_10[0] = 1;
	for (ll i = 1; i < 11; ++i){
		pangkat_10[i] = pangkat_10[i-1]*10;
	}
	ll idx2 = 0;
	for (ll i = 0; i < 11; ++i){
		if (pangkat_10[i] > sol[idx]){
			idx2 = i;
			break;
		}
	}
	ll tmp = 1e11;
	for (ll i = 0; i < 10; ++i){
		if (pangkat_10[idx2]*i + sol[idx] <= MAX){
			cerr << "masuk: " << pangkat_10[idx2]*i + sol[idx] << endl;
			ll max_num = min(N,pangkat_10[idx2]*i+sol[idx]);
			ll min_num = (pangkat_10[idx2]*i + sol[idx]) - N;
			min_num = max(min_num,1LL);
			cerr << "max: " << max_num << " " << "min: " << min_num << endl;
			res += (max_num - min_num + 1)/2;
		} else {
			tmp = pangkat_10[idx2]*i + sol[idx] - N;
		}
	}
	cerr << "> sisa: " << tmp << endl;
	if (N > tmp){
		res += (N - tmp + 1)/2;
	}
	cout << res << endl;
	return 0;
}