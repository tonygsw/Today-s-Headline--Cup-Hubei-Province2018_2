a = 1
tot_bits = 0

for i in range(2, 1000000):
    prime = True
    for j in range(2, i):
        if j * j > i:
            break
        if i % j == 0:
            prime = False
    if not prime:
        continue
    if len(str(i * a)) > 100000:
        break
    print(i)
    a *= i

print("ans")
print(a)
