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

vector<string> words;
unordered_map<string, bool> visited;
string wutt[3];
ll T;
string a;

int main(){
	scll(T);
	getline(cin,a);
	while (T--){
		getline(cin,a);
		stringstream ss(a);
		string buf;
		while (ss >> buf) words.pb(buf);
		bool found = false;
		while (getline(cin,a) && !found){
			if (a != "what does the fox say?"){
				stringstream _ss(a);
				_ss >> wutt[0] >> wutt[1] >> wutt[2];
				visited[wutt[2]] = true;
			} else {
				found = true;
				break;
			}
		}
		string space = "";
		for (auto it : words){
			if (!visited[it]){
				cout << space << it;
				space = " ";
			}
		}
		cout << endl;
		words.clear();
		visited.clear();
	}
	return 0;
}