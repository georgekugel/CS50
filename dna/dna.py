import csv
import sys

def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    csv_file = sys.argv[1]
    dna_file = sys.argv[2]

    with open(csv_file, "r") as file:
        database = list(csv.reader(file))
        headers = database[0]
        database = database[1:]

    with open(dna_file, "r") as file:
        dna_sequence = file.read()

    longest_matches = [longest_match(dna_sequence, headers[i]) for i in range(1, len(headers))]

    for row in database:
        if all(int(row[i]) == longest_matches[i - 1] for i in range(1, len(headers))):
            print(row[0])
            break
    else:
        print("No match")

def longest_match(sequence, subsequence):
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):
        count = 0

        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        longest_run = max(longest_run, count)

    return longest_run

if __name__ == "__main__":
    main()
