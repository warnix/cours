<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title>CalculatricePOST</title>
</head>
<body>
  <h1>Calculatrice en POST</h1>
</form>
<form method="post">
  <input type="text" name="n1">
  + <input type="text" name="n2"> =
  <input type="submit" value="additionner">
</br>
<?php
$n1 = 0;
$n2 = 0;
if(isset($_POST['n1']) && isset($_POST['n2'])){
  $n1 = $_POST['n1'];
  $n2 = $_POST['n2'];
  if(is_numeric($n1)&&is_numeric($n2)){
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
