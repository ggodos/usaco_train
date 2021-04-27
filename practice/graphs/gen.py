with open("input.txt", "r") as file:
    eight = 8
    file.readline()
    array = [x.strip().split() for x in file.readlines()]
    for i in array:
        for j in range(len(i)):
            i[j] = int(i[j])
    with open("input.txt", "w") as file:
        file.write("8")
        for i in array:
            file.write("\n")
            counter = 0
            for j in range(len(i)):
                file.write(str(i[j]-1))
                if (counter == 1):
                    file.write(" ")
                    counter = 0
                file.write(" ")
                counter += 1
        print(*array, sep=" ")