import numpy as np
from scipy.spatial.transform import Rotation as R

cur_vec = [-0.3, -0.3, 0.0]

vertices = []
vertices.append(cur_vec)

for i in range(1, 6):
    rotation_degrees = 60 * i
    rotation_radians = np.radians(rotation_degrees)
    rotation_axis = np.array([0, 0, 1])

    rotation_vector = rotation_radians * rotation_axis
    rotation = R.from_rotvec(rotation_vector)
    rotated_vec = rotation.apply(cur_vec)
    vertices.append(rotated_vec)


up_centre = [0.0, 0.0, 0.4]
down_centre = [0.0, 0.0, -0.4]
vertices.append(up_centre)
vertices.append(down_centre)

# print(len(vertices))

print(36)

for i in range(6):

    color = str(round(np.random.random(), 10)) + " " + str(round(np.random.random(),
                                                                 10)) + " " + str(round(np.random.random(), 10)) + " "

    print(
        f'{round(vertices[6][0], 10)} {round(vertices[6][2], 10)} {round(vertices[6][1], 10)} {color}')

    print(
        f'{round(vertices[i][0], 10)} {round(vertices[i][2], 10)} {round(vertices[i][1], 10)} {color}')

    print(
        f'{round(vertices[(i+1)%6][0], 10)} {round(vertices[(i+1)%6][2], 10)} {round(vertices[(i+1)%6][1], 10)} {color}')

for i in range(6):

    color = str(round(np.random.random(), 10)) + " " + str(round(np.random.random(),
                                                                 10)) + " " + str(round(np.random.random(), 10)) + " "

    print(
        f'{round(vertices[7][0], 10)} {round(vertices[7][2], 10)} {round(vertices[7][1], 10)} {color}')

    print(
        f'{round(vertices[i][0], 10)} {round(vertices[i][2], 10)} {round(vertices[i][1], 10)} {color}')

    print(
        f'{round(vertices[(i+1)%6][0], 10)} {round(vertices[(i+1)%6][2], 10)} {round(vertices[(i+1)%6][1], 10)} {color}')
