file = open("day4/input.txt", "r")

def check_row(board):
    for row in board:
        ok = True
        for r in row:
            if not r[1]:
                ok = False
        if ok:
            return True

def check_column(board):
    for i in range(5):
        ok = True
        for c in board:
            if not c[i][1]:
                ok = False
        if ok:
            return True

def sum_unmarked(n, board):
    sum = 0
    for b in board:
        for val in b:
            if not val[1]:
                sum += int(val[0])
    return sum * n

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

boardWins = [False for _ in range(len(boards))]
for n in numbers:
    for i,b in enumerate(boards):
        for row in b:
            for x in row:
                if n == x[0]:
                    x[1] = True
        if check_row(b) or check_column(b):
            if not boardWins[i]:
                boardWins[i] = True
                numWin = len([j for j in range(len(boards)) if boardWins[j]])
                if numWin == 1 or numWin == len(boards):
                    print(sum_unmarked(int(n), b))