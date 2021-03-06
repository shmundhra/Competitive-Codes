#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std; 

typedef unsigned long long ul ;
typedef long long ll ;

typedef pair < int , int >  pii ;
typedef pair < ll , ll>  pll ;
typedef pair < ll , pll > edge ; 
typedef vector < int > vi ;
typedef vector < ll > vll ;
typedef vector < pll > vp ;

#define MOD 1000000007 
#define vec vector    
#define all(v) (v).begin() , (v).end() 
#define sz(v)  (long long)(v).size() 
#define lp(i , n ) for ( ll i = 0 ; i < n ; i++ )
#define lpp(i , n ) for ( ll i = n-1 ; i >= 0 ; i-- )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define repp(i , a , b , n) for(ll i = b-1 ; i >= a ; i -= n ) 	 

#define f first 
#define s second
#define pb push_back
#define mp make_pair

#define tc(t) ul t ; cin>>t ; while ( t-- )
#define inarr(n) vll v ( n , 0 ) ; lp ( i , n) cin>>v[i]  

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)

ll mini ( ll a, ll b ) { return ( (a) > (b) ? (b) : (a) ) ; }
ll maxi ( ll a, ll b ) { return ( (a) < (b) ? (b) : (a) ) ; }

// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000	} ; 

vector < int > FF ( string A )
{
	vector < int > LVB ( A.size() , 0 ) ;

	int i = 0 ; int j = 1 ; 
	
	while ( j < A.size() )
	{
		if ( A[i] == A[j] )
		{
			LVB[j] = i + 1 ; 
			i++ ; 
			j++ ; 
		}
		else
		{	
			if ( i == 0 )
			{
				LVB[j] = 0 ; 
				j++ ; 				
			}
			else
			{
				i = LVB[i-1] ; 
			}
		}
	}
	return LVB ; 	 
}

int main () 
{
	fast 
	ll t ; 
	cin>>t ; 
	rep ( testcase , 1 , t+1 , 1 )
	{
		string s ; 
		cin>>s ; 

		cout<<"Case #"<<testcase<<": " ; 

		vector < int > LVB = FF ( s ) ; 

		for ( int i = 1 ; i < LVB.size()-1 ; i++ )
		{
			if ( LVB[i] + 1 == LVB[i+1] ) 
				LVB[i] = 0 ; 			
		}
		
        int index = 0 ; 
		int lvb = 0 ; 
		for ( int i = 0 ; i < LVB.size()-1 ; i++ )
		{
			if ( LVB[i] > 0 ) 
			{    
                index = i ; 
				lvb = LVB[i]; 
				break ; 
			}
		}
		if ( lvb == 0 ) cout<<"Impossible\n" ; 

		else
		{
			string ans ( s.begin() , s.begin() + index+1 ) ;  
			ans = ans + string ( s.begin() + lvb , s.end() ) ; 
			cout<<ans<<endl ; 
		}


	}
	

	return 0 ; 
}
