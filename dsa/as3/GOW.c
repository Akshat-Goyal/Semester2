#include<stdio.h>
#define ll long long int 

typedef struct {
	ll x,y;
}tr;

tr ar[100001];
tr ar2[100001];
ll st[2][100001];

void swap(tr *a,tr *b){
	tr t=*a;
	*a=*b;
	*b=t;
}

void minin(ll i){
	while(i!=1 && ar[i/2].x>ar[i].x){
		swap(&ar[i/2],&ar[i]);
		st[1][ar[i/2].y]=i/2;
		st[1][ar[i].y]=i;
		i/=2;
	}
}

void maxin(ll i){
	while(i!=1 && ar2[i/2].x<ar2[i].x){
		swap(&ar2[i/2],&ar2[i]);
		st[1][ar2[i/2].y]=i/2;
		st[1][ar2[i].y]=i;
		i/=2;
	}
}

void minheap(ll i,ll n){
	while(i<=n){
		int min=i;
		if(2*i<=n && ar[i].x>ar[2*i].x)
			min=2*i;
		if(2*i+1<=n && ar[min].x>ar[2*i+1].x)
			min=2*i+1;
		if(min==i)
			break;
		swap(&ar[i],&ar[min]);
		st[1][ar[min].y]=min;
		st[1][ar[i].y]=i;
		i=min;
	}
}

void maxheap(ll i,ll n){
	while(i<=n){
		int max=i;
		if(2*i<=n && ar2[i].x<ar2[2*i].x)
			max=2*i;
		if(2*i+1<=n && ar2[max].x<ar2[2*i+1].x)
			max=2*i+1;
		if(max==i)
			break;
		swap(&ar2[i],&ar2[max]);
		st[1][ar2[max].y]=max;
		st[1][ar2[i].y]=i;
		i=max;
	}	
}

void maxde(ll i,ll n){
	ar2[i]=ar2[n--];
	st[1][ar2[i].y]=i;
	if(i==1 || ar2[i].x<=ar2[i/2].x){
		maxheap(i,n);
	}
	else{
		while(i!=1 && ar2[i/2].x<ar2[i].x){
			swap(&ar2[i/2],&ar2[i]);
			st[1][ar2[i/2].y]=i/2;
			st[1][ar2[i].y]=i;
			i/=2;
		}
	}
}

void minde(ll i,ll n){
	ar[i]=ar[n--];
	st[1][ar[i].y]=i;
	if(i==1 || ar[i].x>=ar[i/2].x){
		minheap(i,n);
	}
	else{
		while(i!=1 && ar[i/2].x>ar[i].x){
			swap(&ar[i/2],&ar[i]);
			st[1][ar[i/2].y]=i/2;
			st[1][ar[i].y]=i;
			i/=2;
		}
	}
}

	int main(){
		ll n,t,k;
		scanf("%lld%lld%lld",&n,&t,&k);

		ll sum=0;
		for(ll i=1,x;i<=k;i++){
			scanf("%lld",&x);
			sum+=x;
			st[0][i]=1;
			st[1][i]=i;
			ar[i].x=x;
			ar[i].y=i;
			minin(i);
		}

		ll a2=0;
		for(ll i=k+1,x;i<=t;i++){
			scanf("%lld",&x);
			if(x>=ar[1].x){
				st[0][ar[1].y]=0;
				ar2[++a2].x=ar[1].x;
				ar2[a2].y=ar[1].y;
				st[1][ar[1].y]=a2;
				maxin(a2);
				sum-=ar[1].x-x;
				ar[1].x=x;
				ar[1].y=i;
				st[0][i]=1;
				st[1][i]=1;
				minheap(1,k);
			}
			else{
				st[0][i]=0;
				st[1][i]=a2+1;
				ar2[++a2].x=x;
				ar2[a2].y=i;
				maxin(a2);
			}
		}

		ll max=sum;
		for(ll i=t+1,x;i<=n;i++){
			scanf("%lld",&x);
			ll f=0;
			if(st[0][i-t]==1){
				f=1;
				st[0][i-t]=-1;
				sum-=ar[st[1][i-t]].x;
				minde(st[1][i-t],k);
			}
			else{
				st[0][i-t]=-1;
				maxde(st[1][i-t],a2);
				a2--;
			}
			if(f==1){
				if(a2==0 || x>=ar2[1].x){
					ar[k].x=x;
					ar[k].y=i;
					st[0][i]=1;
					st[1][i]=k;
					minin(k);
					sum+=x;
				}
				else{
					f=3;
					ar[k]=ar2[1];
					sum+=ar2[1].x;
					st[0][ar2[1].y]=1;
					st[1][ar2[1].y]=k;
					minin(k);
					maxde(1,a2);
					a2--;
				}
			}
			else if(x>=ar[1].x){
				sum=sum-ar[1].x+x;
				st[0][ar[1].y]=0;
				ar2[++a2]=ar[1];
				st[1][ar[1].y]=a2;
				maxin(a2);
				ar[1].x=x;
				ar[1].y=i;
				st[0][i]=1;
				st[1][i]=1;
				minheap(1,k);
			}
			else{
				f=3;
			}
			if(f==3){
				ar2[++a2].x=x;
				ar2[a2].y=i;
				st[0][i]=0;
				st[1][i]=a2;
				maxin(a2);
			}
			
			max=max>=sum?max:sum;
		}
		printf("%lld\n",max);
		return 0;
	}