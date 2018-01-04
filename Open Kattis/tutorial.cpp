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
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define eb emplace_back
#define SQR(x) (x)*(x)
#define CUBE(x) SQR(x)*(x)
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

int main(){
	ll M, N, T;
	scll(M);
	scll(N);
	scll(T);
	bool valid;
	switch(T){
		case 1:{
			ll res = 1;
			for (ll i = 1; i <= N && res <= M; ++i){
				res *= i;
			}
			valid = res <= M;
			break;
		}
		case 2:{
			ll res = 1;
			for (ll i = 1; i <= N && res <= M; ++i){
				res *= 2;
			}
			valid = res <= M;
			break;
		}
		case 3:{
			ll res = 1;
			for (ll i = 1; i <= 4 && res <= M; ++i){
				res *= N;
				cerr << res << endl;
			}
			valid = res <= M;
			break;
		}
		case 4:{
			ll res = 1;
			for (ll i = 1; i <= 3 && res <= M; ++i){
				res *= N;
			}
			valid = res <= M;
			break;
		}
		case 5:{
			ll res = 1;
			for (ll i = 1; i <= 2 && res <= M; ++i){
				res *= N;
			}
			valid = res <= M;
			break;
		}
		case 6:{
			ld res = (ld) N * (ld) log(N) / (ld) log(2);
			valid = res <= (ld) M;
			break;
		}
		case 7:{
			ll res = 1;
			for (ll i = 1; i <= 1 && res <= M; ++i){
				res *= N;
			}
			valid = res <= M;
			break;
		}
	}
	cout << (valid ? "AC" : "TLE") << endl;
	return 0;
}