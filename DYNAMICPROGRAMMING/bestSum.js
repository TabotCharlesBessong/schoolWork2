

const bestSum = (target,array)=>{
  if(target === 0 ) return []
  if(target < 0) return null 

}


console.log(bestSum(8,[2,3,5,7]));
console.log(bestSum(7,[2,3,5,7]));
console.log(bestSum(7,[2,4]));
console.log(bestSum(13,[2,4,5,8,7]));
console.log(bestSum(8,[1,,4,5]));
console.log(bestSum(237,[3,45,23,67,100]));
console.log(bestSum(100,[1,2,5,25]));
console.log(bestSum(300,[7,14]));