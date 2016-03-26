def checkPrime(n):
    if n == 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0:
        return False
    if n % 3 == 0:
        return False

    i = 5
    w = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += w
        w = 2 - w
    
    return True

i = 3
count = 1
cumul = 2
while (count < 1000):
    if checkPrime(i):
        cumul += i
        count += 1
    i += 2

print cumul
