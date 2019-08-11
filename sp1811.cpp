#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,l,m,sa[N],x[N],y[N],height[N],c[N],rk[N],ans;
char s[N];

void GetSA(){
    for (int i=1;i<=n;++i) c[x[i]=s[i]]++;
    for (int i=2;i<=m;++i) c[i]+=c[i-1];
    for (int i=n;i;--i) sa[c[x[i]]--]=i;
    for (int k=1;k<=n;k<<=1){
        int num=0;
        for (int i=n-k+1;i<=n;++i) y[++num]=i;
        for (int i=1;i<=n;++i) if (sa[i]>k) y[++num]=sa[i]-k;
        for (int i=1;i<=m;++i) c[i]=0;
        for (int i=1;i<=n;++i) c[x[i]]++;
        for (int i=2;i<=m;++i) c[i]+=c[i-1];
        for (int i=n;i;--i) sa[c[x[y[i]]]--]=y[i],y[i]=0;
        swap(x,y);
        x[sa[1]]=1; num=1;
        for (int i=2;i<=n;++i)
            x[sa[i]]=(y[sa[i]]==y[sa[i-1]] && y[sa[i]+k]==y[sa[i-1]+k]?num:++num);
        if (num==n) break;
        m=num;
    }
}

void GetHeight(){
	int k=0;
	for (int i=1;i<=n;++i) rk[sa[i]]=i;
	for (int i=1;i<=n;++i){
		if (rk[i]==1) continue;
		if (k) k--;
		int j=sa[rk[i]-1];
		while (j+k<=n && i+k<=n && s[i+k]==s[j+k]) k++;
		height[rk[i]]=k;
	}
}

int main(){
    scanf("%s",s+1);
    l=strlen(s+1);
    s[l+1]='$';
    scanf("%s",s+l+2);
    n=strlen(s+1); m=122;
    GetSA(); GetHeight();
	//for (int i=1;i<=n;++i) printf("%d ",sa[i]);
	//printf("\n");
	//for (int i=1;i<=n;++i) printf("%d ",height[i]);
	//printf("\n");
	for (int i=2;i<=n;++i)
		if ((sa[i]<=l && sa[i-1]>l+1) || (sa[i]>l+1 && sa[i-1]<=l)) ans=max(ans,height[i]);
	printf("%d",ans);
    return 0;
}