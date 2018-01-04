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

vll go[100100];

bool visited[100100];

char jenis[100100];
ll cnt[256];
int main(){
	memset(visited, 0, sizeof visited);
	memset(jenis, 0, sizeof jenis);
	memset(cnt, 0, sizeof cnt);
	ll N;
	scll(N);
	for (ll i = 0; i < N-1; ++i){
		ll A, B;
		scll(A); scll(B);
		go[A].pb(B);
		go[B].pb(A);
	}
	jenis[1] = 'r';
	queue<ll> q;
	q.push(1);
	++cnt[jenis[1]];
	while (!q.empty()){
		ll tmp = q.front();
		q.pop();
		visited[tmp] = true;
		char next = jenis[tmp] == 'r' ? 'b' : 'r';
		for (ll i = 0; i < go[tmp].size(); ++i){
			if (!visited[go[tmp][i]]){
				jenis[go[tmp][i]] = next;
				++cnt[next];
				q.push(go[tmp][i]);
			}
		}
	}
	cout << cnt['r']*cnt['b'] - (N-1) << endl;
	return 0;
}