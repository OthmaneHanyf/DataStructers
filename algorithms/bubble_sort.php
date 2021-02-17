<?php
    include_once "library.php";

    function BSort(& $list)
    {
        for ($i=0; $i < sizeof($list) ; $i++) { 
            for ($j=sizeof($list) - 1; $j > $i ; $j--) { 
                if ($list[$j-1] > $list[$j]) {
                    replace($list[$j-1], $list[$j]);
                }
            }
        }
    }

    $list = array( 3, 2, 6, 5, 1, 4 );
    BSort($list);
    printArray($list);
?>