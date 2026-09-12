class Inputarr{
    arr=[];
    arrprint=[];
    constructor(a=[""]){
        this.arrprint=a;
    }
    input(a=this.arrprint.length){
        let inp;
        for(let i=0;i<a;i++){
            inp=prompt(i<this.arrprint.length?this.arrprint[i]:"не в списку");
        this.arr.push(inp)
        }
    }
    print(){
        for(let i=0;i<this.arr.length;i++){
            alert(this.arr[i]);
        }
    }
    getarr(){
        return this.arr
    }
    getarrprint(){
        return this.arrprints
    }
}



function rangesearch(range,number,min=-1,max=range.length){
    
    if(max-min>1){
        let mid=Math.floor((max-min)/2+min)
        if(number>=range[mid]){
            return rangesearch(range,number,mid,max)
        }else{
            return rangesearch(range,number,min,mid)
        }
    }else{
    return min;
    }
}


/*for(let i=-2;i<62;i++){
    console.log(`${i} is ${rangesearch(Array(0,2,12,18,60),i)}`)
}*/

let age=parseInt(prompt("вік",18))
switch(rangesearch(Array(0,2,12,18,60),age)){
    case -1:
    alert("не народився")
    break;
    case 0:
    alert("немовля")
    break;
    case 1:
    alert("дитя")
    break;
    case 2:
    alert("підліток")
    break;
    case 3:
    alert("дорослий")
    break;
    case 4:
    alert("пенсіонер")
    break;
}


let input=parseInt(prompt("число на клавіатурі",1))
switch(input){
    case 0:
        alert(")")
        break;
    case 1:
        alert("!")
        break;
    case 2:
        alert("@")
        break;
    case 3:
        alert("#")
        break;
    case 4:
        alert("$")
        break;
    case 5:
        alert("%")
        break;
    case 6:
        alert("^")
        break;
    case 7:
        alert("&")
        break;
    case 8:
        alert("*")
        break;
    case 9:
        alert("(")
        break;
    default:
        alert("Не число на клавіатурі")
}

let money=parseInt(prompt("кількість USD",10))

let type=prompt("тип валюти(EUR,UAN,AZN)","EUR")
const EUR=0.861
const UAN=44.344
const AZN=1.699
const commision=0.01
switch(type){
    case "EUR":
    alert((1-commision)*EUR*money);
    break;
    case "UAN":
    alert((1-commision)*UAN*money);
    break;
    case "AZN":
    alert((1-commision)*AZN*money);
    break;
}



let year=parseInt(prompt("рік",300))
alert(((!Boolean(year%4) && Boolean(year%100))||!Boolean(year%400))?"Високосний":"Не високосний")


let number =parseInt(prompt("Число", 123))
number=Math.abs(number);
let lenofnumber=Math.floor(Math.log10(number));
let ispoli=Boolean(true);
for(let i=0;i<(lenofnumber+1)/2;i++){
    if(Math.floor(((number%Math.pow(10,i+1)))/Math.pow(10,i))!=Math.floor(((number%Math.pow(10,lenofnumber-i+1)))/Math.pow(10,lenofnumber-i))){
        ispoli=false;
        break;
    }
}
alert(ispoli?"Поліндром":"Не Поліндром")


let cost=parseInt(prompt("Ціна",300))

switch(rangesearch(Array(200,300,500),cost)){
    case -1:
    alert((1)*cost);
    break;
    case 0:
    alert((1-0.03)*cost);
    break;
    case 1:
    alert((1-0.05)*cost);
    break;
    case 2:
    alert((1-0.07)*cost);
    break;
}

let sq=parseFloat(prompt("Периметр квадрату",300))
let rad=parseFloat(prompt("Радиус кругу",20))
alert((sq/8.0>=rad)?"Вместиться":"Не Вместиться")

const inparr=new Inputarr(["x=1+0, answers: x=1,x=2,x=3 wrire only number","x=2+0, answers: x=1,x=2,x=3 wrire only number","x=3+0, answers: x=1,x=2,x=3 wrire only number"])
let answers=["1","2","3"]
let score=0;
inparr.input();
for(let i=0;i<inparr.getarr().length;i++){
    if(inparr.getarr()[i]==answers[i]){
        alert(`На вопрос ${i+1} ответ Правильный`)
        score+=2;
    }else{
        alert(`На вопрос ${i+1} ответ Не правильный`)
    }
}
alert(score)