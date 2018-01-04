#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define Jehian using
#define Adya namespace
#define Harum std
#define cepet {ios_base::sync_with_stdio(0);cin.tie(0);}

Jehian Adya Harum;
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

bool bits[33];
bool number[100000][33];

bool AND[33];
bool XOR[33];
bool OR[33];

ll RES;
ll toNumber(int idx){
	RES = 0;
	for (ll i = 32; i >= 0; --i){
		RES = RES*2 + number[idx][i];
	}
	return RES;
}

void prnt_idx(bool hehe[]){
	for (ll i = 0; i < 33; ++i){
		cerr << hehe[i];
	}
	cerr << endl;
}

int main(){
	ll T;
	int cnt;
	scll(T);
	while (T--){
		cnt = 0;
		RESET(AND);
		RESET(XOR);
		RESET(OR);
		RESET(bits);
		RESET(number);
		ll N, A, B, C;
		scll(N);
		scll(A);
		scll(B);
		scll(C);
		while (A || B || C){
			AND[cnt] = A%2;
			OR[cnt] = B%2;
			XOR[cnt++] = C%2;
			A /= 2;
			B /= 2;
			C /= 2;
		}
		bool benar = true;
		for (ll i = 0; i < 32 && benar; ++i){
			if ((AND[i] && OR[i]) && (N%2 == XOR[i])){
				for (ll j = 0; j < N; ++j){
					number[j][i] = AND[i];
				}
			} else if (!(AND[i] || OR[i] || XOR[i])){
				for (ll j = 0; j < N; ++j){
					number[j][i] = AND[i];
				}
			} else if (!AND[i] && OR[i]){
				if (N == 1){
					benar = false;
				} else {
					number[0][i] = 0;
					number[1][i] = 1;
					if (!XOR[i] && N == 2){
						benar = false;
					} else {
						number[2][i] = !XOR[i];
						for (ll j = 3; j < N; ++j){
							number[j][i] = 0;
						}
					}
				}
			} else {
				benar = false;
			}
		}
		if (benar){
			// prnt_idx(AND);
			// prnt_idx(OR);
			// prnt_idx(XOR);
			ll tmp;
			ll a = (1<<32) - 1;
			tmp = a;
			ll b = 0;
			ll c = 0;
			for (int i = 0; i < N-1; ++i){
				tmp = toNumber(i);
				printf("%lld ", tmp);
				a &= tmp;
				b |= tmp;
				c ^= tmp;
			}
			tmp = toNumber(N-1);
			printf("%lld\n", tmp);
			a &= tmp;
			b |= tmp;
			c ^= tmp;
		} else {
			printf("-1\n");
		}
	}
}