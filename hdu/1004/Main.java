/**
import java.util.Iterator;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {	
	
	public static void main(String args[]) {
		int n = 0;
		Scanner in = new Scanner(System.in);
		for(; ;) {
			n = in.nextInt();
			if(n == 0) break;
			
			Map<String, Integer> map = new HashMap<String, Integer>();
			
			for(int i=0; i<n; i++) {
				String color =	in.nextLine();
				map.put(color, (map.get(color) == null ? 1 : map.get(color)+1));
			}
			Iterator<String> iter = map.keySet().iterator();
			int max = Integer.MIN_VALUE;
			String curMax = null;
			while(iter.hasNext()) {
				String c = iter.next();
				int count = map.get(c);
				if(max < count) {
					max = count;
					curMax = c;
				}
			}

			System.out.println(curMax);
		}
	}
}
*/

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		for(int i=in.nextInt(); i!=0; i=in.nextInt()) {
			in.next();			
			Map<String, Integer> map = new HashMap<String, Integer>();
			
			for(int k=0; k<i; k++) {
				String color = in.nextLine();
				Integer value = map.get(color);
				map.put(color, value == null ? 1 : value + 1);
			}
			
			Iterator<String> iter = map.keySet().iterator();
			String max = null;
			Integer maxInt = null;
			for(; iter.hasNext(); ) {
				String s = iter.next();
				Integer v = map.get(s);
				if(max == null) max = s;
				if(maxInt == null) maxInt = v;
				if(maxInt <= v) {
					max = s;
					maxInt = v;
				}
			}
			System.out.println(max);
		}
	}

}

