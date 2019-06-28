#include<bits/stdc++.h>
using namespace std;

struct box{
	int l,w,h;
};

bool cmp(box a,box b){
	return a.l*a.w > b.l*b.w;
}

int getMaxHeight(int n,box dim[]){
	box rot[3*n];

	int idx=0;

	for(int i=0;i<n;i++){
		rot[idx].h=dim[i].h;
		rot[idx].l=max(dim[i].l,dim[i].w);
		rot[idx].w=min(dim[i].l,dim[i].w);
		idx++;

		rot[idx].h=dim[i].w;
		rot[idx].l=max(dim[i].l,dim[i].h);
		rot[idx].w=min(dim[i].l,dim[i].h);
		idx++;

		rot[idx].h=dim[i].l;
		rot[idx].l=max(dim[i].h,dim[i].w);
		rot[idx].w=min(dim[i].h,dim[i].w);
		idx++;
	}

	n=3*n;

	sort(rot,rot+n,cmp);

	int height[n];

	for(int i=0;i<n;i++)
		height[i]=rots[i].h;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(rot[i].w < rot[j].w && rot[i].l < rot[j].l && height[i]<height[j]+rot[i].h)
				height[i]=height[j]+rot[i].h;
		}
	}

	int maxi=-1;

	for(int i=0;i<n;i++){
		if(maxi<height[i])
			maxi=height[i];
	}

	return maxi;

	
}

int main(){
	int n,l,w,h;
	cin >> n;

	box dim[n];

	for(int i=0;i<n;i++){
		cin >> h >> l >> w;
		dim[i].l=l;
		dim[i].w=w;
		dim[i].h=h;
	}

	cout << getMaxHeight(n,dim);
		
}