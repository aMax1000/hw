function printontrue(string1, bool){
    let stringnew="";
    //stringnew.length=0
    for(let i=0;i<string1.length;i++){
        //stringnew.length+=Boolean(bool*string1.charCodeAt(i))
        const magicsymbol =8203 //U+200B
        stringnew+=String.fromCharCode(bool*string1.charCodeAt(i)+!bool*8204)
        /*console.log(string1.charCodeAt(i))
        console.log(bool*string1.charCodeAt(i))
        console.log(String.fromCharCode(bool*string1.charCodeAt(i)))
        console.log(stringnew[i])*/
    }
    return stringnew
}


/*let str=""
for(let i=8200;i<10000;i++){
    
    str+=(i)+"\""+String.fromCharCode(i)+"\" "
}
alert(str)*/


let name = prompt("Имя?", "боба")
alert("Привет, " + name)
const year=2026
let yearofbirth = parseInt(prompt("Год Рождения", 1999))
alert(year-yearofbirth)
let sqlen = parseInt(prompt("Длинна сторони квадрата", 10))
alert((4*sqlen))
const pi=3.14
let sphererad = parseInt(prompt("Радиус сферы", 10))
alert((sphererad**2)+"π")
let distance =-1
while(distance<0){
distance = parseInt(prompt("Дистанция в км, должна быть больше 0", 10))
}
let time =-1
while(time<0){
time = parseInt(prompt("Время, должно быть больше 0", 10))
}
alert((distance/time))
const exchange = 1.16
const commition =0.01
let dollar =parseInt(prompt("Обмен долларов в евро, коммисия 1%", 10))
alert(((1-commition)*dollar/exchange))
let volume =parseInt(prompt("Размер флешки в ГБ", 10))
alert(Math.floor(volume/0.82))
let sum =-1
while(sum<0){
sum = parseInt(prompt("Деньги на счету, должно быть больше 0", 10))
}
let price =-1
while(price<0){
price = parseInt(prompt("Цена шоколадки, должно быть больше 0", 10))
}
alert(Math.floor(sum/price)+" сдача: "+sum%price)
let number =parseInt(prompt("Число", 123))
let sign=Math.sign(number)
number=sign*number;
let lenofnumber=Math.floor(Math.log10(number));
let output=0;
for(let i=0;i<lenofnumber+1;i++){
    output+=Math.floor((number%Math.pow(10,i+1))/Math.pow(10,i))*Math.pow(10,lenofnumber-i)
}
alert(output)
let wholenumber =parseInt(prompt("Целое Число", 123))
alert(printontrue("Это Число Четное",!Boolean(wholenumber%2))+printontrue("Это Число Не Четное",Boolean(wholenumber%2)))