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


# print(np.linalg.norm(vertices[0]-vertices[1])/2)

faces = [[0, 1, 2, 3, 4, 5, 6, 7, 8, 9], [10, 11, 12, 13, 14, 15, 16, 17, 18, 19], [1, 0, 10, 11], [2, 1, 11, 12], [3, 2, 12, 13],
         [4, 3, 13, 14], [5, 4, 14, 15], [15, 16, 6, 5], [7, 6, 16, 17], [8, 7, 17, 18], [9, 8, 18, 19], [0, 9, 19, 10]]


for i in range(10):
    vertices.append([vertices[i][0], vertices[i][1], -vertices[i][2]])

# for i in range(20):
#     print(
#         f'"{round(vertices[i][0], 10)}f, {round(vertices[i][1], 10)}f, {round(vertices[i][2], 10)}f, ",')

print(108)

for face in faces:
    color = str(round(np.random.random(), 10)) + " " + str(round(np.random.random(),
                                                                 10)) + " " + str(round(np.random.random(), 10)) + " "

    n = len(face)
    for i in range(n - 2):
        print(
            f'{round(vertices[face[i]][0], 10)} {round(vertices[face[i]][2], 10)} {round(vertices[face[i]][1], 10)} {color}')
        print(
            f'{round(vertices[face[i+1]][0], 10)} {round(vertices[face[i+1]][2], 10)} {round(vertices[face[i+1]][1], 10)} {color}')
        print(
            f'{round(vertices[face[n-1]][0], 10)} {round(vertices[face[n-1]][2], 10)} {round(vertices[face[n-1]][1], 10)} {color}')
