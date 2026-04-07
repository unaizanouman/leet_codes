class Robot:

    def __init__(self, width, height):
        self.w = width
        self.h = height
        self.x = 0
        self.y = 0
        self.dir = 0 
        
        self.perimeter = 2 * (width + height) - 4
        self.moved = False
    def step(self, num):
        self.moved = True
        
        num %= self.perimeter
        if num == 0:
            num = self.perimeter
        
        while num > 0:
            if self.dir == 0:  # East
                steps = min(num, self.w - 1 - self.x)
                self.x += steps
            elif self.dir == 1:  # North
                steps = min(num, self.h - 1 - self.y)
                self.y += steps
            elif self.dir == 2:  # West
                steps = min(num, self.x)
                self.x -= steps
            else:  # South
                steps = min(num, self.y)
                self.y -= steps
            
            num -= steps
            if num > 0:
                self.dir = (self.dir + 1) % 4

    def getPos(self):
        return [self.x, self.y]

    def getDir(self):
        directions = ["East", "North", "West", "South"]
        if not self.moved:
            return "East"
        
        return directions[self.dir]