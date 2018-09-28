<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title>CalculatriceGET</title>
</head>
<body>
  <h1>Calculatrice en GET</h1>
</form>
<form method="get">
  <input type="text" name="n1">
  + <input type="text" name="n2"> =
  <input type="submit" value="additionner">
</br>
<?php
$n1 = 0;
$n2 = 0;
if(isset($_GET['n2']) && isset($_GET['n1'])){
  $n1 = $_GET['n1'];
  $n2 = $_GET['n2'];
  if(is_numeric($n1) && is_numeric($n2)){
    $submit = $n1 + $n2;
    echo "<h2>le résultat est : $n1 + $n2 = $submit</h2>";
  }else{
    echo "-- please enter a numeric value --";
  }
}
?>
<br><a href="index.php">Home</a>
</body>
</html>
