#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class point3{
public:
	double x,y,z;
	point3 operator-(const point3& p)const{ return {x-p.x,y-p.y,z-p.z}; }
};

point3 operator*(double c,const point3& p){ return {c*p.x,c*p.y,c*p.z}; }

double abs(const point3& p){ return sqrt(p.x*p.x+p.y*p.y+p.z*p.z); }

double dot(const point3& p,const point3& q){
	return p.x*q.x+p.y*q.y+p.z*q.z;
}

point3 cross(const point3& p,const point3& q){
	return {p.y*q.z-p.z*q.y,p.z*q.x-p.x*q.z,p.x*q.y-p.y*q.x};
}

int main(){
	point3 a,b,c,p;
	scanf("%lf%lf%lf",&a.x,&a.y,&a.z);
	scanf("%lf%lf%lf",&b.x,&b.y,&b.z);
	scanf("%lf%lf%lf",&c.x,&c.y,&c.z);
	scanf("%lf%lf%lf",&p.x,&p.y,&p.z);

	point3 n=cross(b-a,c-a);
	n=1/abs(n)*n;

	p=p-dot(p,n)*n;
	double s1=dot(cross(p-a,b-a),n);
	double s2=dot(cross(p-b,c-b),n);
	double s3=dot(cross(p-c,a-c),n);
	if((s1>0 && s2>0 && s3>0)
	|| (s1<0 && s2<0 && s3<0)) puts("YES");
	else puts("NO");

	return 0;
}
