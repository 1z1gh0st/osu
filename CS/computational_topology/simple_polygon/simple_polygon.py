import random
import pygame
import math

class Point:

    # Point class
    def __init__(self, x, y):
        self.x = x
        self.y = y


class Line:

    # Line class
    def __init__(self, a, b):
        self.a = a
        self.b = b

    # Define equality so that Line(a,b) == Line(b,a)
    def __eq__(self, other):
        if isinstance(other, Line):
            if self.a == other.a:
                return self.b == other.b
            elif self.b == other.a:
                return self.a == other.b
            else:
                return False
        else:
            return False

    # Slope calculator
    def slope(self):
        if self.a.x < self.b.x:
            rise = self.b.y - self.a.y
            run = self.b.x - self.b.x
            if rise == 0:
                return 0
            elif run == 0:
                return 1000000
            else:
                return rise / run
        elif self.a.x > self.b.x:
            rise = self.a.y - self.b.y
            run = self.a.x - self.b.y
            if rise == 0:
                return 0
            elif run == 0:
                return 1000000
            else:
                return rise / run

    # Length calculator
    def length(self):
        return distance(self.a, self.b)


def distance(a, b):

    # Takes two points and returns the distance between them
    return math.sqrt(((a.x - b.x) ** 2) + ((a.y - b.y) ** 2))


# Function to check if 3 points are co-linear
def colinear(a, b, c):

    # If any pair of points is equal we know they are immediately colinear
    if a == b or b == c or a == c:
        return True

    # Otherwise we check the slope of each line and if they are the same then we return true
    slope_a_b = Line(a,b).slope()
    slope_a_c = Line(a,c).slope()
    if slope_a_b == slope_a_c:
        return True
    else:
        return False


# Function to draw a triangle: takes 3 points
def draw_triangle(a, b, c):
    draw_line(Line(a,b), red)
    draw_line(Line(b,c), red)
    draw_line(Line(c,a), red)


def draw_line(line, color):
    pygame.draw.line(screen, color, (line.a.x * width, line.a.y * height), (line.b.x * width, line.b.y * height), 2)

def smallest_radius(a, b, c):
    r = 0
    while not intersecting(a, b, c, r):
        r += 0.1
    return r

def intersecting(seg_start, seg_end, center, radius):
    if distance(seg_start, center) < distance(seg_end, center):
        if distance(seg_start, center) < radius < distance(seg_end, center):
            return True
        else:
            return False
    else:
        if distance(seg_end, center) < radius < distance(seg_start, center):
            return True
        else:
            return False

points = []

n = 10
visited = dict()

for point in points:
    visited[point] = False

for i in range(0, n):
    point = Point(random.random(), random.random())
    points.append(point)

width = 800
height = 1080
size = (width, height)
screen = pygame.display.set_mode(size)
pygame.display.flip()

white = (255, 255, 255)
blue = (0, 0, 255)
red = (255, 0, 0)

for point in points:
    pygame.draw.circle(screen, white, (int(point.x * width), int(point.y * height)), 5)

lines = []
'''
a = points[0]
b = points[1]
for c in points:
    if not colinear(a, b, c):
        lines.append(Line(a, b))
        lines.append(Line(b, c))
        lines.append(Line(c, a))
        # draw_triangle(a, b, c)
        break
        '''
for p in points:
    for q in points:
        lines.append(Line(p,q))

for line in lines:
    draw_line(line, red)
    print(line.a.x, line.a.y, line.b.x, line.b.y)

running = True
while running:
    for event in pygame.event.get():
        pygame.display.update()
        if event.type == pygame.QUIT:
            running = False


