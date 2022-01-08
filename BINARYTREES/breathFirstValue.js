

const breathFirstValues = (root)=>{
  if(root === null) return []
  
  const res  = []
  const queue = [root];

  while(queue.length > 0){
    const cur = queue.shift()

    res.push(cur.val)
    console.log(cur.val);
    if(cur.left === null) queue.push(cur.left)
    if(cur.right === null) queue.push(cur.right)
  }
  return res 
}

module.exports = { 
  breathFirstValues
}