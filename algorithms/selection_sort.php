<?php
    include_once "library.php"; // The programe executaion will continue
                                // even if the "library.php" wasn't included
    require_once "library.php"; // In case of requiring the "library.php" file
                                // the programe will not execute if there is 
                                // an error in importing the file

    function SSort(& $list)
    {
        for ($i=0; $i < sizeof($list) ; $i++) { 
            $minValue = $list[$i];
            $minIndex = $i;
            for ($j=$i; $j < sizeof($list) ; $j++) { 
                if ($list[$j] < $minValue ) {
                    $minValue = $list[$j];
                    $minIndex = $j;
                }
            }
            if ($i !== $minIndex ) {
                replace($list[$minIndex], $list[$i]);
            }
        }
    }

    $list = array( 3, 2, 6, 5, 1, 4 );
    SSort($list);
    printArray($list);
?>