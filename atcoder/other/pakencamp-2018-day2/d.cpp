#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class G>
class Fenwick_tree_dual{
	vector<G> a;
public:
	Fenwick_tree_dual(int n):a(n){}
	void add(int l,int r,const G& val){
		if(l==0){
			for(;r>0;r-=r&-r) a[r-1]+=val;
			return;
		}
		add(0,r,val);
		add(0,l,-val);
	}
	G get(int i)const{
		G res{};
		for(i++;i<=a.size();i+=i&-i) res+=a[i-1];
		return res;
	}
};

class F2{
	bool x;
public:
	F2():x(false){}
	F2(long long n){ assert(n==0||n==1); x=(n==1); }
	F2& operator+=(const F2& a){ x=(x!=a.x); return *this; }
	F2& operator-=(const F2& a){ return (*this)+=a; }
	F2& operator*=(const F2& a){ x=(x&&a.x); return *this; }
	F2& operator/=(const F2& a){ assert(a.x); return *this; }
	F2 operator+(const F2& a)const{ return F2(*this)+=a; }
	F2 operator-(const F2& a)const{ return F2(*this)-=a; }
	F2 operator*(const F2& a)const{ return F2(*this)*=a; }
	F2 operator/(const F2& a)const{ return F2(*this)/=a; }
	F2 operator-()const{ return x; }
	bool operator==(const F2& a)const{ return x==a.x; }
	bool operator!=(const F2& a)const{ return !((*this)==a); }
	int to_int()const{ return x; }
};

vector<pair<char,int>> run_length_encoding(const string& s){
	vector<pair<char,int>> res;
	int n=s.length(),pre=0;
	rep(i,n) if(i==n-1 || s[i]!=s[i+1]) res.emplace_back(s[i],i-pre+1), pre=i+1;
	return res;
}

int main(){
	int n,m;
	string s; cin>>n>>s>>m;
	vector<char> d(m),f(m);
	rep(i,m) cin>>d[i]>>f[i];

	int q; cin>>q;
	vector<int> t(q),p(q);
	rep(j,q) cin>>t[j]>>p[j], t[j]--, p[j]--;

	deque<pair<char,int>> rle;
	for(auto p:run_length_encoding(s)) rle.emplace_back(p);

	int l=0,r;
	rep(i,m) if(d[i]=='L') l++;
	r=l+n;

	Fenwick_tree_dual<F2> F(n+m);
	rep(i,n) if(s[i]=='B') F.add(l+i,l+i+1,1);

	vector<char> ans(q);
	vector Ev(m,vector<int>());
	rep(j,q) Ev[t[j]].emplace_back(j);
	rep(i,m){
		if(d[i]=='L'){
			int len;
			if(rle[0].first==f[i]){
				rle[0].second++;
				len=0;
			}
			else if(rle.size()==1){
				rle.emplace_front(f[i],1);
				len=0;
			}
			else{
				int tmp=rle[0].second;
				rle.pop_front();
				rle[0].second+=tmp+1;
				len=tmp;
			}

			F.add(l,l+len,1);
			l--;
			if(f[i]=='B') F.add(l,l+1,1);

			for(int id:Ev[i]) ans[id]=(F.get(l+p[id])==1?'B':'W');
		}
		else{
			int len;
			if(rle.back().first==f[i]){
				rle.back().second++;
				len=0;
			}
			else if(rle.size()==1){
				rle.emplace_back(f[i],1);
				len=0;
			}
			else{
				int tmp=rle.back().second;
				rle.pop_back();
				rle.back().second+=tmp+1;
				len=tmp;
			}

			F.add(r-len,r,1);
			r++;
			if(f[i]=='B') F.add(r-1,r,1);

			for(int id:Ev[i]) ans[id]=(F.get(l+p[id])==1?'B':'W');
		}
	}

	rep(j,q) printf("%c\n",ans[j]);

	return 0;
}
