// Bismillaahirrahmaanirrahiim
/* Author	: Jehian Norman Saviero (@Reiva5) */
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
#define mp make_pair
#define eb emplace_back
#define RESET(x) memset((x), 0, sizeof(x))
#define SET(x,y) for(int _je = sizeof(x)/sizeof(x[0]); _je--;) x[_je] = y

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

string A, B;
string solution[2];

int main(){
	solution[0] = solution[1] = "";
	cin >> A >> B;
	ll j = (ll) B.size();
	for (ll i = 0; i <= A.size(); ++i){
		if (j-i >= 0 && A.substr(0,i) == B.substr(j-i,i)){
			solution[0] = B + A.substr(i,A.size()-i);
		}
	}
	j = (ll) A.size();
	for (ll i = 0; i <= B.size(); ++i){
		if (j-i >= 0 && B.substr(0,i) == A.substr(j-i,i)){
			solution[1] = A + B.substr(i,B.size()-i);
		}
	}
	if (solution[0].size() && solution[0].size() < solution[1].size()){
		cout << solution[0] << endl;
	} else if (solution[1].size() && solution[0].size() > solution[1].size()){
		cout << solution[1] << endl;
	} else {
		if (A.size() >= B.size()){
			cout << solution[1] << endl;
		} else {
			cout << solution[0] << endl;
		}
	}
	return 0;
}