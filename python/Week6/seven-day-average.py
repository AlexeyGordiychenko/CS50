import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    new_cases = {}

    for row in reader:
        state = row['state']
        cases = int(row['cases'])
        if state not in new_cases:
            new_cases[state] = []

        new_cases[state].append(cases)
        if len(new_cases[state]) > 15:
            new_cases[state].pop(0)

    for state, cases in new_cases.items():
        new_cases[state] = [j-i for i, j in zip(cases[:-1], cases[1:])]

    return new_cases

# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        cases = new_cases[state]
        print(cases)
        avg1 = sum(cases[0:8]) / 7
        avg2 = sum(cases[7:]) / 7

        try:
            if (avg1 > avg2):
                change = 'decrease'
                percent = (avg1 - avg2) / avg1 * 100
            else:
                change = 'increase'
                percent = (avg2 - avg1) / avg2 * 100
        except ZeroDivisionError:
            change = 'plateau'
            percent = 0
        print(f'{state} had a 7-day average of {avg2:.0f} and an {change} of {percent:.0f}%.')

main()
