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

ll K, X, N, M;
void print_1(ll a, ll b){
	ll i, j;
	for (i = 0; i < a; i += 2){
		cout << "AC";
	}
	for (; i < N; ++i){
		cout << 'J';
	}
	nl;
	for (j = 0; j < b; j += 2){
		cout << "AC";
	}
	for (; j < M; ++j){
		cout << 'J';
	}
	nl;
}

void print_2(ll a, ll b){
	ll i, j;
	char now = 'A';
	for (i = a+1; i < N; ++i){
		cout << 'J';
	}
	for (i = 0; i <= a; ++i){
		cout << now;
		now = now == 'A' ? 'C' : 'A';
	}
	nl;
	for (j = 0; j <= b; ++j){
		cout << now;
		now = now == 'A' ? 'C' : 'A';
	}
	for (j = b+1; j < M; ++j){
		cout << 'J';
	}
	nl;
}
const ll MAX_VAL = 1e9;

int main(){
	ll A, B, C;
	cin >> K >> X >> N >> M;
	if (K == -1){
		if (N+M == X*2){
			char now = 'A';
			for (int i = 0; i < N; ++i){
				cout << now;
				now = now == 'A' ? 'C' : 'A';
			}
			nl;
			for (int i = 0; i < M; ++i){
				cout << now;
				now = now == 'A' ? 'C' : 'A';
			}
			nl;
		} else if (X != 0){
			cout << "Happy new year!" << endl;
		} else {
			for (int i = 0; i < N; ++i){
				cout << 'J';
			}
			nl;
			for (int i = 0; i < M; ++i){
				cout << 'J';
			}
			nl;
		}
	} else {
		for (int i = 0; i < 1000; ++i){
			for (int j = 0; j < 1000; ++j){
				bool salah = false;
				A = i;
				B = j;
				for (int k = 3; k <= K && !salah; ++k){
					C = A+B;
					A = B;
					B = C;
					if (C > X){
						salah = true;
					}
				}
				if (!salah && C == X && 2*i <= N && 2*j <= M){
					print_1(2*i,2*j);
					return 0;
				} else {
					A = i;
					B = j;
					C = A+B+1;
					A = B;
					B = C;
					if (!(i+j)){
						cerr << C << " ";
					}
					for (int k = 4; k <= K && !salah; ++k){
						C = A+B;
						A = B;
						B = C;
					if (!(i+j)){
						cerr << C << " ";
					}
						if (C > X){
							salah = true;
						}
					}
					if (!salah){
						if (C == X){
							if (2*i < N && 2*j < M){
								print_2(2*i,2*j);
								return 0;
							}
						}
					}
				}
			}
		}
		cout << "Happy new year!" << endl;
	}
	return 0;
}