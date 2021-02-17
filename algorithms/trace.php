<?php
    function trace($matrix)
    {
        if (!is_array($matrix)) {
            return $matrix;
        } else {
            $n = count($matrix); 
            $tr = 0;
        }
        for ($i=0; $i < $n; $i++) { 
            $tr += $matrix[$i][$i]; 
        }
        return $tr;
    }

    // $matrix = array(array(3, 2, 1),
    //                 array(4, 4, 3),
    //                 array(2, 1, 3));
    $matrix = 2;
    echo trace($matrix)."\n";
?>