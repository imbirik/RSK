import matplotlib.pyplot as plt
import matplotlib.patches
import numpy as np
import os
young = [[1, 2, 3, 4], [5, 6], [7]]
x_shape = len(young)
y_shape = len(young[0])
rgb = np.zeros([x_shape, y_shape, 3])


for i in range(len(young)):
    for j in range(len(young[i])):
        rgb[i][j][0] = 255/255
        rgb[i][j][1] = 0/255
        rgb[i][j][2] = 0/255


fig, ax = plt.subplots()

for i in range(len(young)):
    for j in range(len(young[i])):
        text = ax.text(j+0.5, i+0.5, young[i][j], fontsize=20, ha="center", va="center")
        frame = matplotlib.patches.Rectangle((j, i), color=rgb[i][j], alpha=0.2, width=1, height=1)
        ax.add_patch(frame)
plt.xlim(left=0, right=y_shape+1)
plt.ylim(bottom=0, top=x_shape+1)
plt.show()
