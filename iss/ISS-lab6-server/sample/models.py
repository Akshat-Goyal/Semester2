from django.db import models

# Create your models here.
class Marks(models.Model):
    name = models.CharField(max_length=100, null=True)
    marks = models.CharField(max_length=100,null=True)
    