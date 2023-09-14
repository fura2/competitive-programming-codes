n = int(input())

if n == 1:
    for i in range(100):
        if (2456 * i) // 10 == 1719:
            ans = i
            break
elif n == 2:
    ans = 257 + 155 - 334
elif n == 3:
    # 3b + 3d + 3e = 1290
    # 7a + 3b + 3c + 5d + 5e = 4140
    # 4a + 2b + 7c + d + 2e = 3520
    # 5a + 3b + 8c + 2d + 2e = 4510
    # 5a + 3b + c + 5d + 3e = 3320
    # solution is a = -75/2, b = -685/2, c = 1045/2, d = 1695/2, e = -75
    ans = 915
elif n == 4:
    ans = round(9603 / 3.3)
else:
    ans = 2 * (22 * 3 + 45)

print(ans)
