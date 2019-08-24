function fifthMonth(a){
	let ar={"January":"0","February":"1","March":"2","April":"3","May":"4","June":"5","July":"6","August":"7","September":"8","October":"9","November":"10","December":"11"};	
	let arr={"0":"January","1":"February","2":"March","3":"April","4":"May","5":"June","6":"July","7":"August","8":"September","9":"October","10":"November","11":"December"};	
	return arr[(ar[a]+5)%12];
}

fifthMonth("January");