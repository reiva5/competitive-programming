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

bool isPrime[100100];
vll prime;

void pre(){
	memset(isPrime, 1, sizeof isPrime);
	isPrime[0] = false;
	isPrime[1] = false;
	for (ll i = 2; i <= 100000; ++i){
		if (isPrime[i]){
			prime.pb(i);
			for (ll j = 2; i*j <= 100000; ++j){
				isPrime[i*j] = false;
			}
		}
	}
}

ll res = 0;
int main(){
	pre();
	ll in;
	scll(in);
	for (ll i = 0; i < prime.size(); ++i){
		ll cnt = 0;
		while (in % prime[i] == 0){
			in /= prime[i];
			++cnt;
		}
		res += cnt;
	}
	cout << (res + (in != 1)) << endl;
	return 0;
}