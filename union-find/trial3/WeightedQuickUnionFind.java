/* 
 * This implements the 
 * Weighted Quick Union and Quick Find algorithm
 *
 * */
public class UF {
	int[] id;
	int[] sz;

	public UF(int n) {
		id = new int[n];
		sz = new int[n];

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
		if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
		else			   { id[j] = i; sz[i] += sz[j]; }
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
