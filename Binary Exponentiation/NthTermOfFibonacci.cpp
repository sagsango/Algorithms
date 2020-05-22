#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define bug1( x ) {cerr << (#x) <<"="<< x << endl;}
#define bug2( x , y ) {cerr << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl;}
#define bug3( x , y , z ) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl;}
#define bug4( x , y , z , w) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl;}
#define bug5( x , y , z , w ,p) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl;}
#define bug6( x , y , z , w ,p , q) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl;}
#define bugn( x , n ) {cerr << (#x) <<":";for(int i=0;i<n;i++)cerr << x[i] <<"  "; cerr << endl;}
#define bugnm( x , n , m ) {cerr << (#x)<<endl;for(int i=0;i<n;i++){cerr << "Row #" << i<< ":";for(int j=0;j<m;j++)cerr << x[i][j] << "   ";cerr << endl;}}
typedef long long ll;
typedef long double ld;
using namespace std;



/*
fib:
 [ f[i] f[i-1] ] [ 1  1 ]  = f[i+1] f[i]
                   1  0
 [ 1  1 ] * [ 1 1 ] ^ n
            [ 1 0 ] 
*/

class matrixExponentiation{
	public : 
	vector<vector<int>> multiply(vector<vector<int>>a ,vector<vector<int>> b , int n)
	{
		int M=1e9+7;
		vector<vector<int>>c(n,vector<int>(n));
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			for(int ic=0,jr=0;ic<n && jr<n;ic++,jr++)
			{
				c[i][j]+=a[i][ic] * b[jr][j];
				c[i][j]%=M;                            /*      MOD Should be taken care of     */
			}
		}
		return c;
	}
	vector<vector<int>> solve(vector<vector<int>>mat,int p)
	{
		int n=mat.size();
		vector<vector<int>>a(n,vector<int>(n));
		for(int i=0;i<n;i++)a[i][i]=1;
		while( p )
		{
			if( p & 1 )
			{
				a=multiply( a , mat , n);
			}
			mat=multiply( mat , mat , n);
			p>>=1;
		}
		return a;
	}
};

int32_t main(){
	IOS
	vector<int>a={1,1}; // first two term 
	vector<vector<int>>b={ {1,1} , {2,0} }; // coefficient matix of fibb.
	int n;cin>>n;
	matrixExponentiation me;
	b=me.solve(b,n-1); // NOTE:dont pass negative value:
	cout << a[0]*b[0][0] + a[1]*b[1][0] << endl;
	
	
}
 
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
