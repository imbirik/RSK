
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

fig = plt.figure()
ax = plt.axes(xlim=(0, 10), ylim=(0, 10))

def draw(tableau, shift=0):
    global fig, ax
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
            ax.text(j+shift+0.5, i+0.5, text, fontsize=20, ha="center", va="center")
            frame = matplotlib.patches.Rectangle((j+shift, i), color=rgb[i][j], alpha=0.2, width=1, height=1)
            ax.add_patch(frame)
    
def animate(i):
    print(i)
    global tabluax
    global fig, ax
    ax.clear()
    ax.set_xlim(0,70)
    ax.set_ylim(0,70)
    draw(tabluax[10*i][0])
anim = animation.FuncAnimation(fig, animate, frames=len(tabluax)//10, interval = 100)
plt.show()
anim.save('C:/result/myanimfast.gif', writer='ffmpeg')
print('Done')