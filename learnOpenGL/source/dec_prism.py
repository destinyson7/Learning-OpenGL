import numpy as np
from scipy.spatial.transform import Rotation as R

centre = [0, 0, 0]

cur_vec = [1.0, 0.0, 0.3090169943749474]

vertices = []
vertices.append(cur_vec)

for i in range(1, 10):
    rotation_degrees = 36 * i
    rotation_radians = np.radians(rotation_degrees)
    rotation_axis = np.array([0, 0, 1])

    rotation_vector = rotation_radians * rotation_axis
    rotation = R.from_rotvec(rotation_vector)
    rotated_vec = rotation.apply(cur_vec)
    vertices.append(rotated_vec)


print(np.linalg.norm(vertices[0]-vertices[1])/2)

for i in range(10):
    vertices.append([vertices[i][0], vertices[i][1], -vertices[i][2]])

for i in range(20):
    print(
        f'"{round(vertices[i][0], 10)}f, {round(vertices[i][1], 10)}f, {round(vertices[i][2], 10)}f, ",')
