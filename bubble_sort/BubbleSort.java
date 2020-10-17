import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class BubbleSort {
	public ArrayList<BigInteger> array;
	public BubbleSort(){
		array = new ArrayList<BigInteger>();
	}
	public static void main (String [ ] args) {
		try {
			BubbleSort bubbleSort = new BubbleSort();
			File input = new File("input.txt");
			Scanner scanner = new Scanner(input);

			while(scanner.hasNextBigInteger()){
				bubbleSort.array.add(scanner.nextBigInteger());
			}
			scanner.close();
			bubbleSort.sort();
			if(!bubbleSort.isSorted()){
				System.out.println("Sorting failed!");
			}
			bubbleSort.printArray();
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
	public void sort() {
		for(int i = 0; i<array.size(); ++i){
			for (int j = 0; j < array.size() - i - 1; j++) {
				if (array.get(j).compareTo(array.get(j + 1)) == 1) {
					swap(j, j + 1);
				}
			}
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