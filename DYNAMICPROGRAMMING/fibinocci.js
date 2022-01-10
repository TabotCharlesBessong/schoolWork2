

// momoization 
// it helps us store already existing solutions 
// we will make use of  javascript objects 

const fib = (n , memo = {})=>{

  // so what we had to do here was this , 
  // to avoid wasting time  , we had to store values of solutions which already existed . 
  // we use the pass by reference property in object to do that 
  if (n in memo) return memo[n]
  // if such a solution already exist , all we had to do was to simly add it  
  if(n <=  2) return 1 
  memo[n] =   fib(n -1 ,memo) + fib(n - 2, memo)
  return memo[n] 
  // the time complexity of this approach is so high especially for very high numbers as the program has a time complexity of O(2^n)
  // so we will make use of dynamic programming  to make it more effective  
}

console.log(fib(6))
console.log(fib(4))
console.log(fib(13))
console.log(fib(20))
console.log(fib(30)) 
console.log(fib(50))
console.log(fib(943))