#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	cout<<setprecision(20);

	long double a,b,c; cin>>a>>b>>c;

	if(a==0){
		if(b==0){
			if(c==0) cout<<-1<<'\n';
			else     cout<< 0<<'\n';
		}
		else{
			cout<<1<<'\n';
			cout<<-c/b<<'\n';
		}
	}
	else{
		auto d=b*b-4*a*c;
		if(d<0){
			cout<<0<<'\n';
		}
		else if(d==0){
			cout<<1<<'\n';
			cout<<-b/(2*a)<<'\n';
		}
		else{
			cout<<2<<'\n';
			long double x1,x2;
			if(b>=0){
				x1=(-b-sqrt(d))/(2*a);
				x2=(2*c)/(-b-sqrt(d));
			}
			else{
				x1=(2*c)/(-b+sqrt(d));
				x2=(-b+sqrt(d))/(2*a);
			}
			cout<<min(x1,x2)<<'\n';
			cout<<max(x1,x2)<<'\n';
		}
	}

	return 0;
}
