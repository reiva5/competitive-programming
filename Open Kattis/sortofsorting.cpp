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
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define eb emplace_back
#define SQR(x) (x)*(x)
#define CUBE(x) SQR(x)*(x)
#define RESET(x) memset((x), 0, ukuranof(x))
#define SET(x,y) memset((x), (y), ukuranof(x))

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

string data[200];
bool cmp(string a, string b){
	return a[0] < b[0] || (a[0] == b[0] && a[1] <= b[1]);
}

void bubblesort(int ukuran){
	for (int i = 0; i < ukuran - 1; ++i){
		for (int j = 0; j < ukuran - 1; ++j){
			if (!cmp(data[j],data[j+1])){
				swap(data[j],data[j+1]);
			}
		}
	}
}

int main(){
	ll T;
	scll(T);
	while (T){
		for (int i = 0; i < T; ++i){
			cin >> data[i];
		}
		bubblesort(T);
		for (int i = 0; i < T; ++i){
			cout << data[i] << endl;
		}
		nl;
		scll(T);
	}
	return 0;
}