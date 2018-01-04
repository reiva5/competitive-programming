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

vector<string> M;
string tmp;
string list_nomor[] =
{
	"***   * *** *** * * *** *** *** *** ***",
	"* *   *   *   * * * *   *     * * * * *",
	"* *   * *** *** *** *** ***   * *** ***",
	"* *   * *     *   *   * * *   * * *   *",
	"***   * *** ***   * *** ***   * *** ***"
};
int HASH[10];
int getNumber(int NOW){
	ll cnt = 0;
	for (ll k = 0; k < 40; k += 4){
		bool benar = true;
		for (ll i = 0; i < 5; ++i){
			for (ll j = 0; j < 3; ++j){
				benar = benar && list_nomor[i][j+k] == M[i][j+NOW];
			}
		}
		if (benar){
			return cnt;
		}
		++cnt;
	}
	return -1;
}

int main(){
	int hit = 0;
	for (int i = 0; i < 10; ++i){
		HASH[i] = i + hit;
		hit += 4;
	}
	while (getline(cin,tmp)){
		M.pb(tmp);
	}
	int n = M.size();
	int m = M[0].size();
	vll sol;
	bool valid = true;
	for (int j = 0; j < m; j += 4){
		sol.pb(getNumber(j));
		valid = valid && sol.back() != -1;
	}
	if (!valid){
		printf("BOOM!!\n");
	} else {
		int res = 0;
		for (auto it : sol){
			res = res*10 + it;
			res %= 6;
		}
		printf("%s\n", res ? "BOOM!!" : "BEER!!");
	}
	return 0;
}

/*char*** ubah = 
{  
	{
		"***",
		"* *",
		"* *",
		"* *",
		"***"
	},
	{
		"  *",
		"  *",
		"  *",
		"  *",
		"  *"
	},
	{
		"***",
		"  *",
		"***",
		"*  ",
		"***"
	},
	{
		"***",
		"  *",
		"***",
		"  *",
		"***"
	},
	{
		"* *",
		"* *",
		"***",
		"  *",
		"  *"
	},
	{
		"***",
		"*  ",
		"***",
		"  *",
		"***"
	},
	{
		"***",
		"*  ",
		"***",
		"* *",
		"***"
	},
	{
		"***",
		"  *",
		"  *",
		"  *",
		"  *"
	},
	{
		"***",
		"* *",
		"***",
		"* *",
		"***"
	},
	{
		"***",
		"* *",
		"***",
		"  *",
		"***"
	},
}; */