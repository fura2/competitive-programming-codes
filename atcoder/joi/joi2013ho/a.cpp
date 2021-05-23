#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T>
vector<pair<T,int>> run_length_encoding(const vector<T>& a){
	vector<pair<T,int>> res;
	int n=a.size(),pre=0;
	rep(i,n) if(i==n-1 || a[i]!=a[i+1]) res.emplace_back(a[i],i-pre+1), pre=i+1;
	return res;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n){
		scanf("%d",&a[i]);
		if(i%2==0) a[i]=1-a[i];
	}

	auto rle=run_length_encoding(a);
	int ans=0;
	if(rle.size()==1){
		ans=rle[0].second;
	}
	if(rle.size()<=2){
		ans=rle[0].second+rle[1].second;
	}
	else{
		for(int i=1;i<rle.size()-1;i++) ans=max(ans,rle[i-1].second+rle[i].second+rle[i+1].second);
	}
	printf("%d\n",ans);

	return 0;
}
