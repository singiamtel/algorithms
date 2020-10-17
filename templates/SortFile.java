import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class SortFile {
	public ArrayList<BigInteger> array;

	public void sort() {
		// Implement sort here
	}

	public SortFile(){
		array = new ArrayList<BigInteger>();
	}
	public static void main (String [ ] args) {
		try {
			SortFile sort = new SortFile();
			File input = new File("input.txt");
			Scanner scanner = new Scanner(input);

			while(scanner.hasNextBigInteger()){
				sort.array.add(scanner.nextBigInteger());
			}
			scanner.close();
			sort.sort();
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