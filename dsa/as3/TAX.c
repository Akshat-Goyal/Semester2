#include<stdio.h>
#include<stdlib.h>
#define ll long long int

typedef struct tree{
	ll data,n,ri,le;
	struct tree *left,*right;
}tree;

ll summ(tree *r){
	if(r==NULL)
		return 0;
	return (r->le+r->ri);
}

tree* insert(tree *r,ll x){
	if(r==NULL){
		r=(tree*)malloc(sizeof(tree));
		r->data=x;
		r->n=1;
		r->le=0;
		r->ri=x;
		r->left=r->right=NULL;
		return r;
	}

	if(x==r->data){
		r->n++;
	}
	else if(x<r->data){
		r->left=insert(r->left,x);
	}
	else {
		r->right=insert(r->right,x);
	}

	r->le=summ(r->left);
	r->ri=summ(r->right)+r->data*r->n;

	return r;
}

tree* maxr(tree *r){
	if(r->right==NULL)
		return r;
	return maxr(r->right);
}

ll f=0;

tree* delet(tree *r,ll x){
	if(r==NULL)
		return r;
	if(x<r->data){
		r->left=delet(r->left,x);
	}
	else if(x>r->data){
		r->right=delet(r->right,x);
	}
	else if(f==0 && r->n-1!=0){
		r->n--;
	}
	else{
		r->n--;
		if(r->left==NULL){
			tree *temp=r->right;
			free(r);
			r=temp;
		}
		else if(r->right==NULL){
			tree *temp=r->left;
			free(r);
			r=temp;
		}
		else{
			tree *temp=maxr(r->left);
			r->data=temp->data;
			r->n=temp->n;
			f=1;
			r->left=delet(r->left,temp->data);
			f=0;
		}
	}


	if(r==NULL)
		return r;

	r->le=summ(r->left);
	r->ri=summ(r->right)+r->data*r->n;

	return r;
}

ll ans(tree*r){
	if(r==NULL)
		return 0;
	return (r->le/10+r->ri/2);
}

void fun(tree *r,ll x){
	ll first=-1;
	ll b=ans(r);
	while(r!=NULL){
		
		if(b>=x){
			first=r->data;
			b-=r->ri / 2;
			b+=(r->data*r->n)/10+ans(r->right);
			r=r->right;
		}
		else{
			b-=r->le/10;
			b+=ans(r->left);
			r=r->left;	
		}
	}
	if(first==-1){
		printf("Alert!\n");
	}
	else{
		printf("%lld\n",first);
	}
	return;
}

void inorder(tree *r){
	if(r==NULL)
		return;
	inorder(r->left);
	printf("%lld %lld: ",r->data,r->n);
	inorder(r->right);
}

	int main(){
		ll n,k=0;
		scanf("%lld",&n);
		tree *r=NULL;
		ll sum=0;
		// r=insert(r,1000000000);
		// r->n=0;
		// r->le=r->ri=0;
		while(n--){
			char a,c;
			ll in;
			while(1){
				scanf("%c%c%lld",&c,&a,&in);
				if(a=='A'){
					break;
				}
			
				if(a=='H'){
					sum+=in;
					r=insert(r,in);
				}
				else{
					sum-=in;
					r=delet(r,in);
					// inorder(r);
					// printf("\n");
				}
			}
			if(sum/10>=in){
				printf("1000000000\n");
				continue;
			}
			if((r==NULL && in==0)){
				printf("1000000000\n");
				continue;
			}
			fun(r,in);
		}
		return 0;
	}