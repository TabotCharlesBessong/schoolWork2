

const howSum = (target,array, memo={})=>{
  if(target in memo) return memo[target]
  if(target === 0) return []
  if(target < 0) return null 

  for(let num of array){
    const rem = target - num 
    const res = howSum(rem,array,memo)
    if(res !== null){
      memo[target] = [...res,num]
      return memo[target]
    }
  }
  memo[target] = null
  return null 
}


console.log(howSum(8,[2,3,5,7]));
console.log(howSum(7,[2,3,5,7]));
console.log(howSum(7,[2,4]));
console.log(howSum(13,[2,4,5,8,7]));
console.log(howSum(237,[3,45,23,67,100]));
console.log(howSum(300,[7,14]));
// console.log(8,[2,3,5,7]);