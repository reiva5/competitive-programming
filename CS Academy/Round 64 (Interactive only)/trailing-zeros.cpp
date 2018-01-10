/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define Jehian using
#define Norman namespace
#define Saviero std
#define cepet {ios_base::sync_with_stdio(0);cin.tie(0);}

Jehian Norman Saviero;

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

bool hehe[1000001];
int main(){
	RESET(hehe);
	ll MIN = 1, MAX = 1000000, MID;
	ll tmp;
	ll hit = 20;
	while (abs(MIN-MAX) > 1 && hit--){
		MID = (MIN+MAX)/2;
		cout << "Q " << MID << endl;
		scll(tmp);
		if (tmp == 1){
			for (ll i = MID; i >= 0; --i){
				if (hehe[i]){
					break;
				}
				hehe[i] = 1;
			}
			MIN = MID;
		} else {
			for (ll i = MID; i <= 1000000; ++i){
				if (!hehe[i]){
					break;
				}
				hehe[i] = 0;
			}
			MAX = MID;
		}
	}
	ll idx;
	for (ll i = 0; i <= 1000000; ++i){
		if (!hehe[i]){
			idx = i-1;
			break;
		}
	}
	ll cnt = 0;
	for (ll i = 5; i <= 1000000; ++i){
		ll j = i;
		while (j % 5 == 0){
			j /= 5;
			++cnt;
		}
		if (cnt >= idx){
			cout << "A " << i << endl;
			return 0;
		}
	}
	cout << "A " << 1000000 << endl;
	return 0;
}