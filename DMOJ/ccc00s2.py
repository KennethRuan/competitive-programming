m = int(input())
rivers=[0]
function = ""
for i in range(m):
    rivers.append(float(input()))

# print(rivers)
while function != "77":
    function = input()
    if function == "99":
        split = int(input())
        percent = float(input())
        # print(percent)
        rivers.insert(split,rivers[split]*percent/100)
        rivers[split+1] = rivers[split+1]*(1-percent/100)

    # print(rivers)
    if function =="88":
        join = int(input())
        rivers[join]+=rivers[join+1]
        rivers.pop(join+1)
    # print(rivers)

rivers = list(map(round,rivers))
# print(rivers)

for i in range(1,len(rivers)-1):
    print(rivers[i],end=" ")

print(rivers[-1])