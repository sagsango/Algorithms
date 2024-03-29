// https://codingcompetitions.withgoogle.com/kickstart/submissions/0000000000050edb/Q2hhbmRuYW5p
// you can use segmented seive also


#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}
typedef unsigned long long ull;
const int bits = 10;
// if all numbers are less than 2^k, set bits = 64-k
const ull po = 1 << bits;
ull mod_mul(ull a, ull b, ull &c) {
		ull x = a * (b & (po - 1)) % c;
			while ((b >>= bits) > 0) {
						a = (a << bits) % c;
								x += (a * (b & (po - 1))) % c;
									}
				return x % c;
}
ull mod_pow(ull a, ull b, ull mod) {
		if (b == 0) return 1;
			ull res = mod_pow(a, b / 2, mod);
				res = mod_mul(res, res, mod);
					if (b & 1) return mod_mul(res, a, mod);
						return res;
}
bool prime(ull p) {
		if (p == 2||p==1) return true;                              // 1 is treated as prime : take of it [ other fine]
			if (p == 1 || p % 2 == 0) return false;
				ull s = p - 1;
					while (s % 2 == 0) s /= 2;
						rep(i,15) {
									ull a = rand() % (p - 1) + 1, tmp = s;
											ull mod = mod_pow(a, tmp, p);
													while (tmp != p - 1 && mod != 1 && mod != p - 1) {
																	mod = mod_mul(mod, mod, p);
																				tmp *= 2;
																						}
															if (mod != p - 1 && tmp % 2 == 0) return false;
																}
							return true;
}
void solve(){
	int l,r;cin>>l>>r;
	int ans = 0;
	repA(i,l,r){
		if(prime(i)||i==8||(i%8!=0&&i%4==0&&prime(i/4))||(i%4!=0&&i%2==0)){
			ans++;
		}
	}
	cout<<ans;

}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) cout<<"Case #"<<i+1<<": ",solve(),cout<<'\n';	
	
	return 0;
}
