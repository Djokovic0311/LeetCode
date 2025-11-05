/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
  let val = this.pop();
  return val !== undefined ? val : -1;    
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */
