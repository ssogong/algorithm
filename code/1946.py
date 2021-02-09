import sys
T = int(input())
answer = []
for i in range(T):
    arr = []
    N = int(input())
    for _ in range(N):
        a, b = map(int, sys.stdin.readline().strip().split())
        arr.append((a, b))
    arr.sort(key=lambda x: x[0])
    min = arr[0][1]
    cnt = 1
    for j in arr[1:]:
      if j[1] < min:
        cnt +=1
        min = j[1]
    answer.append(cnt)
for i in range(T):
    print(answer[i])