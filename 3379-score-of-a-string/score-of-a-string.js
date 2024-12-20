/**
 * @param {string} s
 * @return {number}
 */
var scoreOfString = function(s) {
    let result = 0;
    for (let i = 0; i < s.length - 1; i++){
        result += Math.abs(s[i].charCodeAt(0) - s[i + 1].charCodeAt(0));
    }
    return result;
};