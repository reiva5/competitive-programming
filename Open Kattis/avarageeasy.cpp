// Bismillaahirrahmaanirrahiim
/* Author	: Jehian Norman Saviero (@Reiva5) */
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
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define eb emplace_back
#define RESET(x) memset((x), 0, sizeof(x))
#define SET(x,y) for(int _je = sizeof(x)/sizeof(x[0]); _je--;) x[_je] = y
#define SQR(x) (x)*(x)
#define CUBE(x) SQR(x)*(x)

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


void AVG(ll a, ll b){
	cerr << setprecision(5) << fixed << 1.00 * a / b << endl;
}
ll CS[1000000], E[1000000];
ll sum_cs, sum_e;
ll cs, e, cnt;
ll i;
int main(){
	ll T;
	scll(T);
	while (T--){
		scll(cs); scll(e);
		sum_cs = 0;
		sum_e = 0;
		for (i = 0; i < cs; ++i){
			scll(CS[i]);
			sum_cs += CS[i];
		}
		for (i = 0; i < e; ++i){
			scll(E[i]);
			sum_e += E[i];
		}
		cnt = 0;
		for (i = 0; i < cs; ++i){
			if (((CS[i]+sum_e)*e > (e+1)*sum_e) && ((sum_cs-CS[i])*cs > (cs-1)*sum_cs)){
				++cnt;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}