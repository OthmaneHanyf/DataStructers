(()=>{
    list = new Array(2, 1, 5, 3, 4);
    sort(list);
    console.log(list);
})();

function sort(list) {
    for (let i = 1; i < list.length; i++) {
        let value = list[i];
        let j = i;
        while ( j > 0 && list[j-1] > value ) {
            list[j] = list[j-1];
            j--;
        }
        list[j] = value;
    }
}