<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <title>Document</title>
</head>
<body>
<?php
include 'backhome.html';
echo "Mutiplication";
createGrill();
?>
</body>
</html>


<?php
function createGrill()
{
  echo "<table> ";
  for($i = 1; $i <= 10;$i++){
    echo "<tr>";
    for($j = 1; $j <= 10;$j++){
      echo "<td>";
      echo $i*$j;
      echo "</td>";
    }
    echo "</tr>";
  }
  echo "</table>";
}
?>