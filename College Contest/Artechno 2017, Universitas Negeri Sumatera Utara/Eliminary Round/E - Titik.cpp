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

int main(){
	ll N;
	scll(N);
	string A;
	cin >> A;
	char M[A.size()/N][N];
	memset(M, '\0', sizeof M);
	for (ll i = 0; i < A.size()/N; ++i){
		for (ll j = 0; j < N; ++j){
			M[i][j] = A[i*N+j];
		}
	}
	ll _M = A.size()/N;
	ll cnt = 0;
	for (ll i = 0; i < A.size()/N-1; ++i){
		for (ll j = 0; j < N-1; ++j){
			if (M[i][j] == M[i+1][j] && M[i+1][j] == M[i+1][j+1] && M[i][j+1] == M[i][j] && M[i][j] != '\0'){
				++cnt;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}