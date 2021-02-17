<?php // Include libraries
    include_once "library.php";
?>

<?php // Functions
    function MSort(&$list)
    {
        $mid = (int)(count($list) / 2);
        if ($mid >= 1) {
            $n1 = $mid;
            $n2 = count($list) - $mid;

            for ($i=0; $i < $n1; $i++) { 
                $L[$i] = $list[$i];
            }
            echo $mid;
            for ($i = 0; $i < $n2; $i++) { 
                $R[$i] = $list[$i + $mid];
            }
            printArray($L);
            printArray($R);

            MSort($L);
            MSort($R);

            $i = 0;
            $j = 0;
            $k = 0;

            while ($i < count($L) && $j < count($R)) {
                if ($L[$i] < $R[$j]) {
                    $list[$k] = $L[$i];
                    $i++;
                } else {
                    $list[$k] = $R[$j];
                    $j++;
                }
            $k++;
            }
            while ($i < count($L)) {
                $list[$k] = $L[$i];
                $i++;$k++;
            }
            while ($j < count($R)) {
                $list[$k] = $R[$j];
                $j++;$k++;
            }
            printArray($list);
        }
    }
?>

<?php // Main
    $list = array(1, 2, 0);
    MSort($list);
    printArray($list);
?>