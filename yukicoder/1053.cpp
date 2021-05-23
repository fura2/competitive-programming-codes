#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool check(vector<int> a){
	set<int> S;
	rep(i,a.size()){
		if(S.count(a[i])>0) return false;
		S.emplace(a[i]);
	}
	return true;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	a.erase(unique(a.begin(),a.end()),a.end());

	if(check(a)){
		puts("0");
	}
	else if(a.front()==a.back()){
		a.pop_back();
		puts(check(a)?"1":"-1");
	}
	else{
		puts("-1");
	}

	return 0;
}
