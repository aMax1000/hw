let age = parseInt(prompt("Число", 10))
alert(age ** 2)
let num1 = parseInt(prompt("Число11", 10))
let num2 = parseInt(prompt("Число12", 10))
alert((num1 + num2) / 2)
let sq = parseInt(prompt("Длинна квадрата", 10))
alert(sq ** 2)
const conm = 0.621371
let km = parseInt(prompt("длинна в км", 10))
alert("длинна в милях " + conm * km)
let num3 = parseInt(prompt("Число21", 10))
let num4 = parseInt(prompt("Число22", 10))
alert((num3 + num4))
alert((num3 - num4))
alert((num3 * num4))
if (num4 != 0) {
    alert((num3 / num4))
} else {
    alert("ділення на 0 неможливо")
}
let num5 = parseInt(prompt("Число31", 10))
let num6 = parseInt(prompt("Число32", 10))
alert((-num6 / num5))
let hour=-1
while (hour > 24 || hour < 0) {
    hour = parseInt(prompt("Часы, должны быть между 0 и 24", 10))
}
let min=-1
while (min > 60 || min < 0) {
    min = parseInt(prompt("минуты, должны быть между 0 и 60", 10))
}
alert("до нового дня осталось "+(24-hour)+" часов и "+(60-min)+" минут")
let num7=-1
while (num7 > 1000 || num7 < 100) {
    num7 = parseInt(prompt("Число, должны быть 3 значным", 100))
}
alert(((parseInt(num7/10))%10))
let num8=-1
while (num8 > 100000 || num8 < 10000) {
    num8 = parseInt(prompt("Число, должны быть 5 значным", 10000))
}
alert((parseInt(num8/10)+(num8%10)*10000))
let sell = parseInt(prompt("продажи", 10))
alert((250+sell/10))