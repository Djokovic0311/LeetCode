class PhoneDirectory:

    def __init__(self, maxNumbers: int):
        self.numbers = [0]*maxNumbers
        self.limit = maxNumbers

    def get(self) -> int:
        self.limit -= 1
        if self.limit < 0:
            self.limit += 1
            return -1
        else:
            idx = self.numbers.index(0)
            self.numbers[idx] = 1
            return idx

    def check(self, number: int) -> bool:
        return self.numbers[number] == 0

    def release(self, number: int) -> None:
        if self.numbers[number] == 1:
            self.limit += 1
            self.numbers[number] = 0



# Your PhoneDirectory object will be instantiated and called as such:
# obj = PhoneDirectory(maxNumbers)
# param_1 = obj.get()
# param_2 = obj.check(number)
# obj.release(number)
