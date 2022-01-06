

const dfv = (root)=>{
  if(root === null) return []

  const leftValues = dfv(root.left)
  const rightValues = dfv(root.right) 
  return [root.val , ...leftValues,...rightValues]
}

const people = ['alphabet','meta','tesla','spacex']
const newPeople = ['alvin',...people,'michelle']
console.log(newPeople)