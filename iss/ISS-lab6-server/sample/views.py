from django.shortcuts import render
from django.http import HttpResponseRedirect
from django.http import HttpResponse
from django.contrib import auth
from django.contrib.auth.models import User
from django.views.decorators.csrf import csrf_exempt
from sample.models import Marks
from django.http import JsonResponse

@csrf_exempt
def helloWorld(request):
    return HttpResponse('Hellow World!')

@csrf_exempt
def getMarks(request):
    letter = request.POST.get('letter', '')
    ret = Marks.objects.filter(name__startswith=letter)
    json = {}
    for m in ret:
    	name = m.name
    	marks = eval(m.marks)
    	json[name] = marks
    print(json)
    return JsonResponse(json,safe=False)