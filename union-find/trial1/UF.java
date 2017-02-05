/* This is put in trials as it is problematic.
 * 
 * problematic: If we have N union commands on N Objects,
 * then it takes n^2 array access to process the unions.
 *
 * btw, this type of approach to solving a problem is called
 * 'eager approach.'
 */

public class UF {
	int n;
	int[] id;

	public UF(int n) {
		id = new int[n];

		for (int i = 0; i < n; i++)
			id[i] = i;
	}

	public void union(int p, int q) {
		int pid = id[p];
		int qid = id[q];

		if (!connected(pid, qid)) {
			for (int i = 0; i < id.length; i++) {

				if ( id[i] == pid)
					id[i] = qid;
			}
		}
	}

	public boolean connected(int p, int q) {
		return ( id[p] == id[q] );
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
