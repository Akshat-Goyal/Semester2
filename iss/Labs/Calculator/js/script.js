$("#text").val('0');
var c1=0;
var x=1;
var y=1;
var c;
$("#top").click(function(){
	$("#text").val('0');
	c1=0;
});

$("#_7").click(function(){
	if(c1==10)
		return;
	c1++;
	var x=$("#text").val();
	x+=7;
	$("#text").val(x);
});
$("#_8").click(function(){
	if(c1==10)
		return;
	c1++;
	var x=$("#text").val();
	x+=8;
	$("#text").val(x);
});
$("#_9").click(function(){
	if(c1==10)
		return;
	c1++;
	var x=$("#text").val();
	x+=9;
	$("#text").val(x);
});
$("#_4").click(function(){
	if(c1==10)
		return;
	c1++;
	var x=$("#text").val();
	x+=4;
	$("#text").val(x);
});
$("#_5").click(function(){
	if(c1==10)
		return;
	c1++;
	var x=$("#text").val();
	x+=5;
	$("#text").val(x);
});
$("#_6").click(function(){
	if(c1==10)
		return;
	c1++;
	var x=$("#text").val();
	x+=6;
	$("#text").val(x);
});
$("#_1").click(function(){
	if(c1==10)
		return;
	c1++;
	var x=$("#text").val();
	x+=1
	$("#text").val(x);
});
$("#_2").click(function(){
	if(c1==10)
		return;
	c1++;
	var x=$("#text").val();
	x+=2;
	$("#text").val(x);
});
$("#_3").click(function(){
	if(c1==10)
		return;
	c1++;
	var x=$("#text").val();
	x+=3;
	$("#text").val(x);
});
$("#dot").click(function(){
	var x=$("#text").val();
	x+='.';
	$("#text").val(x);
});
$("#plu").click(function(){
		x=parseInt($("#text").val());
	$("#text").val('0');
	c1=0;
	c='+';
});
$("#min").click(function(){
		x=parseInt($("#text").val());
	$("#text").val('0');
	c1=0;
	c='-';
});
$("#mul").click(function(){
		x=parseInt($("#text").val());
	$("#text").val('0');
	c1=0;
	c='*';
});
$("#div").click(function(){
		x=parseInt($("#text").val());
		
	$("#text").val('0');
	c1=0;
	c='/';
});
$("#eq").click(function(){
	y=parseInt($("#text").val());
	if(c=='+'){
		var ans=x+y;
	}
	else if(c=='-'){
		var ans=x-y;
	}
	else if(c=='*'){
		var ans=x*y;
	}
	else if(c=='/'){
		if(y==0){
			$("#text").val("error");
		}
		else{
			var ans=x/y;
		}
	}
	if(y!=0)
		$("#text").val(ans);
});