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
#define pf push_front
#define ppb pop_back
#define ppf pop_front
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

string a;
string b;
deque<char> A, B;
int i, LE, RI;

int main(){
	cin >> a >> b;
	char solution[a.size()];
	LE = 0, RI = a.size()-1;

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	for (i = 0; i < a.size()/2; ++i){
		A.pb(a[i]);
		B.pb(b[i]);
	}
	if ((int) a.size() & 1){
		A.pb(a[i]);
	}
	for (auto it : A){
		cerr << it;
	}
	cerr << endl;
	for (auto it : B){
		cerr << it;
	}
	cerr << endl;
	int LAST = a.size();
	bool found = false;
	for (i = 1; i <= LAST && !found;){
		if (i & 1){
			if (A.front() < B.front()){
				solution[LE++] = A.front();
				A.ppf();
				++i;
			} else {
				found = true;
			}
		} else {
			if (B.front() >= A.front()){
				solution[LE++] = B.front();
				B.ppf();
				++i;
			} else {
				found = true;
			}
		}
	}

	if (found){
		for (; i <= LAST; ++i){
			if (i & 1){
				if (A.back() <= B.front()){
					solution[RI--] = A.back();
					A.ppb();
				} else {
					solution[RI--] = A.front();
					A.ppf();
				}
			} else {
				if (B.back() <= A.front()){
					solution[RI--] = B.back();
					B.ppb();
				} else {
					solution[RI--] = B.front();
					B.ppf();
				}
			}
		}
	}
	for (i = 0; i < LAST; ++i){
		printf("%c", solution[i]);
	}
	printf("\n");
	return 0;
}