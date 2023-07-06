class Jar:
    def __init__(self, capacity=12):
        # if not(isinstance(capacity, int) and capacity >= 0):
        #     raise ValueError
        self.capacity = capacity
        self.size = 0

    def __str__(self):
        return "🍪"*self.size

    def deposit(self, n):
        if self.size + n > self.capacity:
            raise ValueError('Exceeded jar\'s capacity')
        else:
            self.size += n

    def withdraw(self, n):
        if self.size - n < 0:
            raise ValueError('Not enough cookies to withdraw')
        else:
            self.size -= n

    @property
    def _capacity(self):
        return self.capacity

    @property
    def _size(self):
        return self.size

def main():
    jar = Jar(5)
    print(str(jar.capacity))
    print(str(jar))
    jar.deposit(2)
    print(str(jar))
    jar.withdraw(1)
    print(str(jar))
    jar.deposit(1)
    print(str(jar))
    jar.withdraw(4)
    print(str(jar))

if __name__ == "__main__":
    main()