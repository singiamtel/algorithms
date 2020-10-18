function readArray(){
	const fs = require('fs');
	var file = fs.readFileSync('input.txt').toString('utf-8');
	let arr = file.split("\n");
	arr.pop();
	return arr;
}

arr = readArray();
var t0 = new Date();

// Sort here

var t1 = new Date() - t0;
console.log(arr);
console.log("Sorting took %d", t1);