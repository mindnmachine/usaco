from bisect import bisect_right

[n, l] = list(map(int, input().strip().split()))
c = list(map(int, input().strip().split()))

c.sort()

def check(h):
  a = c[len(c)-h]
  if a >= h:
    return True
  if a == h-1:
    r = bisect_right(c, h-1)-1
    return r - (len(c)-h) + 1 <= l
  return False


left = 0
right = len(c)+1
while left + 1 < right:
  h = (left + right) // 2
  if check(h):
    left = h
  else:
    right = h

print(left)