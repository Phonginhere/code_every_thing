var selectedIndex = 0
var totalStudents = 0
function getInputStudent() {
    var name = document.getElementById("name").value
    var dob = document.getElementById("dob").value
    var genders  = document.getElementsByName("gender")
    var gender = ""
    for(var i = 0; i < genders.length; i++) {
        if(genders[i].checked == true ) {
            gender = genders[i].value
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
    var classNames = document.getElementById("className").options
    var className = ""
    for(var i = 0; i < classNames.length; i++) {
        if(classNames[i].selected == true ) {
            className = classNames[i].value
        }
    }
    
    return {name, dob,gender,checkedlanguages,className}
}
function addStudent() {
    var studentTable = document.getElementById("table2")
    var newStudent = getInputStudent()
    selectedIndex++
    var row = studentTable.insertRow(selectedIndex);
    row.id = Math.floor(Date.now())
    var cell0 = row.insertCell(0)
    cell0.innerHTML = newStudent.name

    var cell1 = row.insertCell(1)
    cell1.innerHTML = newStudent.className

    var cell2 = row.insertCell(2)
    cell2.innerHTML = newStudent.dob

    var cell3 = row.insertCell(3)
    cell3.innerHTML = newStudent.gender
        
    var cell4 = row.insertCell(4)
    cell4.innerHTML = newStudent.checkedlanguages
    
    var cell5 = row.insertCell(5)
    cell5.innerHTML = `<button style="text-decoration: underline; decoration: none;"
            onclick='deleteStudent("${row.id}")'>Delete</button>`
    totalStudents++;
    reloadTotalStudents()
}
function reloadTotalStudents() {
    var pTotalStudents = document.getElementById("pTotalStudents")
    pTotalStudents.innerHTML = `Total students : ${totalStudents}`
}

function deleteStudent(timestamp) {
    var yesOrNo = confirm("Do you want to delete ?")
    if(yesOrNo == true) {
        var studentTable = document.getElementById("table2")
        var rows = studentTable.rows
        // debugger
        for(var i = 0; i < rows.length; i++) {
            // debugger
            if(rows[i].id === timestamp) {
                studentTable.deleteRow(i)
                totalStudents = totalStudents > 0 ? totalStudents-1 : totalStudents
                reloadTotalStudents()
            }
        }
        currentIndex--
    }
}
var classNames = ["C1980G2", "C1704G1"]
function checkClassExist(className) {
    for(eachClass of classNames) {
        if(eachClass === className) {
            return true
        }
    }
    return false
}
function addClass() {
    var newClassName = prompt("Enter your new class name ?", "")
    if(newClassName.trim() === "") {
        alert("Class name must not be blank !")
        return
    }
    if(checkClassExist(newClassName) == true) {
        alert("Class name exists, please choose another !")
        return
    }

    classNames.push(newClassName)
    var classes = document.getElementById("className")
    var option = document.createElement("option");
    option.text = newClassName
    option.value = newClassName
    classes.add(option)
}
function fetClassDataToUI() {
    var classes = document.getElementById("className")
    for(className of classNames) {
        var option = document.createElement("option");
        option.text = className
        option.value = className
        classes.add(option)
    }
}