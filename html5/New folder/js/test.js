var selectedIndex = 0
var totalProduct = 0
function getInputProduct() {
    var name = document.getElementById("name").value
    var Genders = document.getElementsByName("Gender")
    var Gender = ""
    for(var i = 0; i < Genders.length; i++) {
        if(Genders[i].checked == true ) {
            Gender = Genders[i].value
        }
    }
    var languages  = document.getElementsByName("language")
    var checkedlanguages = []
    for(var i = 0; i < languages.length; i++) {
        if(languages[i].checked == true ) {
            checkedlanguages.push(languages[i].value)
        }
    }
    checkedlanguages = checkedlanguages.join(", ")
    return {name,Gender,checkedlanguages}
}
function addProduct() {
    var ProductTable = document.getElementById("table2")
    var newProduct = getInputProduct()
    selectedIndex++
    var row = ProductTable.insertRow(selectedIndex);
    row.id = Math.floor(Date.now())
    var cell0 = row.insertCell(0)
    cell0.innerHTML = newProduct.name

    var cell1 = row.insertCell(1)
    cell1.innerHTML = newProduct.Gender
        
    var cell2 = row.insertCell(2)
    cell2.innerHTML = newProduct.checkedlanguages
    
    var cell3 = row.insertCell(3)
    cell3.innerHTML = `<button style="text-decoration: underline; decoration: none;"
    onclick='deleteProduct("${row.id}")'>Delete</button>`
    totalProduct++;
    reloadTotalProducts()
}
function reloadTotalProducts() {
    var pTotalProduct = document.getElementById("pTotalProduct")
    TotalProduct.innerHTML = TotalProduct$;{TotalProduct}
}

function deleteProduct(timestamp) {
    debugger
    var yesOrNo = confirm("Do you want to delete ?")
    if(yesOrNo == true) {
        var ProductTable = document.getElementById("table2")
        var rows = ProductTable.rows
        for(var i = 0; i < rows.length; i++) {
            if(rows[i].id === timestamp) {
                ProductTable.deleteRow(i)
                totalProducts = totalProducts > 0 ? totalProducts-1 : totalProducts
                reloadTotalProducts()
            }
        }
        currentIndex--
    }
}