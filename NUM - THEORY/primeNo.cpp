#include<bits/stdc++.h>
using namespace std;
// O (sqrt(N))
// not that good to use in contest queries
bool prime(int a){
	 if(a==1)
	    return false;
	for(int i = 2 ; i * i <= a ; i++)
	{
	    
		if(a % i == 0)
		return false;
		
	}
	return true;
    
   
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin>>n;
  
  if(prime(n)) 
   cout<<"prime";
   else 
   cout<<"comp";
  return 0;
}

