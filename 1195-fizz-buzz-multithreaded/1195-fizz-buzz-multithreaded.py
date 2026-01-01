from threading import Semaphore

class FizzBuzz:
    def __init__(self, n):
        self.n = n
        self.i = 1

        self.sem_number = Semaphore(1)
        self.sem_fizz = Semaphore(0)
        self.sem_buzz = Semaphore(0)
        self.sem_fizzbuzz = Semaphore(0)

    def fizz(self, printFizz):
        while True:
            self.sem_fizz.acquire()
            if self.i > self.n:
                return
            printFizz()
            self._next()

    def buzz(self, printBuzz):
        while True:
            self.sem_buzz.acquire()
            if self.i > self.n:
                return
            printBuzz()
            self._next()

    def fizzbuzz(self, printFizzBuzz):
        while True:
            self.sem_fizzbuzz.acquire()
            if self.i > self.n:
                return
            printFizzBuzz()
            self._next()

    def number(self, printNumber):
        while True:
            self.sem_number.acquire()
            if self.i > self.n:
                self.sem_fizz.release()
                self.sem_buzz.release()
                self.sem_fizzbuzz.release()
                return

            if self.i % 3 == 0 and self.i % 5 == 0:
                self.sem_fizzbuzz.release()
            elif self.i % 3 == 0:
                self.sem_fizz.release()
            elif self.i % 5 == 0:
                self.sem_buzz.release()
            else:
                printNumber(self.i)
                self._next()

    def _next(self):
        self.i += 1
        self.sem_number.release()
