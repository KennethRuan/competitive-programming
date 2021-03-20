s = input()
n = len(s)
psa = [[0 for _ in range(n+1)] for _ in range(3)]

for i,c in enumerate(s):
    idx = ord(c) - 65
    for j in range(3):
        psa[j][i+1] = psa[j][i]
    psa[idx][i+1] += 1

cnt = [psa[0][-1], psa[1][-1], psa[2][-1]]


def query(c, idx, se):
    if idx + 1 > n:
        return psa[c][(idx+cnt[se]) % n] - psa[c][idx % n]
    if idx + cnt[se] > n:
        return psa[c][n] - psa[c][idx] + psa[c][(idx+cnt[se]) % n]
    return psa[c][idx+cnt[se]] - psa[c][idx]

mins = 9999999

for i,c in enumerate(s):
    mins = min(mins,
               query(1, i, 0) + query(2, i, 0) + query(0, i+cnt[0], 1) + query(2, i+cnt[0], 1) - min(query(1, i, 0), query(0, i+cnt[0], 1)),
               query(1, i, 0) + query(2, i, 0) + query(0, i+cnt[0], 2) + query(1, i+cnt[0], 2) - min(query(2, i, 0), query(0, i+cnt[0], 2)))

print(mins)