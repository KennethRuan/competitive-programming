def cyclic_util(root,graph,visited,rec_stack):
    # print("root:",root)
    # print("paths:",graph[root])

    visited[root-1] = True
    rec_stack[root-1] = True

    # print("visited:",visited)
    # print("recStack:",rec_stack)

    for paths in graph[root]:

        if not visited[paths-1]:
            if cyclic_util(paths,graph,visited,rec_stack):
                return True
        elif rec_stack[paths-1]:
            return True

    rec_stack[root-1] = False
    return False


def cyclic(graph):
    visited = [False]*n
    rec_stack = [False]*n
    for i in range(1, n + 1):
        if not visited[i-1]:
            if cyclic_util(i, graph, visited, rec_stack):
                return True
    return False

n = int(input())
m = int(input())

l = [[] for i in range(1,n+1)]

for i in range(m):
    a = input().split(" ")
    l[int(a[0])-1].append(int(a[1]))

graph = dict((i+1,l[i]) for i in range(n))

if cyclic(graph):
    print("N")
else:
    print("Y")