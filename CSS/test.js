// function fn1(){
//     let fn = () => {
//         console.log(this);
//     }
//     let ret = fn.bind(this);
//     ret();
// }
// fn1();

const { ConsoleMessage } = require("puppeteer");

let obj = new Object();
obj = {
    name : "ayush",
    f : ()=>{
        console.log(this)
    } 
};
obj.f();

function fn(name){
    console.log('Hi i am ', {name})
}
fn('ayu');

