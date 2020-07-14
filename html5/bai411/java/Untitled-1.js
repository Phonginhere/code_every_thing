var songs = [
    {
        name:'Lai may bay',
        year: 2019,
        author: 'Binh Gold'
    },{
        name:'Boc bat ho',
        year: 2018,
        author: 'Binh Gold'
    },{
        name:'Abc xyz',
        year: 2017,
        author: '1234'
    },{
        name:'Em gi oi',
        year: 2019,
        author: 'K-ICM'
    },
];

function sortByType(type) {
    songs = songs.sort(function(s1, s2){
        if(type == "Name") {
            return s1.name > s2.name ? 1 : -1;
        } else if(type == "Year") {
            return s1.year - s2.year
        } else {
            return s1.author > s2.author ? 1 : -1;
        }
    });
}
console.log(`songs = ${JSON.stringify(songs)}`);

function showAllSongs(){
    var tblSongs = document.getElementById("tblSongs");
    tblSongs.innerHTML = "";
    for(var i =  0; i < songs.length; i++) {
        var song = songs[i];
        var row = tblSongs.insertRow();
        var cell0 = row.insertCell(0);
        cell0.innerHTML = song.name;
    
        var cell1 = row.insertCell(1);
        cell1.innerHTML = song.year;
    
        var cell2 = row.insertCell(2);
        cell2.innerHTML = song.author;
    }
}
function changeSortType() {
    var type = document.getElementById("chooseSort").value;
    //alert("Ban chon :"+type);
    sortByType(type);
    showAllSongs();
}
showAllSongs();