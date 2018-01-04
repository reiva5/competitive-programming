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

bool pembagi[100100];
bool exist[100100];
ll cnt[100100];
ll data[100100];

int main(){
	memset(pembagi, 0, sizeof pembagi);
	memset(exist, 0, sizeof exist);
	memset(data, 0, sizeof data);
	memset(cnt, 0, sizeof cnt);

	ll N;
	scll(N);
	for (ll i = 0; i < N; ++i){
		ll temp;
		scll(temp);
		++data[temp];
	}

	for (ll i = 1; i <= 100000; ++i){
		for (ll j = 1; i*j <= 100000; ++j){
			cnt[i] += data[i*j];
		}
	}

	ll Q;
	scll(Q);
	for (ll i = 0; i < Q; ++i){
		ll temp;
		scll(temp);
		cout << cnt[temp] << endl;
	}
	return 0;
}