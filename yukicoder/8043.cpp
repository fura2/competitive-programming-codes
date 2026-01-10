#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	vector<string> in;
	while(1){
		string s; getline(cin,s);
		if(s.empty()) break;
		in.emplace_back(s);
	}

	if(in.size()==1){ // 9000, 480, 9002
		if(isdigit(in[0][0])){
			int n=stoi(in[0]);
			if(n==1 || n==16 || n==51 || n==100){ // 9002
				for(int i=1;i<=n;i++){
					if(i%15==0) cout<<"FizzBuzz\n";
					else if(i%3==0) cout<<"Fizz\n";
					else if(i%5==0) cout<<"Buzz\n";
					else cout<<i<<'\n';
				}
			}
			else{ // 480
				cout<<n*(n+1)/2<<'\n';
			}
		}
		else{ // 9000
			cout<<"Hello World!\n";
		}
	}
	else{ // 9001, 9008, 9009
		if(isalpha(in[1][0])){ // 9001
			stringstream ss(in[0]);
			int a,b; ss>>a>>b;
			cout<<a+b<<' '<<in[1]<<'\n';
		}
		else{ // 9008, 9009
			stringstream ss;
			for(auto s:in) ss<<s<<' ';
			int n; ss>>n;
			lint ans=0;
			rep(i,n){
				lint a; ss>>a;
				ans+=a;
			}
			cout<<ans<<'\n';
		}
	}

	return 0;
}
