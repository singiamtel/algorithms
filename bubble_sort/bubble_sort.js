function readArray(){
	const fs = require('fs');
	var file = fs.readFileSync('input.txt').toString('utf-8');
	let arr = file.split("\n");
	arr.pop();
	return arr;
}

function swap(arr, i, j){
	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

function bubbleSort(arr){
	for(let i=0; i<arr.length; ++i){
		for(let j=0; j<arr.length-i-1; ++j){
			if(arr[j] > arr[j+1]) swap(arr, j, j+1);
		}

	}
}

arr = readArray();
var t0 = new Date();
bubbleSort(arr);
var t1 = new Date() - t0;
console.log(arr);
console.log("Sorting took %d", t1);