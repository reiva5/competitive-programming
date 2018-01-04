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

bool used[100100];
int main(){
	memset(used, 0, sizeof used);
	int N, X;
	sci(N); sci(X);
	int res = X;
	for (int i = 1; i < N; ++i){
		int tmp;
		tmp = i;
		res ^= tmp;
		cerr << res << endl;
		used[tmp] = true;
	}
	bool found = false;
	int last;
	for (int j = N; j <= 1000000 && !found; ++j){
		int tmp = res^0;
		cerr << tmp << endl;
		if (!used[tmp]){
			found = true;
			last = tmp;
		}
	}
	if (found){
		cout << "YES" << endl;
		cout << 1;
		for (int i = 2; i < N; ++i){
			cout << " " << i;
		}
		cout << " " << last << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}