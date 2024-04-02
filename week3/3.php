<!DOCTYPE html>
<html>

<body>
  <?php
  function writeMsg()
  {
    echo "Hello world!";
  }
  writeMsg();
  ?>
</body>

</html>
<!DOCTYPE html>
<html>

<body>
  <?php
  function familyName($fname)
  {
    echo "$fname Refsnes.<br>";
  }
  familyName("Bejo");
  familyName("Painem");
  familyName("Rudi");
  familyName("Paijo");
  familyName("Alex");
  ?>
</body>

</html>
<!DOCTYPE html>
<html>

<body>
  <?php
  function setHeight($minheight = 50)
  {
    echo "The height is : $minheight <br>";
  }
  setHeight(350);
  setHeight();
  setHeight(135);
  setHeight(80);
  ?>
</body>

</html>
