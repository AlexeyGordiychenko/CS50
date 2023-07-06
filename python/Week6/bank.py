from cs50 import get_string

def main():
    input = get_string("Greeting")
    if input.lstrip().lower()[:5] == "hello":
        print("$0")
    elif input.lstrip().lower()[:1] == "h":
        print("$20")
    else:
        print("$100")

if __name__ == "__main__":
    main()