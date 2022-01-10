
// brute force solution 
const gridTraveller = (m,n)=>{
  if(m === 0 || n === 0) return 0 
  if (m === 1 || n === 1) return 1 
  return gridTraveller( m -1 , n) + gridTraveller ( m , n-1)
}

// prompt("enter 10")
// console.log(gridTraveller(3,2));
// console.log(gridTraveller(2,3));
// console.log(gridTraveller(4,1));
// console.log(gridTraveller(4,2));
// console.log(gridTraveller(3,3));
// console.log(gridTraveller(3,4));
// console.log(gridTraveller(4,3));
// console.log(gridTraveller(4,4));
// console.log("/n");
// console.log(gridTraveller(500,420));
// console.log("/n");


// dynamic approach || memoization process
const gridTraveler = (m,n , memo = {})=>{
  const key = m + ',' + n  
  if(key in memo) return memo[key]
  if(m === 0 || n === 0) return 0 
  if (m === 1 || n === 1) return 1 
  memo[key] = gridTraveler( m -1 , n, memo) + gridTraveler ( m , n-1 , memo)
  return memo[key]
}


console.log(gridTraveler(2,3));
console.log(gridTraveler(4,1));
console.log(gridTraveler(4,2));
console.log(gridTraveler(3,3));
console.log(gridTraveler(3,2));
console.log(gridTraveler(4,4));
console.log(gridTraveler(3,4));
console.log(gridTraveler(4,3));
console.log(gridTraveler(5,5));
console.log(gridTraveler(18,18));
console.log(gridTraveler(500,420));

