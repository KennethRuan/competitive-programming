q = int(input())
wins = [35,100,10]
payout = [30,60,9]
mplays = [int(input())+1 for i in range(3)]
plays = 0
i = 0


def pay_check(i, q):
    if mplays[i] == wins[i]:
        q += payout[i]
        mplays[i] = 1
    else:
        mplays[i] += 1
    return q


while q > 0:
    q -= 1
    plays += 1
    q = pay_check(i, q)
    i += 1
    if i > 2:
        i = 0


print("Martha plays " +str(plays)+" times before going broke.")