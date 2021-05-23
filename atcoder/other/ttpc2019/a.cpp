#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,t; cin>>a>>b>>t;
	for(int i=a;;i+=b-a) if(i>=t) return cout<<i<<endl,0;
}
