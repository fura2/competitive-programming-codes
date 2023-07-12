d = int(input())
a1, a2 = map(int, input().split('.'))
b1, b2 = map(int, input().split('.'))

c1 = a1 + b1
c2 = a2 + b2
c1 += c2 // (10 ** d)
c2 %= 10 ** d
c2 = str(c2)
c2 = ('0' * (d-len(c2))) + c2
print(f'{c1}.{c2}')
