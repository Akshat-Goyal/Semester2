from random import randint

n = 12
t = randint(n // 2, n)
k = randint(t // 2, t)
print(str(n) + " " + str(t) + " " + str(k))
x = ""
for i in range(n):
    x += str(randint(-100, 100)) + " "

print(x)
