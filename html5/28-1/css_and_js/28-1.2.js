var questions = {
    index:0,
    new: function() {
        if (questions.index < questionsdb.length) {
            $(".questions span").text(questionsdb[this.index].question);
            $(".choices ul").html('');
            for (const choice of questionsdb[questions.index].choices) {
                $(".choices ul").append('<li class="snickleFritz" numberIndex="'+questionsdb[this.index].choices.indexOf(choice)+'"><h2>'+choice+'</h2></li>');
            }
            timer.start(15);
        }
        else {return;}
    }
}
var answers = {
    correct:0,
    incorrect:0,
    unanswered:0,
    markCorrect: function() {
        answers.correct++;
        $(".wins h1").text(answers.correct);
        questions.index++;
        questions.new();
    },
    markFalse: function() {
        answers.incorrect++;
        $(".losses h1").text(answers.incorrect);             
        questions.index++;
        questions.new();
    },
    markUnanswered: function() {
        answers.unanswered++;
        $(".unanswered h1").text(answers.unanswered);             
        questions.index++;
        questions.new();                             
    }
};
var timer = {
    intervalId: 0,
    running: false,
    t: 15,
    start: function(seconds) {
        if (!timer.running) {
            timer.t = seconds;
            timer.intervalId = setInterval(timer.decrement, 1000);
            timer.running = true;
        }    
    },
    decrement: function() {
        timer.t--;
        $(".timer #sec").text(timer.t);
        if (timer.t === 0) {
            timer.stop();
            answers.markUnanswered();
        }
    },
    stop: function() {
        clearInterval(timer.intervalId);
        timer.running = false;
    }    
};

$(document).on('click','.snickleFritz', function() {
    timer.stop();
    if( questions.index >= questionsdb.length ) {return;}
    var userChoice = Number($(this).attr("numberindex"));
    if (userChoice === questionsdb[questions.index].answer) {
        answers.markCorrect();
    } else {
        answers.markFalse();
    }
});

$('button').click(function() { questions.new() });

var questionsdb = [{
    question: "whats the weather?",
    choices: ["who cares", "cloudy", "eclipse"],
    answer: 0
}, {
    question: "do you like coding?",
    choices: ["getting there", "sometimes", "totally"],
    answer: 0
}, {
    question: "do you like video games?",
    choices: ["love", "hate", "sometimes"],
    answer: 0
}, {
    question: "do you like sports?",
    choices: ["yes", "sometimes", "no"],
    answer: 0
}, {
    question: "do you like food?",
    choices: ["the best", "yeah", "totally"],
    answer: 0
}];