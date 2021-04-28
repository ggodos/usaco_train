with open("castle.in") as file:
    M, N = [int(x) for x in file.readline().split()]
    counter = 0
    maxSize = len(str(M*N))
    for i in range(N):
        print(i+1, end=" ")
        print(" "*(maxSize - len(str(i+1))), end="")
        for j in range(M):
            print(counter, end=" ")
            print(" "*(maxSize - len(str(counter))), end="")
            counter += 1
        print()











