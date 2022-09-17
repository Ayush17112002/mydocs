function add(a,b){
    var sum = a+b;
    function addChild(){
        console.log(sum);
    }
    return addChild;
}
var catchChild = add(2,3);
catchChild();