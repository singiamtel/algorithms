import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class MergeSort{
	public ArrayList<BigInteger> array;

	public void merge(ArrayList<BigInteger> data,int l,int m,int r){
		int m1 = m - l + 1;
		int m2 = r - m;

		ArrayList<BigInteger> L = new ArrayList<BigInteger>(m1);
		ArrayList<BigInteger> R = new ArrayList<BigInteger>(m2);
		
		for(int i = 0; i < m1;++i){
			L.add(data.get(l+i));
		}

		for(int i = 0; i < m2;++i){
			R.add(data.get(m+1+i));
		}
		int x = 0;
		int y = 0;
		int z = l;

		while(x < m1 && y < m2){
			if(!(L.get(x).compareTo(R.get(y)) != -1)){
				data.set(z,L.get(x));
				++x;
			}else{
				data.set(z,R.get(y));
				++y;
			}
			++z;
		}
		while(x < m1){
			data.set(z,L.get(x));
			++x;
			++z;
		}
		while(y < m2){
			data.set(z,R.get(y));
			++y;
			++z;
		}
	}
	public void mergeSort(ArrayList<BigInteger> data, int l, int r) {
		if(l < r){
			int m = (l + r) / 2;
			mergeSort(data,l,m);
			mergeSort(data,m+1,r);
			merge(data,l,m,r);
		}
	}

	public MergeSort(){
		array = new ArrayList<BigInteger>();
	}
	public static void main (String [ ] args) {
		try {
			MergeSort sort = new MergeSort();
			File input = new File("input.txt");
			Scanner scanner = new Scanner(input);

			while(scanner.hasNextBigInteger()){
				sort.array.add(scanner.nextBigInteger());
			}
			scanner.close();
			sort.mergeSort(sort.array,0,sort.array.size()-1);
			if(!sort.isSorted()){
				System.out.println("Sorting failed!");
			}
			sort.printArray();
		} catch (FileNotFoundException e) {
			System.out.println("File input.txt was not found");
			e.printStackTrace();
		}
	}

	public boolean isSorted(){
		for (int i = 0; i < array.size() - 1; i++) {
			if(array.get(i).compareTo(array.get(i+1)) == 1) return false;
		}
		return true;
	}
	public void printArray(){
		for (int i = 0; i < array.size(); i++) {
			System.out.println(array.get(i));
		}
	}
}
