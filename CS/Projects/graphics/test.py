import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLU import *

vertices = (
    (0, 0, 0), # 0
    (1, 0, 0), # 1
    (0, 1, 0), # 2
    (0, 0, 1), # 3
    (1, 1, 0), # 4
    (1, 0, 1), # 5
    (0, 1, 1), # 6
    (1, 1, 1)  # 7
)

edges = (
    (0,1),
    (0,2),
    (0,3),
    (1,4),
    (1,5),
    (2,4),
    (2,6),
    (3,5),
    (3,6),
    (4,7),
    (5,7),
    (6,7)
)

def Cube():
    glBegin(GL_LINES)
    for edge in edges:
        for vertex in edge:
            glVertex3fv(vertices[vertex])
    glEnd()


def main():
    pygame.init()
    display = (800,600)
    pygame.display.set_mode(display, DOUBLEBUF|OPENGL)
    pygame.display.toggle_fullscreen()

    gluPerspective(45, (display[0]/display[1]), 0.1, 50.0)

    glTranslatef(0.0,0.0, -5)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

        glRotatef(1, 3, 1, 1)
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
        Cube()
        pygame.display.flip()
        pygame.time.wait(10)


main()
