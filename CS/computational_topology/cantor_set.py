import pygame

def remove_middle_third(array, r, l):
    array.append(r + ((l - r) / 3))
    array.append(r + (2 * ((l - r) / 3)))
    array.sort()

width = 1920
height = 1080
size = (width, height)
screen = pygame.display.set_mode(size)
pygame.display.flip()

array = [0,1]

n = 7

bar_height = height / n

BLUE = (0, 0, 255)

for i in range(0, n):
    num_intervals = len(array) / 2
    print("Remove ", 2 ** i, " intervals...")
    temp = []
    for j in range(0, 2 ** i):
        temp.append((array[0 + (2 * j)], array[1 + (2 * j)]))
    for pair in temp:
        pygame.draw.rect(screen,BLUE,(pair[0] * width, i * bar_height, (pair[1] - pair[0]) * width, bar_height))
        remove_middle_third(array, pair[0], pair[1])
    print(array)


running = True
while running:
    for event in pygame.event.get():
        pygame.display.update()
        if event.type == pygame.QUIT:
            running = False

