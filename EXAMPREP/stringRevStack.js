

const stringRev = (str)=>{
  let rs = ""
  for(let i = str.length - 1; i >= 0 ;i-- )
    rs += str[i]
  return rs
}

console.log(stringRev("denisnsassounguessou"))