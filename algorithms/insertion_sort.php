<?php // Include libraries
    include_once "library.php";
?>

<?php // Functions
    function ISort(&$list)
    {
        for ( $i = 1; $i < count($list); $i++ ) { 
            $value = $list[$i];
            $j = $i;
            while ($j > 0 && $list[$j - 1] > $value) {
                $list[$j] = $list[$j - 1];
                $j--;
            }
            $list[$j] = $value;
        }
    }
?>

<?php // Main 
    $list = array(3, 1, 5, 2, 4);
    ISort($list);
    printArray($list);
?>

