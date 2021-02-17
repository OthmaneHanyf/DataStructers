
function getSubMatrix(matrix, k, m){
    const n = matrix.length;
    const subMatrix = new Array();
    let arr = new Array();
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (i === k || j === m) {
                continue;
            } else {
                arr.push(matrix[i][j]);
            } 
        }
        if (arr.length === 0) continue;
        else {
            subMatrix.push(arr);
            arr = new Array();
        }
    }
    return subMatrix;
}

function det(matrix) {
    let sum = 0, i = 0;
    const n = matrix.length;
    if( !isNaN(matrix) ) return matrix;
    if( matrix[0].length === 1 ) return matrix[0][0] ; 
    for (let j = 0; j < n; j++) {
        sum += Math.pow(-1, i+j)*matrix[i][j]*det(getSubMatrix(matrix, i, j));
    } 
    return sum;
}

console.log(det([[1, 1], [1, 2]]));
