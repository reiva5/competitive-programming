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

#define harga fi
#define kuota se

struct hidup{
	ll kuota;
	ll harga;
};

bool bego(const hidup a, const hidup b){
	return a.kuota*b.harga > a.harga*b.kuota;
}

int main(){
	ll T;
	scll(T);
	while (T--){
		ll N, M;
		scll(N); scll(M);
		vector<hidup> data(N);
		for (ll i = 0; i < 2; ++i){
			for (ll j = 0; j < N; ++j){
				if (i){
					scll(data[j].kuota);
				} else {
					scll(data[j].harga);
				}
			}
		}
		sort(data.begin(),data.end(),bego);
		ll kuota = 0;
		for (ll i = 0; i < N; ++i){
			ll get = M/data[i].harga;
			M %= data[i].harga;
			kuota += get*data[i].kuota;
		}
		cout << kuota << endl;
	}
	return 0;
}