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

ll GET[2][100100];
ll prefixsum[2][100100];
ll win[2];

int main(){
	pll A[2], B[2];
	for (ll i = 0; i < 2; ++i){
		scll(A[i].fi); scll(A[i].se);
		scll(B[i].fi); scll(B[i].se);
	}
	memset(GET, 0, sizeof GET);
	for (ll x = 0; x < 2; ++x){
		for (ll i = A[x].fi; i <= A[x].se; ++i){
			for (ll j = B[x].fi; j <= B[x].se; ++j){
				++GET[x][i+j];
			}
		}
	}
	memset(prefixsum, 0, sizeof prefixsum);
	for (ll x = 0; x < 2; ++x){
		ll i;
		prefixsum[x][A[x].fi+B[x].fi] = GET[x][A[x].fi+B[x].fi];
		for (i = A[x].fi+B[x].fi+1; i <= A[x].se+B[x].se; ++i){
			prefixsum[x][i] = prefixsum[x][i-1] + GET[x][i];
		}
		for (; i <= 100000; ++i){
			prefixsum[x][i] = prefixsum[x][i-1];
		}
	}
	win[0] = win[1] = 0;
	for (ll x = 0; x < 2; ++x){
		for (ll i = A[x].fi+B[x].fi; i <= A[x].se+B[x].se; ++i){
			win[x] += prefixsum[!x][i-1];
		}
	}
	cerr << win[0] << " " << win[1] << endl;
	if (win[0]* == win[1]) printf("draw\n");
	else if (win[0] > win[1]) printf("mantan\n");
	else printf("love\n");
	return 0;
}