<?php
$page_index = 1;
if(isset($_GET['page'])){
  $page_index = $_GET['page'];
}
?>
<html lang="fr">
<head>
  <meta charset="utf-8"/>
  <title>Accueil </title>
</head>
<body>
  <?php change_page(); ?>
  <ul>
    <li><a href="calculatriceGET.php">Calculatrice en GET<a></li>
      <li><a href="calculatricePOST.php">Calculatrice en POST<a></li>
        <li><a href="calendrier.php">Calendrier<a></li>
        </ul>
        <br>
        <a href="?page=1">1</a>
        <a href="?page=2">2</a>
        <a href="?page=3">3</a>
        <a href="index.php">Home</a>
      </body>
      </html>
      <?php
      function change_page()
      {
        global $page_index;
        switch ($page_index) {
          case '1':
          include 'home.html';
          break;
          case '2':
          include 'heure.php';
          break;
          case '3':
          include 'multiplication.php';
          break;
          default:
          break;
        }
      }
      ?>
