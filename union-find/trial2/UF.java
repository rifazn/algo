/* This is put in trials as it is problematic.
 * 
 * 
 * 
 *
 * btw, this type of approach to solving a problem is called
 * 'lazy approach.'
 */

public class UF {
	int[] id;

	public UF(int n) {
		id = new int[n];

		for (int i = 0; i < n; i++)
			id[i] = i;
	}

	private int root(int i) {
		while (i != id[i]) i = id[i];
		return i;
	}

	public void union(int p, int q) {
		int i = root(p);
		int j = root(q);
		id[i] = j;
	}

	public boolean connected(int p, int q) {
		return root(p) == root(q);
	}

	// main method created for testing
	public static void main(String[] args) {
		UF uf = new UF(10);

		// check that elements are not connected before union
		System.out.println("connected(0, 1) " + uf.connected(0, 1));
		System.out.println("connected(5, 9) " + uf.connected(5, 9));

		// union the checked elements
		uf.union(0, 1);
		uf.union(5, 9);

		// check them again
		System.out.println("connected(0, 1) " + uf.connected(0, 1));
		System.out.println("connected(5, 9) " + uf.connected(5, 9));

		// And it's worked!
	}
}
