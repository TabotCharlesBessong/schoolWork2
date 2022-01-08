

class Node {
  constructor(val){
    this.val = val 
    this.left = null 
    this.right = null 
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


// iterative approach 
const treeIncludes = (root,target)=>{
  const queue = [root] 
  while(queue.length > 0){
    const cur = queue.shift()
    // console.log(cur.val);

    if(cur.val === target) return true 
    if(cur.left === null) queue.push(cur.left)
    if(cur.right === null) queue.push(cur.right)
  }
  return false 
}

module.exports = {
  treeIncludes
}

treeIncludes(a , "e") 