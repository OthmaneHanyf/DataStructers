def tr(matrix):

    try:
        n = len(matrix)
    except TypeError :
        return matrix
    s = 0
    for i in range(n):
        s += matrix[i][i]
    return s

print(tr([[1, 1], [3, 1]]))