function factorial(n){
    if(n < 2) {
        return 1;
    } 
    else {
        return (n * factorial(n - 1));
    }
}

function gameProb(p,curp,curq){
    q = 1-p;
    var sum = 0
    for(var n=0;n<3-curq;n++){
        sum += Math.pow(p,4-curp) * Math.pow(q,n) * ( factorial(3-curp+n) / ( factorial(3-curp) * factorial(n)));
    }
    sum += (Math.pow(p,2)/(1-2*p*q)) * (( factorial(6-curq-curp) / ( factorial(3-curp) * factorial(3-curq))) * Math.pow(p,3-curp)*Math.pow(q,3-curq));
    return sum;
}

function netPointPercentage(servePercentage,returnPercentage){
    return servePercentage/(servePercentage+returnPercentage)
}

const tennisScores = [0,15,30,40,'A','G'];

const aServePointsWon = .69 //percentage of points a wins on serve
const aReturnPointsWon = .4 //percentage of points a wins on return
var cura = 0;
var aServe = true;

const bServePointsWon = .74 //percentage of points b wins on serve
const bReturnPointsWon = .28 //percentage of points b wins on return
var curb = 0;

if(aServe){
    console.log("A wins "+aServePointsWon+" of points on serve");
    console.log("B wins "+bReturnPointsWon+" of points on return");
    var aNetPercent = netPointPercentage(aServePointsWon,bReturnPointsWon);
    console.log("A has a "+aNetPercent+" net chance to win points on serve");
    console.log("A has a "+gameProb(aNetPercent,0,0)+" chance to win game starting at 0-0");
    console.log("\nCurrent Score");
    console.log("A is Serving");
    console.log("A   "+tennisScores[cura]+"-"+tennisScores[curb]+"   B");
    console.log("A has a "+gameProb(aNetPercent,cura,curb)+" chance to win current game");
}
else{
    console.log("B is Serving");
    console.log("B wins "+bServePointsWon+" of points on serve");
    console.log("A wins "+aReturnPointsWon+" of points on return");
    var bNetPercent = netPointPercentage(bServePointsWon,aReturnPointsWon);
    console.log("B has a "+bNetPercent+" chance to win points on serve");
    console.log("B has a "+gameProb(bNetPercent,0,0)+" chance to win game");
}

