N, K = map(int, input().split())
arr = list(map(int, input().split()))
answer = 0
arr3 = []
while(len(arr) > 0):
  now = arr.pop(0)
  if len(arr3) < N:
    if now not in arr3:
      arr3.append(now)
  elif now in arr3:
    continue
  else:
    maxIdx = 0
    maxIdx2 = 0
    for idx, x in enumerate(arr3):
      if x not in arr:
        maxIdx2 = idx
        break
      else:
        for i, val in enumerate(arr):
          if val == x:
            if i >= maxIdx:
              maxIdx = i
              maxIdx2 = idx
            break
    arr3[maxIdx2] = now
    answer += 1
print(answer)