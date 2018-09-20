<html lang="fr">
<head>
<meta charset="utf-8"/>
<title>Accueil </title>
</head>
  <body>
<h1>Accueil</h1>
<a href="index.php?n=1">1</a>
<a href="index.php?n=2">2</a>
</body>
</html>

<?php
function page1()
{
  include 'backhome.html';
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
<?php
function page2()
{
  include 'backhome.html';
echo "Il est ".date('H:i:s');
echo "\n";
}
?>
