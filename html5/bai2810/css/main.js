function login() {
    const email = document.getElementById("email").value
    const password = document.getElementById("password").value    
    if(email == "hoang@gmail.com" && password == "123456") {
        alert("Dang nhap thanh cong")
    } else {
        alert("Dang nhap that bai")
    }    
   //alert(JSON.stringify(mobiles))
}