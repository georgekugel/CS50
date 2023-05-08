from cs50 import get_float

def main():
    while True:
        change = get_float("Change owed: ")
        if change >= 0:
            break

    change_cents = round(change * 100)
    coins = 0

    coins += change_cents // 25
    change_cents %= 25

    coins += change_cents // 10
    change_cents %= 10

    coins += change_cents // 5
    change_cents %= 5

    coins += change_cents

    print(coins)

if __name__ == "__main__":
    main()