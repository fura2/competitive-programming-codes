# findthefirstsubstringequaltothegivenxfromsqrt(2)

import decimal

decimal.getcontext().prec = 10000
s = str(decimal.Decimal(2).sqrt())

x = input()
print(s.index(x)-1)
