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
function stringcreator(a="",b=0){
    output=[];
    temp="";
    let indexofop=0;
    for(let i=0;i<b;i++){
        temp=a;
        while(true){
            indexofop=temp.indexOf("^")
            if(indexofop!=-1){
                break;
            }
            temp=temp.slice(0,index)+String(i)+temp.slice(index+1)
        }
        output.push(temp)
    }
}


/*let sum=0
let input="0"
while(input!="нет"){
    sum+=parseInt(input);
    input=prompt("number to add","нет")
}
alert(sum)*/
function task1(){
    let start
    start=parseInt(prompt("початок диапозону"))
    let stop
    stop=parseInt(prompt("Кінец диапозону"))
    let strarr=[]
    if(stop<start){
        alert("error")
        return
    }
    for(let i=0;i<stop-start;i++){
        strarr.push(`вставьте ${i+start} элемент`)
    }
    const inparr=new Inputarr(strarr)
    inparr.input()
    let sum=0;
    for(let i=0;i<inparr.getarr().length;i++){
        let temp=inparr.getarr()[i]
        sum+=parseInt(temp)
    }
    alert(sum)
}
function task2(){
    const inparr=new Inputarr([
    "1 элемент", 
    "2 элемент", 
    "3 элемент", 
    "4 элемент", 
    "5 элемент", 
    "6 элемент", 
    "7 элемент", 
    "8 элемент", 
    "9 элемент", 
    "10 элемент", 
    ])
    inparr.input()
    let possum=0;
    let negsum=0;
    let zerosum=0;
    for(let i=0;i<inparr.getarr().length;i++){
        let temp=inparr.getarr()[i]
        if(temp>0){
            possum++
        }else if(temp<0){
            negsum++
        }else{
            zerosum++
        }
    }
    alert(possum)
    alert(negsum)
    alert(zerosum)
}
task1()
task2()