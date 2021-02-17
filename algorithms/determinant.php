<?php
    // Our main programe
    $matrix = array(array(6, 3),
                    array(2, 2));
    echo det($matrix);
    // Function
    function get_sub_matrix($matrix, $n, $m)
    {
        $len = count($matrix);
        $array = array();
        $subMatrix = array();
        for ($i=0; $i < $len ; $i++) { 
            for ($j=0; $j < $len; $j++) { 
                if ($n === $i || $m === $j) {
                    continue;
                } else {
                    $array[] = $matrix[$i][$j]; 
                }
            }
            if (count($array) === 0) {
                continue;
            } else {
                $subMatrix[] = $array;
            }
        }
        return $subMatrix; 
    }

    function det($matrix)
    {
        if (!is_array($matrix)) {
            return $matrix;
        } elseif (count($matrix[0], 1) == 1) {
            return $matrix[0][0];
        } else {
            $n = count($matrix);
            $d = 0;
            for ($i=0; $i < $n; $i++) { 
                $d += pow(-1, $i)*$matrix[0][$i]*det(get_sub_matrix($matrix, 0, $i));
            }
            return $d;
        }
    }

?>