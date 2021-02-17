(()=>{
    const list = [2, 1, 4, 0, 3];
    sort(list);
    console.log(list); 
})();

function sort(list) {
    mid = list.length / 2 ;
    if (mid >= 1) {
        const L = list.slice(0, mid);
        const R = list.slice(mid);

        sort(L);
        sort(R);

        let i = 0,j = 0, k = 0; 
        while (i < L.length && j < R.length) {
            if (L[i] < R[j]) {
                list[k] = L[i];
                i++;
            } else {
                list[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < L.length) {
            list[k] = L[i];
            i++;k++; 
        }
        while (j < R.length) {
            list[k] = R[j]; 
            j++;k++; 
        }
    }    
}