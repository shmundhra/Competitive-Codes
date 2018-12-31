// https://www.codechef.com//KOL18ROL/problems/VALIDSTK

#include <bits/stdc++.h>
using namespace std; 

typedef unsigned long long ul ;
typedef long long ll ;
typedef string str ;

typedef pair < int , int >  pii ;
typedef pair < ll , ll>  pll ;
typedef pair < ll , pll > edge ; 
typedef vector < int > vi ;
typedef vector < ll > vll ;
typedef vector < pll > vp ;

#define MOD 1000000007 
#define vec vector    
#define nl '\n' 
#define is == 
#define all(v) (v).begin() , (v).end() 
#define sumof(v) accumulate ( all(v) , 0LL )
#define maxof(v) max_element( all(v) )
#define minof(v) min_element( all(v) )
#define rev(v) reverse(all(v)) 
#define sz(v)  (long long)(v).size() 
#define lp(i , n ) for ( ll i = 0 ; i < (n) ; i++ )
#define lp1(i , n ) for ( ll i = 1 ; i <= (n) ; i++ )
#define lpp(i , n ) for ( ll i = n-1 ; i >= 0 ; i-- ) 	 
#define umap unordered_map 

#define F first 
#define S second
#define pb push_back

#define tc(t) ul testcases ; cin>>testcases ; for ( int t = 1 ; t <= testcases ; t++ )
#define inarr(size) vll v ( size , 0 ) ; lp ( i , size ) cin>>v[i]  
#define invec( vec_name ) lp ( i , sz(vec_name) ) cin>>vec_name[i] 
#define debug( vec_name ) for ( auto val : vec_name ) cout<<val<<" " ; cout<<nl 
#define fast ios::sync_with_stdio(false); cin.tie(0);
ll power(ll x,ll y,ll mod){ ll res = 1; while(y){if(y&1) res= (res*x)%mod; y/=2, x=(x*x)%mod; }return res%mod;}
vll calc_fact (ll n , ll mod ){	vll fact(n+1,1) ; lp1 (i,n) fact[i] = (fact[i-1]*i) % mod ; return fact ; }
vll FF( str A ) { vll LPB(sz(A),0); ll len = 0 ; lp1 ( i , sz(A)-1) {if ( A[i] is A[len] ) LPB[i] = ++len ; else if ( len ) len = LPB[len-1] , i-- ; } return LPB ; }
bool KMP( str A, str B, vll LPB ){ ll j=0 ; lp (i,sz(A)) {if ( A[i] is B[j]) {if ( ++j is B.size() ) return true ;} else if (j) {j = LPB[j-1] ; i-- ; } } return false ;}


vll factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000	} ; //18!  

vector < string > ans = {"Invalid" , "Valid" } ; 

int main () 
{
	fast 
	tc(t)
	{
		ll n ; cin>>n ; inarr(n) ; 
		lp ( i , n ) if ( !v[i] ) v[i] = -1 ; 
		vll pref(n,0) ; pref[0] = v[0] ; 
		lp1(i,n-1)
		{
			pref[i] = pref[i-1] + v[i] ; 
		}
		ll flag = 1 ;
		lp ( i , n )
		{
			if ( pref[i] < 0 )
			{
				flag = 0 ; 
				break ; 
			}
		} 
		cout<<ans[flag]<<nl ; 
	}
		
	return 0 ; 
	
}
