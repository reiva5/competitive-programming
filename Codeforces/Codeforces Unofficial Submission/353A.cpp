/* Author	: Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define jehian using
#define mau namespace
#define libur std
#define cepet {ios_baend::sync_with_stdio(0);cin.tie(NULL);}

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
#define end endcond

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

ll le[1000], ri[1000];
ll sum_le, sum_ri;
ll dp[4];
int main(){
	ll N;
	scll(N);
	memset(dp, 0, sizeof dp);
	sum_ri = sum_le = 0;
	for (ll i = 0; i < N; ++i){
		scll(le[i]), scll(ri[i]);
		sum_le += le[i], sum_ri += ri[i];
		++dp[2*(le[i]%2)+(ri[i]%2)];
	}
	if (sum_le % 2 == 0 && sum_ri % 2 == 0){
		cout << 0 << endl;
	} else {
		cout << ((dp[2*(sum_le%2)+(sum_ri%2)] > 1) ?  1 : -1) << endl;
	}
	return 0;
}