
function tr(matrix) {
    let s = 0;
    const n = matrix.length ;
    if( !isNaN(matrix) ) return matrix;
    for (let i = 0; i < n; i++) {
        s += matrix[i][i] ;
    }
    return s;
}

console.log(tr([[1, 2], [3, 1]]));