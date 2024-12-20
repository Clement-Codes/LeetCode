/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let outerArgs = [];
    let id = null;

    function execute(){
        fn(...outerArgs);
        id = null;
        outerArgs = [];
    }
    return function(...args) {
        if (id != null){
            clearTimeout(id);
        }
        outerArgs = args;
        id = setTimeout(execute, t);
    }
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */