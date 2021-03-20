n = int(input())
arr = list(map(int,input().split()))

def mergeSort(l,r):
    if l == r:
        return [arr[l]]
    mid = (l+r)//2
    return merge(mergeSort(l,mid),mergeSort(mid+1,r))

def merge(a,b):
    i = 0
    j = 0
    global inv
    res = []
    while i < len(a) and j < len(b):
        if a[i] <= b[j]:
            res.append(a[i])
            i += 1
        else:
            res.append(b[j])
            j += 1
            inv += len(a) - i 
    while i < len(a):
        res.append(a[i])
        i+= 1
    while j < len(b):
        res.append(b[j])
        j+= 1

    return res

inv = 0
mergeSort(0,len(arr)-1)
print(inv)