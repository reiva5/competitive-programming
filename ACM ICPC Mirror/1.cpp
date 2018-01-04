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

unordered_map<ll, vll> occur;
ll cnt = 0;

void binary_search(ll first, ll last, ll find){
	if (first == last){
		if (occur[first].back() > find){
			cnt++;
			occur[cnt].pb(find);
		} else {
			occur[first].pb(find);
		}
	} else {
		ll mid = (first+last)/2;
		if (occur[mid].back() > find){
			binary_search(mid+1,last,find);
		} else {
			binary_search(first,mid,find);
		}
	}
}

int main(){
	ll T;
	scanf("%lld", &T);
	ll data[T];
	for (ll i = 0; i < T; ++i){
		scanf("%lld", &data[i]);
	}
	occur[cnt].pb(data[0]);
	for (ll i = 1; i < T; ++i){
		binary_search(0,cnt,data[i]);
	}
	for (ll i = 0; i <= cnt; ++i){
		printf("%lld", occur[i][0]);
		for (ll j = 1; j < occur[i].size(); ++j){
			printf(" %lld", occur[i][j]);
		}
		printf("\n");
	}
	return 0;
}