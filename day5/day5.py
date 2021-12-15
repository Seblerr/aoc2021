def main(diag=False):
    grid = {}
    for line in open("input.txt", "r"):
        start, end = line.split("->")
        x1,y1 = start.split(",")
        x2,y2 = end.split(",")
        x1 = int(x1)
        x2 = int(x2)
        y1 = int(y1)
        y2 = int(y2)

        if x1 == x2 or y1 == y2:
            for x in range(min(x1,x2), max(x1,x2)+1):
                for y in range(min(y1,y2), max(y1,y2)+1):
                    if (x,y) not in grid:
                        grid[(x,y)] = 1
                    else:
                        grid[(x,y)] +=1

    num = 0
    for key,value in grid.items():
        if value >= 2:
            num += 1
    print(num)

main()