/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var x=init;
    return{
        increment(){
            return x=x+1;
        },
        reset(){
            return x=init;
        },
        decrement(){
            return x=x-1;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */