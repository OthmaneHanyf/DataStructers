(()=>{
    const list = new Array(4, 2, 1, 6, 5, 3);
    sort(list);
    console.log(list);
})();

function sort(list) {
    let min_value, min_index, tmp ;
    for (let i = 0; i < list.length; i++) {
        min_value = list[i];
        min_index = i;
        for (let j = i; j < list.length; j++) {
            if (list[j] < min_value) {
                min_value = list[j];
                min_index = j;
            };
        }
        if (min_index !== i) {
            tmp = list[min_index];
            list[min_index] = list[i];
            list[i] = tmp;
        }
    }
}