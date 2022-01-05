
// const {dfv} = require("./depthFirstSearch")
// import depthFirstValue from "./depthFirstValue"

class Node {
  constructor(val){
    this.val = val 
    this.left = null 
    this.right = null 
  }
}

// console.log(a.left);
// console.log(a.right);

// const depthFirstValue = (root)=>{
  // 
// }

const depthFirstValue = (root)=>{
  const stack = [root] 
  while(stack.length > 0){
    const current = stack.pop()
    console.log(current.val);
    if(current.left) stack.push(current.left)
    if(current.right) stack.push(current.right)
    if(current.left) stack.push(current.left)
  }
}

const a = new Node('a')
const b = new Node('b')
const c = new Node('c')
const d = new Node('d')
const e = new Node('e')
const f = new Node('f')

a.left = b
a.right = c
b.left = d
b.right = e 
c.left = f 

// module.exports = { 
  // depthFirstValue
// }

depthFirstValue(a)
// dfv(a)