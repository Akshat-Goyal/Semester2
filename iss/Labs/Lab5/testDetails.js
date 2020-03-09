let arr=require('./data.js');
function getHighestMarks(){
	var max=0;
	var name="";
	for(var i in arr){
		var sum=0;
		for(var j in arr[i]){
			sum+=arr[i][j];
		}
		if(max<sum){
			max=sum;
			name=i;
		}
	}
	return name;
}


function getSubject2Toppers(){
	var max=0;
	for(var i in arr){
		if(max<arr[i][1]){
			max=arr[i][1];
		}
	}
	var ar=new Array();
	for(var i in arr){
		if(arr[i][1]==max){
			ar.push(i);
		}
	}
	ar.sort();
	return ar;
}

getHighestMarks();
getSubject2Toppers();