#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int base;
	string s; cin>>base>>s;
	int n=s.length();

	vector<int> a(n);
	rep(i,n) a[i]=s[i]-'a'+1;

	while(1){
		bool changed=false;
		for(int i=n-1;i>0;i--){
			if(a[i-1]+base<=26){
				if(i==n-1 || a[i]>=2){
					a[i]--;
					a[i-1]+=base;
					changed=true;
					if(a[i]==0){
						n--;
						a.pop_back();
					}
				}
			}
		}
		if(!changed) break;
	}

	rep(i,n) putchar('a'+a[i]-1);
	puts("");

	return 0;
}
