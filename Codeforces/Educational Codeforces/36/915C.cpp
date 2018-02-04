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

string tmp;
string gabung(string& a, string& b){
	tmp.clear();
	for (auto& it : a){
		tmp.pb(it);
	}
	for (auto& it : b){
		tmp.pb(it);
	}
	return tmp;
}

string gabung(string& a, char& b){
	tmp.clear();
	for (auto& it : a){
		tmp.pb(it);
	}
	tmp.pb(b);
	return tmp;
}

int main(){
	string A, B;
	cin >> A >> B;
	sort(ALL(A));
	reverse(ALL(A));
	if (A.size() < B.size()) {
		cout << A << endl;
	} else {
		if (A <= B) {
			cout << A << endl;
		} else {
			string sol = "";
			for (ll i = 0; i < B.size(); ++i){
				bool ketemu = false;
				cerr << "Phase: " << i+1 << endl;
				for (ll j = 0; j < A.size() && !ketemu; ++j) {
					cerr << gabung(sol,A[j]) << " --- " << B.substr(0,i+1) << endl;
					if (gabung(sol,A[j]) <= B.substr(0,i+1)){
						sol.pb(A[j]);
						A.erase(j,1);
						ketemu = true;
						cerr << "ketemu" << endl;
					}
				}
				if (!ketemu) {
					bool benar = false;
					ll idx = i-1;
					while (!benar && idx >= 0){
						A.pb(sol.back());
						sol.erase(sol.size()-1,1);
						sort(ALL(A));
						reverse(ALL(A));
						char MIN = A[0];
						bool stopper = false;
						for (ll j = 0; j < A.size() && !stopper; ++j) {
							if (A[j] < B[idx]) {
								MIN = A[j];
								A.erase(j,1);
								stopper = true;
							}
						}
						if (stopper) {
							sol.pb(MIN);
							cout << gabung(sol,A) << endl;
							return 0;
						} else {
							--idx;
						}
					}
					if (!benar) {
						sort(ALL(A));
						cout << A << endl;
						return 0;
					}
				}
			}
			cout << sol << endl;
		}
	}
	return 0;
}