# import re

file = open("day4/input.txt", "r")
# file = "day4/input.txt"

lines = file.readlines()
numbers = lines[0].split(",")
board = []
boards = []


for line in lines[1:]:
    line = line.strip()
    if line:
        board.append([[i, False] for i in line.split()])
    else:
        if board:
            boards.append(board)
        board = []
boards.append(board)

def check_row(row):
    # print(row)
    for r in row:
        if r[1] == False:
            return False
    return True

def check_column(board):
    for i in range(5):
        for col in board:
            print(col[i][0])
            if col[i][1] == False:
                # print("false", col)
                return False
    print("TRUE")
    return True
    # for i, c in enumerate(board):
    #     for x in range(5):
    #         print(i,x)
    #         if not c[x][i][1]:
    #             print("False", c)
    #             return False
    #         if li[c][1] == False:
    #             return False
    # print("found winning column")
    # return True


# print(numbers)

def main():
    for n in numbers:
        for b in boards:
            for row in b:
                for x in row:
                    if n==x[0]:
                        x[1] = True
                        if check_row(row):
                            return n, b
                        if check_column(b):
                            return n, b

win_n, win_b = main()
# print(win_n, win_b)


# for b in boards:
#     print(b)
