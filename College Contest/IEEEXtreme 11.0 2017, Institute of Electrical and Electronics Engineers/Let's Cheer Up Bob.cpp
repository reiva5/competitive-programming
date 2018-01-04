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
#define mp make_pair
#define eb emplace_back
#define RESET(x) memset((x), 0, sizeof(x))
#define SET(x,y) memset((x), (y), sizeof(x))

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

#define i fi
#define j se

pll data[9];

char tic[3][3];
bool ver[3];
bool hor[3];
bool diagonal[3];
bool ketemu;
int i;
int j;

bool menangBob(){
	RESET(ver);
	for (i = 0; i < 3; ++i){
		ver[i] = tic[i][0] == tic[i][1] && tic[i][1] == tic[i][2] && tic[i][2] == 'X';
	}
	for (i = 0; i < 3; ++i){
		hor[i] = tic[0][i] == tic[1][i] && tic[1][i] == tic[2][i] && tic[2][i] == 'X';
	}
	diagonal[0] = tic[0][0] == tic[1][1] && tic[1][1] == tic[2][2] && tic[2][2] == 'X';
	diagonal[1] = tic[2][0] == tic[1][1] && tic[1][1] == tic[0][2] && tic[0][2] == 'X';
	diagonal[2] = false;

	ketemu = false;
	for (i = 0; i < 3; ++i){
		ketemu = ketemu || ver[i];
		ketemu = ketemu || hor[i];
		ketemu = ketemu || diagonal[i];
	}
	return ketemu;
}

bool menangAku(){
	RESET(ver);
	for (i = 0; i < 3; ++i){
		ver[i] = tic[i][0] == tic[i][1] && tic[i][1] == tic[i][2] && tic[i][2] == 'O';
	}
	for (i = 0; i < 3; ++i){
		hor[i] = tic[0][i] == tic[1][i] && tic[1][i] == tic[2][i] && tic[2][i] == 'O';
	}
	diagonal[0] = tic[0][0] == tic[1][1] && tic[1][1] == tic[2][2] && tic[2][2] == 'O';
	diagonal[1] = tic[2][0] == tic[1][1] && tic[1][1] == tic[0][2] && tic[0][2] == 'O';
	diagonal[2] = false;

	ketemu = false;
	for (i = 0; i < 3; ++i){
		ketemu = ketemu || ver[i];
		ketemu = ketemu || hor[i];
		ketemu = ketemu || diagonal[i];
	}
	return ketemu;
}

int bob_move[9];
int my_move[9];
bool visited[9];

void prnt(){
	for (i = 0; i < 3; ++i){
		for (j = 0; j < 3; ++j){
			cerr << tic[i][j] << " ";
		}
		cerr << endl;
	}
}


pll eval(ll A){
	return {A/3, A%3};
}

vll menang;
vll tmp;
int main(){
	ll MIN = 10;
	ll T;
	T = 9;
	for (ll x = 0; x < 9; ++x){
		scll(data[x].fi), scll(data[x].se);
		bob_move[x] = (3*(data[x].fi-1)+data[x].se-1);
		my_move[x] = x;
	}
	ll I;
	ll J;
	bool found = false;
	do {
		found = false;
		tmp.clear();
		SET(tic, '_');
		RESET(visited);
		ll cnt = 0;
		J = 0;
		for (I = 0; I < 9 && !found; ++I){
			while (I < 9 && visited[bob_move[I]]){
				++I;
			}
			if (I < 9 && !visited[bob_move[I]]){
				pll P = eval(bob_move[I]);
				tic[P.i][P.j] = 'X';
				visited[bob_move[I]] = true;
			}
			if (!found){
				found = visited[my_move[J]];
				if (!found){
					if (J < 9 && !visited[my_move[J]]){
						pll P = eval(my_move[J]);
						tic[P.i][P.j] = 'O';
						found = menangAku();
						visited[my_move[J]] = true;
						++cnt;
						tmp.pb(my_move[J]);
						++J;
					}
				}
			} else {
				if (menangBob() && MIN > cnt){
					MIN = cnt;
					menang = tmp;
				}
			}
		}
		if (menangBob() && MIN > cnt){
			MIN = cnt;
			menang = tmp;
		}
	} while (next_permutation(my_move,my_move+9));
	
	cerr << menang.size() << endl;
	for (i = 0; i < menang.size(); ++i){
		pll tmp = eval(menang[i]);
		cout << tmp.fi+1 << " " << tmp.se+1 << endl;
	}
	return 0;
}