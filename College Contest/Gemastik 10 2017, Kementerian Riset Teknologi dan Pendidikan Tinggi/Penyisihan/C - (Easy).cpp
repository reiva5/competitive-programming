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


ll size[50];
bool visited[100];

bool cmp(pair<ll,vll> a, pair<ll,vll> b){
	return a.se.size() < b.se.size();
}

int main(){
	ll T;
	scll(T);
	while (T--){
		memset(size, 0, sizeof size);
		memset(visited, 0, sizeof visited);
		ll N;
		scll(N);
		pair<ll,vll> data[50];
		for (ll i = 0; i < N; ++i){
			scll(size[i]);
			--size[i];
		}
		for (ll i = 0; i < N; ++i){
			ll tmp;
			ll tmp_2;
			scll(tmp);
			for (ll i = 0; i < tmp; ++i){
				scll(tmp_2);
				data[i].se.pb(tmp_2);
			}
			data[i].fi = i;
		}
		sort(data,data+N,cmp);
		ll now = N;
		for (ll i = 0; i < N; ++i){
			ll id = data[i].fi;
			for (ll j = 0; j < data[i].se.size(); ++j){
				if (size[id] > 0 && !visited[data[i].se[j]]){
					--size[id];
					++now;
					visited[data[i].se[j]] = true;
				}
			}
		}
		cout << now << endl;
	}
	return 0;
}