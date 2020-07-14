var currentIndex = 0
var totalStudents = 0
function getStudentInfo() {
    var name = document.getElementById("name").value
    var dob = document.getElementById("dob").value
    var genders = document.getElementsByName("gender")
    var gender = ""
    for(var i = 0; i < genders.length; i++){
        if(genders[i].checked == true) {
            gender = genders[i].value
        }
    }
    var languages =document.getElementsByName("language")
    var checkedLanguages = []
    for(var i = 0; i < languages.length; i++){
        if(languages[i].checked == true) {
            checkedLanguages.push(languages[i].value)
        }
    }
    checkedLanguages = checkedLanguages.join(", ")
    var classNames = document.getElementById("className").options
    var className = ""
    for(var i = 0; i < classNames.length; i++){
        if(classNames[i].selected == true) {
            className = classNames[i].value
        }
    }
    return {name,dob, gender, checkedLanguages, className}
}
function addStudent() {
    
    var newStudent = getStudentInfo()   
    currentIndex++ 
    insertToStudentTable(newStudent)
}

function insertToStudentTable(student) {
    var studentTable = document.getElementById("table2")
    var row = studentTable.insertRow(currentIndex)
    row.id = Math.floor(Date.now())

    var cell0 = row.insertCell(0)
    cell0.innerHTML = student.name

    var cell1 = row.insertCell(1)
    cell1.innerHTML = student.className

    var cell2 = row.insertCell(2)
    cell2.innerHTML = student.dob

    var cell3 = row.insertCell(3)
    cell3.innerHTML = student.gender

    var cell4 = row.insertCell(4)
    cell4.innerHTML = student.checkedLanguages

    var cell5 = row.insertCell(5)
    cell5.innerHTML = `<button style="text-decoration: underline; decoration: none;"
            onclick='deleteStudent("${row.id}")'>Delete</button>`
    totalStudents++;
    var countStudent = document.getElementById("countStudent")
    countStudent.innerText = totalStudents
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
                //totalStudents = totalStudents > 0 ? totalStudents - 1 : totalStudents
                totalStudents--
                var countStudent = document.getElementById("countStudent")
                countStudent.innerHTML = totalStudents
            }
        }
        currentIndex--
    }
}
var classNames = ["C1798G1", "C135G2"]
function addNewClass() {
    var newClassName = prompt("Enter your new class name: ", "")
    if(newClassName.trim() === "") {
        alert("Cannot insert a blank name !")
        return
    }
    classNames.push(newClassName)
    var className = document.getElementById("className")
    var option = document.createElement("option")
    option.innerHTML = newClassName
    className.add(option)
}
function reloadClassNames() {
    var className = document.getElementById("className")
    for (var i = 0; i < classNames.length; i++) {
        var eachClass = classNames[i]
        var option = document.createElement("option")
        option.innerHTML = eachClass
        className.add(option)
    }
}