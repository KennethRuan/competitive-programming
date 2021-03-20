r, c = map(int,input().split())
k = int(input())
matrix = [[0]*c for i in range(r)]
cats = [[] for i in range(r)]

matrix[0][0] = 1


for i in range(k):
    a, b = map(int,input().split())
    cats[a-1].append(b-1)

for i in range(r):
    for j in range(c):
        matrix[i][j] += (matrix[i-1][j] if i > 0 else 0) + (matrix[i][j-1] if j > 0 else 0)
        if j in cats[i]:
            matrix[i][j] = 0

print(matrix[-1][-1])