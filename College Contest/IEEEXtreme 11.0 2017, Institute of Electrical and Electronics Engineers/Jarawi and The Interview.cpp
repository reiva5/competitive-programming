// Bismillaahirrahmaanirrahiim
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
#define mp make_pair
#define eb emplace_back
#define RESET(x) memset((x), 0, sizeof(x))
#define SET(x,y) memset((x), (y), sizeof(x))

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

vll data[256];
ll idx[256];
ll binary_search(ll le, ll ri, char c, ll LAST){
	if (le == ri){
		if (data[c][le] < LAST){
			idx[c] = le-1;
			return data[c][le];
		} else {
			return -1;
		}
	} else if (ri-le == 1){
		if (data[c][ri] < LAST){
			idx[c] = ri-1;
			return data[c][ri];
		} else if (data[c][le] < LAST){
			idx[c] = le-1;
			return data[c][le];
		} else {
			return -1;
		}
	} else {
		ll mid = (le+ri)/2;
		if (data[c][mid] < LAST){
			return binary_search(mid, ri, c, LAST);
		} else {
			return binary_search(le, mid, c, LAST);
		}
	}
}

int main(){
	string s;
	string p;
	cin >> s;
	for (ll i = 0; i < s.size(); ++i){
		data[s[i]].pb(i);
	}
	ll q;
	cin >> q;
	while (q--){
		for (ll i = 'a'; i <= 'z'; ++i){
			idx[i] = data[i].size()-1;
		}
		cin >> p;
		ll cnt = 0;
		ll last = s.size();
		for (ll j = p.size()-1; j >= 0 && last >= 0; --j){
			if (idx[p[j]] >= 0){
				last = binary_search(0, idx[p[j]], p[j], last);
				if (last >= 0){
					++cnt;
				}
			} else {
				last = -1;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}