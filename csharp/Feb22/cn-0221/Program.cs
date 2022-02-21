namespace cn_0221;

public class Solution {
	public static string PushDominoes(string dominoes) {
		var q = new Queue<int>();

		var n = dominoes.Length;
		for (int i = 0; i < n; ++i) {
			if ('.' != dominoes[i]) {
				q.Enqueue(i);
				q.Enqueue(0);
			}
		}

		var result = new int[n];
		var lastModified = new int[n];
		while (q.Count > 0) {
			var position = q.Dequeue();
			var timePoint = q.Dequeue();
			
		}
		
		return "test";
	}

	public static void Main() {
		// empty
	}
}