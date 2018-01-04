/* Author	: Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define jehian using
#define mau namespace
#define libur std
#define cepet {ios_base::sync_with_stdio(false);cin.tie(NULL);}

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
#define scld(x) scanf("%Lf", &x)
#define scui(x) sci(x)
#define scul(x) scl(x)
#define scull(x) scll(x)


int HASH[200100];
int _fix[2][5000];
int sorted[2][5000];

int main(){
	cepet;
	int T;
	cin >> T;
	while (T){
		for (int i = 0; i < 2; ++i){
			for (int j = 0; j < T; ++j){
				cin >> _fix[i][j];
				sorted[i][j] = _fix[i][j];
			}
		}
		for (int i = 0; i < 2; ++i) sort(sorted[i],sorted[i]+T);
		for (int i = 0; i < T; ++i) HASH[sorted[0][i]+100000] = sorted[1][i];
		for (int i = 0; i < T; ++i){
			printf("%d\n",HASH[_fix[0][i]+100000]);
		}
		nl;
		cin >> T;
	}
}