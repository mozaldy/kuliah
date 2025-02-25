var count = 0;

function button() {
  count++;
  var h2 = document.getElementById("count");
  h2.innerHTML = count;
  heading_color();
}

function heading_color() {
  var btn = document.getElementById("heading");
  if (btn.style.color == "red") {
    btn.style.color = "blue";
  } else {
    btn.style.color = "red";
  }
}
