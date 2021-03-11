import numpy as np
from scipy.spatial.transform import Rotation as R

centre = [0.0, 0.0, 0.5]

cur_vec = [-0.3, -0.3, 0.0]

vertices = []
vertices.append(cur_vec)

for i in range(1, 11):
    rotation_degrees = (360/11) * i
    rotation_radians = np.radians(rotation_degrees)
    rotation_axis = np.array([0, 0, 1])

    rotation_vector = rotation_radians * rotation_axis
    rotation = R.from_rotvec(rotation_vector)
    rotated_vec = rotation.apply(cur_vec)
    vertices.append(rotated_vec)

vertices.append(centre)

print(len(vertices))

for i in range(11):

    color = str(round(np.random.random(), 10)) + "f, " + str(round(np.random.random(),
                                                                   10)) + "f, " + str(round(np.random.random(), 10)) + "f, "

    print(
        f'{round(vertices[11][0], 10)}f, {round(vertices[11][1], 10)}f, {round(vertices[11][2], 10)}f, {color}')

    print(
        f'{round(vertices[i][0], 10)}f, {round(vertices[i][1], 10)}f, {round(vertices[i][2], 10)}f, {color}')

    print(
        f'{round(vertices[(i+1)%11][0], 10)}f, {round(vertices[(i+1)%11][1], 10)}f, {round(vertices[(i+1)%11][2], 10)}f, {color}')
