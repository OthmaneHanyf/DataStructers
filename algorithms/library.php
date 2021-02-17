<?php
    function replace(& $a ,& $b)
    {
        $tmp = $a;
        $a = $b;
        $b = $tmp;
    }
    
    function printArray($array)
    {
        echo "\n{";
        foreach ($array as $item) {
            echo " $item,";
        }
        echo "}\n";
    }
?>