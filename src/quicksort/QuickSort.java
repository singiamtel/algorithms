import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class QuickSort{
	public ArrayList<BigInteger> array;
	public int partition(ArrayList<BigInteger> data,int low, int high){
		int i = low -1;
		BigInteger pivot = data.get(high);

		for(int j = low; j < high; ++j){
			//if(data.get(j) <= pivot){
			if(!(data.get(j).compareTo(pivot) == 1)){
				++i;
				swap(i,j);
			}
		}
		swap(i+1,high);
		return (i+1);
	}
	public void quickSort(ArrayList<BigInteger> data,int low,int high) {
		// Implement sort here
		if(data.size() == 1) return;
		if(low < high){
			int pivot = partition(data,low,high);
			quickSort(data, low, pivot -1);
			quickSort(data, pivot +1, high);
		}
	}

	public QuickSort(){
		array = new ArrayList<BigInteger>();
	}
	public static void main (String [ ] args) {
		try {
			QuickSort sort = new QuickSort();
			File input = new File("input.txt");
			Scanner scanner = new Scanner(input);

			while(scanner.hasNextBigInteger()){
				sort.array.add(scanner.nextBigInteger());
			}
			scanner.close();
			sort.quickSort(sort.array,0,sort.array.size()-1);
			if(!sort.isSorted()){
				System.out.println("Sorting failed!");
			}
			sort.printArray();
		} catch (FileNotFoundException e) {
			System.out.println("File input.txt was not found");
			e.printStackTrace();
		}
	}

	private void swap(int from, int to){
		BigInteger tmp = array.get(from);
		array.set(from, array.get(to));
		array.set(to, tmp);
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
