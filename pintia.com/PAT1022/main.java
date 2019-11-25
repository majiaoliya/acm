import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		List<HashMap<String, ArrayList<String>>> mps = new ArrayList<HashMap<String, ArrayList<String>>>();
		for(int i=0; i<7; i++) {
			HashMap<String, ArrayList<String>> mp = new HashMap<String, ArrayList<String>>();
			mps.add(mp);
		}
		Scanner in = new Scanner(System.in);
		int n;
		n = Integer.parseInt(in.nextLine());
//		System.out.println(n);
		for(int i=0; i<n; i++) {
			String id = in.nextLine();
			for(int k=1; k<=5; k++) {
				String line = in.nextLine();
				if(k == 3) {
					String arr[] = line.split(" ");
					for(int j=0; j<arr.length; j++) {
						if(mps.get(k).get(arr[j]) == null) {
							ArrayList<String> list = new ArrayList<String>();
							mps.get(k).put(arr[j], list);
						}
//						System.out.println("3add " + arr[j] + "  " + id);
						mps.get(k).get(arr[j]).add(id);
					}
				} else {
					if(mps.get(k).get(line) == null) {
						ArrayList<String> list = new ArrayList<String>();
						mps.get(k).put(line, list);
					}
					mps.get(k).get(line).add(id);
				}
			}
		}
		
//		for(int i=1; i<=5; i++) {
//			System.out.println(mps.get(i));
//		}
//		
		n = Integer.parseInt(in.nextLine());
//		System.out.println(n);
		for(int i=0; i<n; i++) {
			String line = in.nextLine();
			int tag = line.charAt(0) - '0';
			String key = line.substring(3);
			System.out.println(line);
			if(mps.get(tag).get(key) != null) {
//				int size = mps.get(tag).get(key).size();
				ArrayList<String> list = mps.get(tag).get(key);
				Collections.sort(list);
				for(int j=0; j<list.size(); j++)
					System.out.println(list.get(j));
			} else {
				System.out.println("Not Found");
			}
		}
	}

}

