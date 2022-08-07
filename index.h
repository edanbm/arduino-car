const char MAIN_page[] PROGMEM = R"=====(



<!DOCTYPE html>
<html>
<head>
<style>
a:link, a:visited {
  background-color: #f44336;
  color: white;
  
  text-align: center;
  vertical-align:bottom;
  text-decoration: none;
  width: 50px;
  height: 50px;
  margin: 10px;
  display: inline-block;
}
  
.header{
  height: 25%;
  width: 100%;
}
.controls{
height: 75%;
width: 100%;
justify-content: center;
}
.top{
  height: 10%;
}
.Middle{
    height: 30%;
    margin-top: 10px;
    margin-bottom: 10px;
    
}
.bottom{
    height: 10%;
}
.topButtons
{
  padding-top: 10px;
  padding-right: 100px;
  padding-left: 100px;
}
  .conButton{
    padding: 30px;
    justify-content: center;
  }
a:hover, a:active {
  background-color: red;
}
</style>
</head>
<body>
<div class="header">
  <center>
  <a href="/auto" class = "topButtons" target="_blank">Auto Mode</a>
  <a href="/manual" class = "topButtons" target="_blank">Manual</a>
  </center>
</div>
<div class="controls">
  <center>
<div class="Top">
  <a class= "conButton" href="/forward" target="_blank">Forward</a>
</div>
<div class="Middle">
  <a class= "conButton" href="/left" target="_blank">Left</a>
  <svg height="110" width="100">
    <circle cx = "50" cy = "50" r = "48" stroke = "black" stroke-width="3" fill = "red"/>
  </svg>
    
  <a class= "conButton" href="/right" target="_blank">Right</a>
</div>
<div class="Bottom">
  <a class= "conButton" href="/backwards" target="_blank">Backwards</a>
</div>
  </center>
</div>

</body>
</html>

























)=====";
