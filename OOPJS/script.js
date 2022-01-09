

// alert("hello dude")

// OBJECT literals 
// const circle = {
  // radius:1,
  // location:{
    // x:1,
    // y:1
  // },
  // draw: function() {
    // console.log('hello ');
  // }
// };
// 
// circle.draw()

// factories  functions 
// const createCircle = (radius)=>{
  // return {
    // radius,
    // draw : ()=>{
      // console.log('Hello dude')
    // }
  // };
// }
// 
// const circle = createCircle(1)
// circle.draw()

// constructor 

function Circle  (radius){
  // console.log(this, 'this');
  this.radius = radius 
  // this is abstraction , we are tryng  to hide the complexity of our program and only showing the essentials 
  let defaultLoc = {x:0, y:0}
  // let computeOptLoc = (factor)=>{

  // }

  this.getLoc = ()=>{
    return defaultLoc 
  }
  this.draw = ()=>{
    // computeOptLoc(0.15) 
    console.log('Hello men ')
  }
  Object.defineProperty(this , 'defaultLoc',{
    get: ()=>{
      return defaultLoc 
    }
  })
}

const cir = new Circle(1) 
// cir.getLoc()
// cir.computeOptLoc(0.25)
cir.draw() 

// so how do we access  hidden variables in javascript 
// well we will use getters and setters 

// cir.location = {y:20}
// cir['location'] = { y : 23}

// delete cir['location']
// delete cir.location

// for(let key in cir) {
  // console.log(key, cir[key])
// }


// function rect (width)

// function Circle (radius){
  // this.radius = radius 
  // this.draw = ()=>{
    // console.log('draw')
  // }
// }
// 
// Circle.call({} , 1)
// 
// const another = new Circle(1)



// reference type values 
// let x = {value:20}
// let y = x 
// x.value = 30 
// 
// console.log(x.value , y.value);

// primitive values  
// let x = 20
// let y = x 
// x = 30 
// 
// console.log(x , y)