import requests as req

r=req.get('https://api.opendota.com/api/players/431931403/heroes?significant=0');
r=r.json();
maxi=0
x=0
y=0
z=0
maxid=0
for a in r:
	x=a['games']
	y=a['win']
	if x>=6 and ((y/x)*100)>maxi:
		maxi=(y/x)*100
		maxid=a['hero_id']
print(maxi, maxid)
