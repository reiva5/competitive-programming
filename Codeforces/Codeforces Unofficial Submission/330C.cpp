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

int main(){
	ll N;
	scll(N);
	char M[N][N], temp;
	bool baris_evil[N];
	bool kolom_evil[N];
	ll cnt[2];
	cnt[0] = cnt[1] = 0;
	memset(baris_evil, false, sizeof baris_evil);
	memset(kolom_evil, false, sizeof kolom_evil);
	for (ll i = 0; i < N; ++i){
		scc(temp);
		for (ll j = 0; j < N; ++j){
			scc(M[i][j]);
		}
	}
	for (ll i = 0; i < N; ++i){
		bool benar = true;
		for (ll j = 0; j < N; ++j){
			benar = benar && M[i][j] == 'E';
		}
		baris_evil[i] = benar;
		cnt[0] += benar;
	}

	for (ll j = 0; j < N; ++j){
		bool benar = true;
		for (ll i = 0; i < N; ++i){
			benar = benar && M[i][j] == 'E';
		}
		kolom_evil[j] = benar;
		cnt[1] += benar;
	}
	if (cnt[0] && cnt[1]){
		cout << -1 << endl;
	} else {
		if (cnt[0]){
			for (ll j = 0; j < N; ++j){
				bool found = false;
				ll temp;
				for (ll i = 0; i < N && !found; ++i){
					if (M[i][j] == '.'){
						temp = i;
						found = true;
					}
				}
				cout << temp+1 << " " << j+1 << endl;
			}
		} else {
			for (ll i = 0; i < N; ++i){
				bool found = false;
				ll temp;
				for (ll j = 0; j < N && !found; ++j){
					if (M[i][j] == '.'){
						temp = j;
						found = true;
					}
				}
				cout << i+1 << " " << temp+1 << endl;
			}
		}
	}
	return 0;
}