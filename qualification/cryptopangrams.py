#!/usr/bin/python3

import math

t = int(input())
for tc in range(0, t):
  n, l = [int(k) for k in input().split()]
  a = [int(k) for k in input().split()]

  pivot = None
  b = [None] * (l + 1)
  for i in range(1, l - 1):
    if a[i - 1] != a[i]:
      pivot = i
      b[i] = math.gcd(a[i - 1], a[i])
      break

  for i in range(pivot - 1, -1, -1):
    b[i] = a[i] // b[i + 1]
  for i in range(pivot + 1, l + 1):
    b[i] = a[i - 1] // b[i - 1]

  conv = {val: chr(ord('A') + idx) for idx, val in enumerate(sorted(set(b)))}
  res = ''.join(conv[bi] for bi in b)
  print(f'Case #{tc + 1}: {res}')
