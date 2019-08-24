var N=100000;
var Q=100;
var n=Math.floor(Math.random()*(N-1))+1;
var q=Math.floor(Math.random()*(Q-1))+1;
console.log(n+" "+q);
var st="";
for(var i=0;i<n;i++){
	st+=Math.floor(Math.random()*9);
}
console.log(st);
for(var i=0;i<q;i++){
	var a=Math.floor(Math.random()*3);
	if(a>=2){
		var b=Math.floor(Math.random()*(n-1))+1;
		var c=Math.floor(Math.random()*9);
		console.log(1+" "+b+" "+c);
	}
	else{
		var b=Math.floor(Math.random()*(n-1))+1;
		var c=Math.floor(Math.random()*(n-b))+b;
		console.log(2+" "+b+" "+c);	
	}
}