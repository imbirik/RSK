
import matplotlib.pyplot as plt
import matplotlib.patches
import numpy as np
#import ffmpeg
import json
import os
import matplotlib.animation as animation
#import imagemagick
import ffmpeg


def read(filename, Q_tabluax = False):
    with open(filename, 'r') as f:
        tabluaxes = json.loads(f.read())
    return tabluaxes

tabluax = read('out.txt')  

# def draw_PQ(tableaux, i, fig, ax, Q_tableau=False, show=True):
#     P = tabluax[i][0]
#     Q = tabluax[i][1]
#     if Q_tableau:
#         draw(P, fig=fig, ax=ax)
#         draw(Q, fig=fig, ax=ax, shift=len(P[0])+1)
#     else:
#         draw(P, fig=fig, ax=ax)
#     if show:
#       plt.show()
class BumpingTraceAnimation:


    def __init__(self, trace):
        self.x_trace = []
        self.y_trace = []
        self.fig = plt.figure()
        self.ax = plt.axes(xlim=(0, 1), ylim=(0, 1))
        self.line = self.ax.plot([], [], lw=1)
        for elem in trace:
            x = elem[0]
            y = elem[1]
            scale = elem[2]
            x = x/scale
            y = y/scale
            x_rotated = x/np.sqrt(2) + y/np.sqrt(2)
            y_rotated = -x/np.sqrt(2) + y/np.sqrt(2)
            self.x_trace.append(x_rotated)
            self.x_trace.append(y_rotated)
        self.dots_number = len(self.x_trace)

    def animate(self, i):
        self.line.set_data(self.x_trace[: i], y_trace[: i])
        return self.line
    
    def create_animation(self):
        anim = animation.FuncAnimation(self.fig, self.animate, frames=self.dots_number, interval=20)




class YoungAnimation:
    
    def __init__(self, tabluax):
        self.tabluax = tabluax1
        self.fig = plt.figure()
        self.ax = plt.axes(xlim=(0, 10), ylim=(0, 10))

    def draw(self, tableau, shift=0):
        y_shape = len(tableau)
        x_shape = len(tableau[0])
        rgb = np.zeros([y_shape, x_shape, 3])
        for i in range(len(tableau)):
            for j in range(len(tableau[i])):
                rgb[i][j][0] = 255/255
                rgb[i][j][1] = 0/255
                rgb[i][j][2] = 0/255
        for i in range(len(tableau)):
            for j in range(len(tableau[i])):
                text = ''#tableau[i][j]
                self.ax.text(j+shift+0.5, i+0.5, text, fontsize=20, ha="center", va="center")
                frame = matplotlib.patches.Rectangle((j+shift, i), color=rgb[i][j], alpha=0.2, width=1, height=1)
                self.ax.add_patch(frame)
 
    def animate(self,i):
        print(i)
        self.ax.clear()
        self.ax.set_xlim(0,70)
        self.ax.set_ylim(0,70)
        self.draw(self.tabluax[10*i][0])

    def create_animation(self):
        anim = animation.FuncAnimation(self.fig, self.animate, frames=len(tabluax)//20, interval = 1000)
        anim.save('C:/result/myanimfast.gif', writer='ffmpeg')
        print('Done')
my_creater = YoungAnimation(tabluax)
my_creater.create_animation()