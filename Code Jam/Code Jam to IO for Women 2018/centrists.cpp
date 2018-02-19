/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
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
#define nl printf("\n")
#define sp printf(" ")

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
#define ALL(x) (x).begin(), (x).end()
#define ALLSIZE(x,n) (x), (x)+(n)

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

string data[3];
string tmp[3];
vll go[26];
bool recStack[26];
bool visited[26];

bool isCyclicUtil(ll i){
	if (!visited[i]){
		visited[i] = 1;
		recStack[i] = 1;
		for (auto& it : go[i]){
			if (!visited[it] && isCyclicUtil(it)){
				return true;
			} else if (recStack[it]){
				return true;
			}
		}
	}
	recStack[i] = false;
	return false;
}

void CLEAR(){
	for (ll i = 0; i < 26; ++i){
		go[i].clear();
	}
}

bool isCyclic(){
	RESET(recStack);
	RESET(visited);
	for (ll i = 0; i < 26; ++i){
		if (isCyclicUtil(i)){
			return true;
		}
	}
	return false;
}

int main(){
	ll T;
	scll(T);
	ll tc = 1;
	while (T--){
		CLEAR();
		ll N;
		scll(N);
		bool lanjut = false;
		for (ll i = 0; i < 3; ++i){
			cin >> data[i];
		}
		cout << "Case #" << tc++ << ": ";
		// Cek data 1
		tmp[0] = data[1];
		tmp[1] = data[0];
		tmp[2] = data[2];
		for (ll i = 0; i < N; ++i){
			if (tmp[0][i] != tmp[1][i]){
				go[tmp[0][i]-'A'].pb(tmp[1][i]-'A');
				break;
			}
		}
		for (ll i = 0; i < N; ++i){
			if (tmp[1][i] != tmp[2][i]){
				go[tmp[1][i]-'A'].pb(tmp[2][i]-'A');
				break;
			}
		}
		if (isCyclic()){
			lanjut = true;
		} else {
			cout << "YES ";
		}
		if (lanjut){
			swap(tmp[0],tmp[2]);
			CLEAR();
			for (ll i = 0; i < N; ++i){
				if (tmp[0][i] != tmp[1][i]){
					go[tmp[0][i]-'A'].pb(tmp[1][i]-'A');
					break;
				}
			}
			for (ll i = 0; i < N; ++i){
				if (tmp[1][i] != tmp[2][i]){
					go[tmp[1][i]-'A'].pb(tmp[2][i]-'A');
					break;
				}
			}
			cout << (isCyclic() ? "NO " : "YES ");
		}

		// Cek data 2
		lanjut = false;
		CLEAR();
		tmp[0] = data[0];
		tmp[1] = data[1];
		tmp[2] = data[2];
		for (ll i = 0; i < N; ++i){
			if (tmp[0][i] != tmp[1][i]){
				go[tmp[0][i]-'A'].pb(tmp[1][i]-'A');
				break;
			}
		}
		for (ll i = 0; i < N; ++i){
			if (tmp[1][i] != tmp[2][i]){
				go[tmp[1][i]-'A'].pb(tmp[2][i]-'A');
				break;
			}
		}
		if (isCyclic()){
			lanjut = true;
		} else {
			cout << "YES ";
		}
		if (lanjut){
			swap(tmp[0],tmp[2]);
			CLEAR();
			for (ll i = 0; i < N; ++i){
				if (tmp[0][i] != tmp[1][i]){
					go[tmp[0][i]-'A'].pb(tmp[1][i]-'A');
					break;
				}
			}
			for (ll i = 0; i < N; ++i){
				if (tmp[1][i] != tmp[2][i]){
					go[tmp[1][i]-'A'].pb(tmp[2][i]-'A');
					break;
				}
			}
			cout << (isCyclic() ? "NO " : "YES ");
		}

		// Cek data 3
		lanjut = false;
		CLEAR();
		tmp[0] = data[0];
		tmp[1] = data[2];
		tmp[2] = data[1];
		for (ll i = 0; i < N; ++i){
			if (tmp[0][i] != tmp[1][i]){
				go[tmp[0][i]-'A'].pb(tmp[1][i]-'A');
				break;
			}
		}
		for (ll i = 0; i < N; ++i){
			if (tmp[1][i] != tmp[2][i]){
				go[tmp[1][i]-'A'].pb(tmp[2][i]-'A');
				break;
			}
		}
		if (isCyclic()){
			lanjut = true;
		} else {
			cout << "YES\n";
		}
		if (lanjut){
			swap(tmp[0],tmp[2]);
			CLEAR();
			for (ll i = 0; i < N; ++i){
				if (tmp[0][i] != tmp[1][i]){
					go[tmp[0][i]-'A'].pb(tmp[1][i]-'A');
					break;
				}
			}
			for (ll i = 0; i < N; ++i){
				if (tmp[1][i] != tmp[2][i]){
					go[tmp[1][i]-'A'].pb(tmp[2][i]-'A');
					break;
				}
			}
			cout << (isCyclic() ? "NO\n" : "YES\n");
		}
	}
	return 0;
}