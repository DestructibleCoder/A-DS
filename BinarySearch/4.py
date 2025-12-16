import math

def check(a: list, n: int, c: int, m: int, r: int) -> bool:
    i, count = 0, 0
    while i <= n-c:
        if a[i+c-1]-a[i] <= m:
            count += 1
            i += c
        else:
            i+=1
    return count >= r


def main():
    n, r, c = map(int, input().split())
    
    a = list()
    for i in range(n): a.append(int(input()))
    a.sort()
    
    L, R = -1, a[-1]-a[0]

    while R - L > 1:
        m = L + (R - L)//2
        if check(a, n, c, m, r):
            R = m
        else:
            L = m
    print(R)

if __name__ == '__main__':
    main()