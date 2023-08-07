/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe(val1){
        if(val1===val){
            return true;
        }
        else{
          throw Error("Not Equal"); 
        }
        },
        notToBe(val1){
            if(val1===val){
                throw Error("Equal");
            }
            else return true;
        }
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */