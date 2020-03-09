from django.conf.urls import url
from . import views
urlpatterns = [url(r'^hello$', views.helloWorld, name='helloWorld'),
               url(r'^getmarks$', views.getMarks, name='getMarks'),
               ]