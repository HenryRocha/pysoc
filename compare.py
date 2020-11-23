import time
import pysoc
import bubble

l = list(reversed(range(int(1e4))))
print("== Python ==")
time1 = time.time()
l1 = bubble.bubble_sort(l)
time0 = time.time()
print(f"> {time0 - time1} seconds")

print("== C ==")
time3 = time.time()
l2 = pysoc.bubble_sort(l)
time2 = time.time()
print(f"> {time2 - time3} seconds")
print(f"\n> C is {(time0 - time1)/(time2 - time3)} times faster")


print(l1 == l2 == sorted(l))
