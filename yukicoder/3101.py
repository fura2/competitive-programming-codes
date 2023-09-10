def f(n):
    if n < 10:
        return 0
    x = 1
    for c in str(n):
        x *= int(c)
    return 1 + f(x)


def main():
    # import cv2
    # img = cv2.imread('input.png', cv2.IMREAD_GRAYSCALE)
    # h, w = img.shape
    # for i in range(h):
    #     for j in range(w):
    #         print(chr(img[j, i]), end='')

    n = int(input())
    print(f(n))


if __name__ == '__main__':
    main()
