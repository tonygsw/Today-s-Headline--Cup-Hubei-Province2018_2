from Crypto.Util import number
import os

res = 1
for i in range(0, 141):
    new_prime = number.getPrime(512, os.urandom)
    res *= new_prime

print(res)
print(len(str(res)))
