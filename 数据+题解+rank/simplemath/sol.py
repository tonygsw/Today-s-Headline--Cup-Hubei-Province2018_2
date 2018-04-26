import sys

cnt = 0
arr = []
fst = False
for line in sys.stdin:
    if fst:
        arr.append(int(line))
    fst = True
cnt = len(arr)
step = 1
while step < cnt:
    cur = 0
    while cur + step < cnt:
        arr[cur] *= arr[cur + step]
        arr[cur + step] = None
        cur += step * 2
    step *= 2

print(arr[0])
