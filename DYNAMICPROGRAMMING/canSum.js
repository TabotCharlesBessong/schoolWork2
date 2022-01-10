

const canSum = (target , num , memo = {})=>{
  // as a  note what , you take in as key should be what directly affect the output of your functions 
  if(target in memo) return memo[target]
  if(target === 0) return true 
  if(target < 0 ) return false 

  for (let n of num){
    // console.log(n);
    const rem = target - n 
    if(canSum(rem , num , memo) === true ){
      memo[target] = true 
      return memo[target]
    }
  }
  memo[target] = false 
  return memo[target]
}

console.log(canSum(7,[2,3]));//true
console.log(canSum(7,[6,3]));// false
console.log(canSum(7,[5,3,4,7]));// true
console.log(canSum(7,[2,4]));// false
console.log(canSum(8,[2,3,5]));// true
console.log(canSum(300,[7,14]));// false
