function checkAnswerMC(event, isCorrect) {
    let feedback = document.getElementById("mc-feedback");
    if (isCorrect) {
        event.target.style.backgroundColor = "#5ce47d";
        feedback.textContent = "Correct!";
    } else {
        event.target.style.backgroundColor = "#f4005e";
        feedback.textContent = "Incorrect";
    }
}

function checkAnswerFR() {
    const correctAnswer = "H2O";
    let inputField = document.getElementById("fr-input");
    let feedback = document.getElementById("fr-feedback");

    if (inputField.value.toUpperCase() === correctAnswer) {
        inputField.style.backgroundColor = "#5ce47d";
        feedback.textContent = "Correct!";
    } else {
        inputField.style.backgroundColor = "#f4005e";
        feedback.textContent = "Incorrect";
    }
}