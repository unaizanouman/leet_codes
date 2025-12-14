class Solution:
    def numberOfWays(self, corridor):
        MOD = 10**9 + 7

        # positions of all seats
        seats = [i for i, c in enumerate(corridor) if c == 'S']

        # invalid cases
        if len(seats) < 2 or len(seats) % 2 != 0:
            return 0

        ways = 1

        # process seat pairs
        for i in range(2, len(seats), 2):
            # plants between previous pair and next pair
            gap = seats[i] - seats[i - 1]
            ways = (ways * gap) % MOD

        return ways
