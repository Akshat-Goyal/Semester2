function toCamelCase(st) {
	var ar=st.split(' ');
	var string="";
	for(let i=0,f=0;i<ar.length;i++){
		let s=ar[i].split('');
		if(s[0]>="a" && s[0]<="z" && f!=0){
			s[0]=s[0].toUpperCase();
			string+=s.join('')+" ";
		}
		else if(s[0]>='A' && s[0]<='Z' && f==0){
			s[0]=s[0].toLowerCase();
			string+=s.join('')+" ";
			f=1;
		}
		else{
			string+=s.join('')+" ";
		}
	}
	console.log(string);
	return string;
}

toCamelCase("! Hello there, how are you !!");