function curry(fn) {
  return function curried(...args) {
    if (args.length >= fn.length) {
      return fn.apply(this, args);
    } else {
      return function (...args2) {
        return curried.apply(this, args.concat(args2));
      };
    }
  };
}

function sum(a, b, c, d) {
  return a + b + c + d;
}

let curriedSum = curry(sum);
curriedSum(1, 2, 3)(4);
curriedSum(1)(2)(3, 4);
