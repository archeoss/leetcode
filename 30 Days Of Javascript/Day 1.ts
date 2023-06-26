/**
 * @return {Function}
 */
const createHelloWorld = function () {
  return function (..._args: string[]) {
    return "Hello World";
  };
};

const f = createHelloWorld();
console.log(f()); // "Hello World"
