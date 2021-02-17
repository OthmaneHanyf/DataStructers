from math import * 

def getSubMatrix( matrix, k, m ):

    n = len(matrix)
    subMatrix = []
    arr = []
    for i in range(n):
        for j in range(n):
            if (i == k or j == m) :
                continue
            else :
                arr.append(matrix[i][j])
        if len(arr) == 0 : 
            continue
        else :
            subMatrix.append(arr)
            arr = []
    return subMatrix

def det(matrix):
    sum = i = 0
    try :
        n = len(matrix)
    except TypeError:
        return matrix
    if (len(matrix[0]) == 1) :
        return matrix[0][0]
    for j in range(n):
        sum += pow(-1, i+j)*matrix[i][j]*det(getSubMatrix(matrix, i, j))
    return sum

print ( det([[1, 1], [1, 2]]) )