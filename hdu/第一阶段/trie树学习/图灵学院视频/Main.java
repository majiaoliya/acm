public class Main {
	
	public static void main(String args[]) {
		String s[] = { "java", "ps", "php", "ui", "css", "js" };
		TreeNode root = new TreeNode();
		for(String ss : s) {
			TireTree.createTireTree(root, ss);
		}
		System.out.println("insert ok");
		System.out.println(TireTree.find("java", root));
		System.out.println(TireTree.find("jav", root));
	}

}

class TreeNode {
	final static int MAX_SIZE = 26;
	char data; //表示存的字母
	boolean isEnd = false; //是否叶子节点
	TreeNode childs[];

	public TreeNode() {
		childs = new TreeNode[MAX_SIZE];
		isEnd = false;
	}

}

/**
 * 占用很大的内存 26叉树
 * 不适合中日韩文 也不适合IK
 * 可以用变种 : 双数组Tire树
 * find复杂度 O(n)
 */

class TireTree {
	public static void createTireTree(TreeNode node, String str) {
		char d[] = str.toCharArray();
		for(int i=0; i<d.length; i++) {
			int loc = d[i] - 'a'; // 0-25
			if(node.childs[loc] == null) {
				node.childs[loc] = new TreeNode();
				node.childs[loc].data = d[i];
			}
			node = node.childs[loc];
		}
		node.isEnd = true;
	}
	public static boolean find(String str, TreeNode node) {
		char d[] = str.toCharArray();
		for(int i=0; i<d.length; i++) {
			int loc = d[i] - 'a';
			if(node.childs[loc] == null) 
				return false;
			else 
				node = node.childs[loc];
		}
		// return true; //可以找到前缀 (用于补全)
		return node.isEnd; //可以找到完整的单词
	}
}
