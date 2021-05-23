#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	vector<pair<int,int>> seq;
	rep(i,n){
		int a; scanf("%d",&a);
		if(i%2==0){
			if(!seq.empty() && seq.back().first==a){
				seq.back().second++;
			}
			else{
				seq.emplace_back(a,1);
			}
		}
		else{
			if(!seq.empty() && seq.back().first==a){
				seq.back().second++;
			}
			else if(seq.empty()){
				seq.emplace_back(a,1);
			}
			else{
				int tmp=seq.back().second;
				seq.pop_back();
				if(seq.empty()){
					seq.emplace_back(a,tmp+1);
				}
				else{
					seq.back().second+=tmp+1;
				}
			}
		}
	}

	int ans=0;
	rep(i,seq.size()) if(seq[i].first==0) ans+=seq[i].second;
	printf("%d\n",ans);

	return 0;
}
