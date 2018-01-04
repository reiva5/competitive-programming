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

ll last_idx_column[1000000];
ll last_idx_row[1000000];
ll last_val_column[1000000];
ll last_val_row[1000000];
pair<ll,pll> data[1000000];
ll matriks[1000000];
ll N, M;

#define data(i,j)		data[(i)*M+(j)]
#define matriks(i,j)	matriks[(i)*M+(j)]
#define I 				se.fi
#define J 				se.se

bool cmp(pair<ll,pll> a, pair<ll,pll> b){
	return a.fi < b.fi;
}

ll MAX = 0;
int main(){
	RESET(last_idx_row);
	RESET(last_idx_column);
	RESET(last_val_row);
	RESET(last_val_column);
	scll(N);
	scll(M);
	for (ll i = 0; i < N; ++i){
		for (ll j = 0; j < M; ++j){
			scll(data(i,j).fi);
			data(i,j).se.fi = i;
			data(i,j).se.se = j;
		}
	}
	sort(data,data+N*M,cmp);
	ll banyak = N*M;
	ll tmp = 0;
	for (ll i = 0; i < banyak; ++i){
		if (data[i].fi > last_val_column[data[i].I] && last_idx_column[data[i].I] >= last_idx_row[data[i].J]){
			++last_idx_column[data[i].I];
			last_idx_row[data[i].J] = last_idx_column[data[i].I];
		} else if (data[i].fi > last_val_row[data[i].J] && last_idx_row[data[i].J] >= last_idx_column[data[i].I]){
			++last_idx_row[data[i].J];
			last_idx_column[data[i].I] = last_idx_row[data[i].J];
		} else if (data[i].fi == last_val_column[data[i].I] && last_val_column[data[i].I] >= last_idx_row[data[i].J]){
			last_idx_row[data[i].J] = last_idx_column[data[i].I];
		} else {
			last_idx_column[data[i].I] = last_idx_row[data[i].J];
		}
		last_val_column[data[i].I] = data[i].fi;
		last_val_row[data[i].J] = data[i].fi;
		matriks(data[i].I,data[i].J) = last_idx_column[data[i].I];
		MAX = max(MAX,max(last_idx_column[data[i].I],last_idx_row[data[i].J]));
	}
	cout << MAX << endl;
	return 0;
}