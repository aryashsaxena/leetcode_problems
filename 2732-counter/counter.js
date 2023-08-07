/**
 * @param {number} n
 * @return {Function} counter
 */


var createCounter = function(n) {
    var j=0;
    return function() {
        // console.log(j," ");
        const x= n+j;
        j++;
        return x;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */