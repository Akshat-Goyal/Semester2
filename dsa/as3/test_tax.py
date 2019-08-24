from random import randint as rand

N = rand(1, 100)
l = []

print(N)

hireFireCount = 0

for i in range(N):
    if hireFireCount < 100:
        H = rand(1, 100)
        for j in range(H):
            l.append(rand(0,100000) * 100)
            print('H ' + str(l[len(l) - 1]))
            hireFireCount += 1

        F = rand(1, len(l))
        for j in range(F):
            f = rand(0, len(l) - 1)
            print('F ' + str(l[f]))
            del l[f]
            hireFireCount += 1

    B = rand(0, 1000000)

    print('A ' + str(B))

