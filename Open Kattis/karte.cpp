/* Author   : Jehian Norman Saviero (@Reiva5) */
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
#define mp make_pair
#define eb emplace_back

/* MACROS FOR ATTRIBUTE */
#define fi first
#define se second

int cnt[256];
bool visited[256][14];
int main(){
	memset(visited, false, sizeof visited);
	for (int i = 0; i < 256; ++i) cnt[i] = 13;
	string S;
	cin >> S;
	bool found = false;
	for (ll i = 0; i < S.size() && !found; i += 3){
		char tipe = S[i];
		int val = 10*(S[i+1]-48) + S[i+2]-48;
		if (!visited[tipe][val]){
			visited[tipe][val] = true;
		} else {
			found = true;
		}
		--cnt[tipe];
	}
	if (!found){
		cout << cnt['P'] << " " << cnt['K'] << " " << cnt['H'] << " " << cnt['T'] << endl;
	} else {
		cout << "GRESKA" << endl;
	}
	return 0;
}