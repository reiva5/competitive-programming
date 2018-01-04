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

ll K[1010][550];
int main(){
	ll T;
	scll(T);
	while (T--){
		ll C, N;
		scll(C);
		scll(N);
		ll wt[N];
		ll val[N];
		for (ll i = 0; i < N; ++i){
			scll(wt[i]);
			scll(val[i]);
		}
		int i, w;
		for (i = 0; i <= N; i++){
			for (w = 0; w <= C; w++){
				if (i==0 || w==0)
					K[i][w] = 0;
				else if (wt[i-1] <= w)
					K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
				else
					K[i][w] = K[i-1][w];
			}
		}
		cout << K[N][C] << endl;
	}
	return 0;
}