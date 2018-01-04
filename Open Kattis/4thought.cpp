// Bismillaahirrahmaanirrahiim
/* Author	: Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define jehian using
#define mau namespace
#define libur std
#define cepet {ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);}

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
#define special pair<ll,pll>

bool cek;
char simbol[] = {'+', '*', '-', '/'};

bool isNumber(char &c){
	return c >= '0' && c <= '9';
}

bool isSimbol(char &c){
	cek = false; 
	for (int i = 0; i < 4; ++i) cek = cek || simbol[i] == c;
	return cek;
}

bool isKaliBagi(char &c){
	cek = false;
	for (int i = 1; i < 4; i += 2) cek = cek || simbol[i] == c;
	return cek;
}

ll getVal(ll A, char c, ll B){
	if (c == '+'){
		return A+B;
	} else if (c == '-'){
		return A-B;
	} else if (c == '*'){
		return A*B;
	} else {
		return A/B;
	}
}

ll eval(string &A){
	deque<pair<ll,char>> data[2];
	ll tmp = 0;
	for (ll i = 0; i < A.size(); ++i){
		if (isNumber(A[i])){
			tmp = tmp*10 + A[i]-48;
		} else {
			data[0].pb(mp(tmp,'#'));
			data[0].pb(mp(-1,A[i]));
			tmp = 0;
		}
	}
	data[0].pb(mp(tmp,'#'));
	ll val[2];
	char opr;
	while (!data[0].empty()){
		val[0] = data[0].front().fi;
		data[0].pop_front();
		if (!data[0].empty()){
			opr = data[0].front().se;
			data[0].pop_front();
			val[1] = data[0].front().fi;
			data[0].pop_front();
			if (isKaliBagi(opr)){
				data[0].push_front(mp(getVal(val[0],opr,val[1]), '#'));
			} else {
				data[1].pb(mp(val[0],'#'));
				data[1].pb(mp(-1,opr));
				data[0].push_front(mp(val[1],'#'));
			}
		} else {
			data[1].pb(mp(val[0],'#'));
		}
	}

	while (data[1].size() > 1){
		val[0] = data[1].front().fi;
		data[1].pop_front();
		if (data[1].size()){
			opr = data[1].front().se;
			data[1].pop_front();
			val[1] = data[1].front().fi;
			data[1].pop_front();
			data[1].push_front(mp(getVal(val[0],opr,val[1]), '#'));
		}
	}

	return data[1][0].fi;
}

string hehe;
int main(){
	hehe = "4_4_4_4";
	char tanda[4] = {'+','-','*','/'};
	ll N;
	scll(N);
	while (N--){
		bool found = false;
		ll tmp;
		scll(tmp);
		for (int i = 0; i < 4 && !found; ++i){
			for (int j = 0; j < 4 && !found; ++j){
				for (int k = 0; k < 4 && !found; ++k){
					hehe[1] = tanda[i];
					hehe[3] = tanda[j];
					hehe[5] = tanda[k];
					found = (tmp == eval(hehe));
					if (found){
						for (auto it : hehe){
							printf("%c ", it);
						}
						printf("= %lld\n", tmp);
					}
				}
			}
		}
		if (!found){
			printf("no solution\n");
		}
	}
	return 0;
}