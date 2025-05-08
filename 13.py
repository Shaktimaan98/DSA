import random

ladder = {1: 38, 4: 14, 8: 30, 21: 42, 28: 76, 50: 67, 71: 92, 80: 99}
snake = {32: 10, 34: 6, 48: 26, 62: 18, 88: 24, 95: 56, 97: 78}
pos1 = 0
pos2 = 0

def move(pos):
    dice = random.randint(1, 6)
    print(f"Dice: {dice}")
    pos = pos + dice
    if pos in snake:
        print("Bitten by Snake")
        pos = snake[pos]
        print(f"Position: {pos}")
    elif pos in ladder:
        print("Climbed by Ladder")
        pos = ladder[pos]
        print(f"Position: {pos}")
    else:
        print(f"Position: {pos}")
    print("\n")
    return pos

while True:
    A = input("Player 1, enter \"A\" to throw Dice: ")
    if A.lower() == 'a':  # Ensure player 1 throws dice only when they input 'A'
        pos1 = move(pos1)
        if pos1 >= 100:
            print("Game Over\nPlayer 1 Wins!")
            break
    else:
        print("Invalid input. Please enter 'A' to throw the dice for Player 1.")
        continue

    A = input("Player 2, enter \"B\" to throw Dice: ")
    if A.lower() == 'b':  # Ensure player 2 throws dice only when they input 'B'
        pos2 = move(pos2)
        if pos2 >= 100:
            print("Game Over\nPlayer 2 Wins!")
            break
    else:
        print("Invalid input. Please enter 'B' to throw the dice for Player 2.")
        continue
