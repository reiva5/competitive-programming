/* Author   : Jehian Norman Saviero (@Reiva5) */
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

set<string> pemain;
int main(){
	ll N;
	scll(N);
	pemain.insert("Alex");
	pemain.insert("Bob");
	string nganggur = "Carl";
	for (ll i = 0; i < N; ++i){
		ll T;
		scll(T);
		if (T == 1 && pemain.find("Alex") != pemain.end()){
			if (nganggur == "Carl"){
				pemain.erase("Bob");
				pemain.insert("Carl");
				nganggur = "Bob";
			} else {
				pemain.erase("Carl");
				pemain.insert("Bob");
				nganggur = "Carl";
			}
		} else if (T == 2 && pemain.find("Bob") != pemain.end()){
			if (nganggur == "Alex"){
				pemain.erase("Carl");
				pemain.insert("Alex");
				nganggur = "Carl";
			} else {
				pemain.erase("Alex");
				pemain.insert("Carl");
				nganggur = "Alex";
			}
		} else if (T == 3 && pemain.find("Carl") != pemain.end()){
			if (nganggur == "Bob"){
				pemain.erase("Alex");
				pemain.insert("Bob");
				nganggur = "Alex";
			} else {
				pemain.erase("Bob");
				pemain.insert("Alex");
				nganggur = "Bob";
			}
		} else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}