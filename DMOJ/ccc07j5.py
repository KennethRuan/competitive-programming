mind = int(input())
maxd = int(input())
hotels = [0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000]
for i in range(int(input())):
    hotels.append(int(input()))
hotels.sort()
dp = [1] + [0 for i in range(1,len(hotels))]
for i in range(1,len(hotels)):
    for j in range(i):
        if mind <= hotels[i]-hotels[j] <= maxd:
            dp[i] += dp[j]
print(dp[-1])