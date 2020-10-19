function merge(data, l, m, r){
	var m1 = m - l + 1;
	var m2 = r - m;

	let L = new Array(m1);
	let R = new Array(m2);

	for(i = 0; i < m1;++i){
		L[i] = data[l+i];
	}
	for(i = 0; i < m2;++i){
		R[i] = data[m+1+i];
	}
	var x = 0;
	var y = 0;
	var z = l;

	while(x < m1 && y < m2){
		if(L[x] <= R[y]){
			data[z] = L[x];
			++x;
		}else{
			data[z] = R[y];
			++y;
		}
		++z;
	}
	while(x < m1){
		data[z] = L[x];
		++x;
		++z;
	}
	while(y < m2){
		data[z] = R[y];
		++y;
		++z;
	}
}

function mergeSort(data,l,r){
	if(l < r){
		var m = Math.floor((l + r) / 2);
		mergeSort(data,l,m);
		mergeSort(data,m+1,r);
		merge(data,l,m,r);
	}
}

function readArray(){
	const fs = require('fs');
	var file = fs.readFileSync('input.txt').toString('utf-8');
	let arr = file.split("\n");
	arr.pop();
	return arr;
}

arr = readArray();

var t0 = new Date();
mergeSort(arr,0,arr.length);
var t1 = new Date() - t0;

for(i = 0; i < arr.length-1;++i){
	if(arr[i] > arr[i+1]){
		throw "Array was not sorted";
	}
}
//console.log(arr);
console.log("Sorting took %d", t1);
