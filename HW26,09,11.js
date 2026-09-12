function factorial(a){
    if(a>1){
        return a*factorial(a-1)
    }else{
        return 1
    }
}


let input=prompt("строка","#43#")
let sum=0;
for(let i=0;i<input.length;i++){
    if(input[i]=='#'){
        sum++
    }
}
alert(sum)

let num=parseInt(prompt("число",2))
for(let i=num;i<=0;i++){
    alert(i)
}
let num2=parseFloat(prompt("число для степени",2))
let num3=parseFloat(prompt("степень",2))
alert(Math.pow(num2,num3))

let num4=parseInt(prompt("число для разложения 1",2))
let num5=parseInt(prompt("число для разложения 2",2))
const num4divset=new Set
const num5divset=new Set
const numsdivset=new Set
let maximumsq=Math.sqrt(Math.max(num4,num5))
let is1numdiv=Boolean(false)
for(let i=2;i<maximumsq;i++){
    if(!Boolean(num4%i)){
    is1numdiv=true
    num4divset.add(i)

    num4divset.add(Math.round(num4/i))
        if(num5divset.has(Math.round(num4/i))){
            numsdivset.add(Math.round(num4/i))
        }
    }


    if(!Boolean(num5%i)){
        num5divset.add(i)
        if(is1numdiv){
            numsdivset.add(i)
        }
        num5divset.add(Math.round(num5/i))

        if(num4divset.has(Math.round(num5/i))){
            numsdivset.add(Math.round(num5/i))
        }
    }
    is1numdiv=false
}
console.log(num4divset)
console.log(num5divset)
console.log(numsdivset)
alert("check console")

let num6=parseInt(prompt("число для факториала",4))
alert(factorial(num6))

let num7=-1
do{
num7=parseInt(prompt("ответ на 2+2*2"))
}while(num7!=6);

let numdiv=1000;
let itt=0;

itt=Math.ceil(Math.log2(numdiv/50))
alert(itt)
alert(numdiv/Math.pow(2,itt))