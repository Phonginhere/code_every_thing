function myFunction() {
    var myDIV = document.getElementById("myDIV");
    var show = document.getElementById("show");
    debugger
    if (myDIV.style.display === "none") {
      document.getElementById("show").innerHTML = "Hide&uarr;"
      
      myDIV.style.display = "block";
    } else {
      document.getElementById("show").innerHTML = "Show&darr;"
      
      
      myDIV.style.display = "none";
    }
  }
function myFunction2() {
    debugger
    document.getElementsByClassName("summit")[0].disabled = !document.getElementsByClassName("summit")[0].disabled
    
}  
