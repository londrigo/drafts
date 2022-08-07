def is_prime(n):
    if (n != 2 and n%2 == 0):
        return False
    m = n -1    
    while(m > 1):
        if ((n % m) == 0):
            return (False)
        m -= 1
    return(True)

def primes():
    num = 1
    while True:
        if is_prime(num):
            yield num
        num += 1

generator = primes()


# Listing the first 1000 prime numbers 
it = 0 
while (it<1000):
    print(next(generator))
    it += 1


