

// exercise from the memoisation technique 

const fact   = (n)=>{
  if( n == 1) return 1 
  else{
    return fact(n) *  fact(n-1)
    
  }
}

console.log(fact(1));
console.log(fact(3));
// console.log(fact(5));
// console.log(fact(127));


