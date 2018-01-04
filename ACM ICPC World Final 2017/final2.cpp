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

vector<char> go[256];

bool visited[256];
bool dfs(char a, char b){
	if (a == b){
		return true;
	} else {
		bool cari = false;
		for (ll i = 0; i < go[a].size() && !cari; ++i){
			if (!visited[go[a][i]]){
				visited[go[a][i]] = true;
				cari = cari || dfs(go[a][i],b);
			}
		}
		return cari;
	}
}

int main(){
	ll m, n;
	scll(m); scll(n);
	for (ll i = 0; i < m; ++i){
		char a, b;
		cin >> a >> b;
		go[a].pb(b);
	}
	for (ll i = 0; i < n; ++i){
		string a, b;
		cin >> a >> b;
		if (a.size() == b.size()){
			bool benar = true;
			for (ll i = 0; i < a.size() && benar; ++i){
				memset(visited, 0, sizeof visited);
				benar = dfs(a[i],b[i]);
			}
			if (benar){
				cout << "yes" << endl;
			} else {
				cout << "no" << endl;
			}
		} else {
			cout << "no" << endl;
		}
	}
	return 0;
}