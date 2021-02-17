
function sort(list) {
    for (let i = 0; i < list.length; i++) {
        for (let j = list.length - 1; j > i ; j--) {
            if (list[j-1] > list[j]) { 
                var tmp;
                tmp = list[j-1];
                list[j-1] = list[j];
                list[j] = tmp;
            }  
        }
    }    
}

(() => {
    const list = [3, 2, 4, 1, 6, 5];
    sort(list);
    console.log(list); 
})();