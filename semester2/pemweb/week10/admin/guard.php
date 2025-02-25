<?php

session_start();
if ($_SESSION["user_logged"] != true)
  header('Location: signin.php');
