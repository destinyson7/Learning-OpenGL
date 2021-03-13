import math
import numpy as np

vertices = [
    "1.0f, 0.0f, 0.3090169944f, ",
    "0.8090169944f, 0.5877852523f, 0.3090169944f, ",
    "0.3090169944f, 0.9510565163f, 0.3090169944f, ",
    "-0.3090169944f, 0.9510565163f, 0.3090169944f, ",
    "-0.8090169944f, 0.5877852523f, 0.3090169944f, ",
    "-1.0f, 0.0f, 0.3090169944f, ",
    "-0.8090169944f, -0.5877852523f, 0.3090169944f, ",
    "-0.3090169944f, -0.9510565163f, 0.3090169944f, ",
    "0.3090169944f, -0.9510565163f, 0.3090169944f, ",
    "0.8090169944f, -0.5877852523f, 0.3090169944f, ",
    "1.0f, 0.0f, -0.3090169944f, ",
    "0.8090169944f, 0.5877852523f, -0.3090169944f, ",
    "0.3090169944f, 0.9510565163f, -0.3090169944f, ",
    "-0.3090169944f, 0.9510565163f, -0.3090169944f, ",
    "-0.8090169944f, 0.5877852523f, -0.3090169944f, ",
    "-1.0f, 0.0f, -0.3090169944f, ",
    "-0.8090169944f, -0.5877852523f, -0.3090169944f, ",
    "-0.3090169944f, -0.9510565163f, -0.3090169944f, ",
    "0.3090169944f, -0.9510565163f, -0.3090169944f, ",
    "0.8090169944f, -0.5877852523f, -0.3090169944f, ",
]

shape_sides = [[0, 1, 2, 3, 4, 5, 6, 7, 8, 9], [10, 11, 12, 13, 14, 15, 16, 17, 18, 19], [1, 0, 10, 11], [2, 1, 11, 12], [3, 2, 12, 13],
               [4, 3, 13, 14], [5, 4, 14, 15], [15, 16, 6, 5], [7, 6, 16, 17], [8, 7, 17, 18], [9, 8, 18, 19], [0, 9, 19, 10]]


def generate1():
    count = 0
    print("#ifndef __decagonalPrism_h__\n#define __decagonalPrism_h__")
    print("extern float vertices[] = {")
    for side in shape_sides:
        color = str(np.random.random()) + "f, " + str(np.random.random()
                                                      ) + "f, " + str(np.random.random()) + "f, "
        n = len(side)
        if n == 3:
            print(vertices[side[0]]+color)
            print(vertices[side[1]]+color)
            print(vertices[side[2]]+color)
            count += 1
            print()
        else:
            for i in range(n-2):
                print(vertices[side[i]]+color)
                print(vertices[side[i+1]]+color)
                print(vertices[side[n-1]]+color)
                count += 1
                print()
        print()
    print("};\nextern int triangleCount = " + str(count)+";\n#endif")


generate1()
