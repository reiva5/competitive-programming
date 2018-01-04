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

map<ll, vll> idx;
set<ll> hit;
ll N;
ll UP, DOWN;

ll binser(ll val, ll find, ll awal, ll akhir){
	if (awal == akhir){
		if (idx[val][awal] <= find){
			return awal;
		} else {
			return -1;
		}
	}
	if (akhir-awal == 1){
		if (idx[val][akhir] <= find){
			return akhir;
		} else if (idx[val][awal] <= find){
			return awal;
		} else {
			return -1;
		}
	}
	ll mid = (awal+akhir)/2;
	if (find <= idx[val][mid]){
		return binser(val, find, awal, mid);
	} else {
		return binser(val, find, mid+1, akhir);
	}
}

ll findNeighbour2(ll val, ll i){
	ll tmp_up = 0, tmp_down = 0;
	if (hit.find(val+1) != hit.end()){
		UP = binser(val+1,i,0,idx[val+1].size()-1);
		tmp_up = UP+1;
		tmp_up = idx[val+1].size() - tmp_up;
	}
	if (hit.find(val-1) != hit.end()){
		DOWN = binser(val-1,i,0,idx[val-1].size()-1);
		tmp_down = DOWN+1;
		tmp_down = idx[val-1].size() - tmp_down;
	}
	return tmp_up + tmp_down;
}

ll findNeighbour(ll val, ll i){
	ll tmp_up = 0, tmp_down = 0;
	if (hit.find(val+1) != hit.end()){
		UP = binser(val+1,i,0,idx[val+1].size()-1);
		tmp_up = UP+1;
	}
	if (hit.find(val-1) != hit.end()){
		DOWN = binser(val-1,i,0,idx[val-1].size()-1);
		tmp_down = DOWN+1;
	}
	return tmp_up + tmp_down;	
}

int main(){
	scll(N);
	ll data[N];
	for (ll i = 0; i < N; ++i){
		scll(data[i]);
		idx[data[i]].pb(i);
		hit.insert(data[i]);
	}
	ll sum = 0;
	ll cnt = 0;
	for (ll i = 1; i < N; ++i){
		sum += (i-findNeighbour(data[i],i))*data[i];
	}
	for (ll i = 0; i < N-1; ++i){
		sum -= (N-i-1-findNeighbour2(data[i],i))*data[i];
	}
	cout << sum+(cnt/2) << endl;
	return 0;
}