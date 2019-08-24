function myArray(array){
	ar=array;
	this.sum=function(){
		let sum=0;
		for(i in ar){
			sum+=ar[i];
		}
		return sum;
	}
	this.product=function(){
		let product=1;
		for(i in ar){
			product*=ar[i];
		}
		return product;
	}
	this.sort=function(){
		let temp=ar.concat();
		temp.sort(function(a,b){return a-b });
		return temp;
	}
	this.modify=function(i,s){
		ar[i]=s;		
	}
	this.display=function(){
		console.log(ar);
	}
}
arrr=[58,56,234,56];
sq = new myArray(arrr);
console.log(sq.ar);
console.log(sq.sum());
console.log(sq.product());
console.log(sq.sort());
sq.modify(1,10);
sq.display();