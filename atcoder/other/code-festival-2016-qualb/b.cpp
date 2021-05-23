#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a,b;
	string s; cin>>n>>a>>b>>s;

	int cnt1=0,cnt2=0;
	for(char c:s){
		if(c=='a'){
			if(cnt1<a+b){
				puts("Yes");
				cnt1++;
			}
			else puts("No");
		}
		else if(c=='b'){
			if(cnt1<a+b && cnt2<b){
				puts("Yes");
				cnt1++;
			}
			else puts("No");
			cnt2++;
		}
		else puts("No");
	}

	return 0;
}
