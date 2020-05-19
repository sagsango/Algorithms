// https://artofproblemsolving.com/community/c90633h1291397_number_theory_in_competitive_programming_tutorial

#include <iostream>
typedef long long ll;
using namespace std;
int inv[111111], n;
ll mod=1e9+7;
int main(void)
{
    cin>>n;
    int i;
    inv[1]=1;
    for(i=2 ; i<=n ; i++)
    {
        inv[i]=((mod-mod/i)*inv[mod%i])%mod;
        cout<<inv[i]<<endl;
    }
}
