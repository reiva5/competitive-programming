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

ll data[100005];
ll dp[100005];
multiset<ll> q;

int main(){
	ll N, K;
	ll i, cnt = 0;
	scll(N);
	scll(K);
	for (i = 0; i < N; ++i){
		scll(data[i]);
	}
	for (i = 0; i <= min(N-1,K); ++i){
		q.insert(data[i]);
	}
	dp[cnt++] = *q.begin();
	cerr << "size: " << q.size() << endl;
	auto itr = q.find(data[0]);
	for (i = 1; i < N; ++i){
		if (i+K < N){
			itr = q.find(data[i-1]);
			q.erase(itr);
			q.insert(data[i+K]);
			dp[cnt++] = *q.begin();
		} else {
			itr = q.find(data[i-1]);
			q.erase(itr);
			dp[cnt++] = *q.begin();
		}
	}
	for (ll j = 0; j < N; ++j){
		cerr << dp[j] << " ";
	}
	cerr << endl;
	bool found = false;
	ll idx;
	for (i = 0; i < N && !found; ++i){
		if (dp[i] < data[i]){
			found = true;
			idx = i;
		}
	}
	if (found){
		found = false;
		for (i = min(N-1,idx+K); i > idx && !found; --i){
			if (dp[idx] ==  data[i]){
				swap(data[idx],data[i]);
			}
		}
	}
	for (i = 0; i < N-1; ++i){
		printf("%lld ", data[i]);
	}
	printf("%lld\n", data[N-1]);
	return 0;
}