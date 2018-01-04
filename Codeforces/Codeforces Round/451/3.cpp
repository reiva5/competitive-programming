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

string name;
map<string, pair< set<string>, set<string> > > data;
set<string>::iterator it;

int main(){
	ll N;
	scll(N);
	ll T;
	string tmp;
	ll ukuran = 1;
	for (ll i = 0; i < N; ++i){
		cin >> name;
		scll(T);
		while (T--){
			cin >> tmp;
			ukuran = 1;
			while (ukuran < tmp.size()){
				it = data[name].se.find(tmp.substr(tmp.size()-ukuran,ukuran));
				data[name].fi.insert(tmp.substr(tmp.size()-ukuran,ukuran));
				if (it != data[name].se.end()){
					data[name].se.erase(tmp.substr(tmp.size()-ukuran,ukuran));
				}
				++ukuran;
			}
			it = data[name].fi.find(tmp);
			if (it == data[name].fi.end()){
				data[name].se.insert(tmp);
				data[name].fi.insert(tmp);
			}
		}
	}
	cout << data.size() << endl;
	for (auto x : data){
		cout << x.fi << " " << x.se.se.size();
		for (auto y : x.se.se){
			cout << " " << y;
		}
		cout << endl;
	}
	return 0;
}