
const  reverseStr=(str)=>
{
    let n = str.length;

    // Swap character starting from two
    // corners
    for (let i = 0; i < parseInt(n / 2, 10); i++)
        str = swap(str,i,n - i - 1);
    return str;
}
 
const  swap = (str, i, j)=>
{
    // this line of code enables us to breakdown our string into  characters since we  need to have different characters
    let ch = str.split('');

    let temp = ch[i];
    ch[i] = ch[j];
    ch[j] = temp;
    return ch.join("");
}


console.log(reverseStr("iloveyougirl"))