function run() {
    let input = document.querySelector('input').value
    if (input === "") return
    
    let content = ""
    
    if (!isNaN(input)) {
        let reverse = reverseNumber(parseInt(input))
        content = `Reverse of the given number is ${reverse}`
    } else {
        let position = leftmostVowelPosition(input)
        
        if (position != -1) {
            content = `The leftmost vowel was found at position ${position+1}`
        } else {
            
            content = `The input string does not contain any vowels`
        }
    }

    document.getElementById("output").innerHTML = content
}

function reverseNumber(num) {
    num = Math.abs(num)
    let digit = 0
    let result = 0

    while (num != 0) {
        digit = num % 10
        result = (result * 10) + digit
        num = Math.floor(num/10)
    }
    
    return result
}

function leftmostVowelPosition(str) {
    let vowels = new Set("aeiou")
    str = str.toLowerCase()
    
    for (let i = 0; i < str.length; i++) {
        if (vowels.has(str[i])) return i;
    }
    return -1
}