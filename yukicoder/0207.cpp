#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i++){
		string s=to_string(i);
		if(i%3==0 || count(s.begin(),s.end(),'3')>0) printf("%d\n",i);
	}
	return 0;
}
