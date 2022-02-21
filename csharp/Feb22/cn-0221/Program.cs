namespace cn_0221;

public class Solution {
	public string PushDominoes(string dominoes) {
		var q = new Queue<int>();

		var n = dominoes.Length;
		var result = new int[n];
		var lastModified = new int[n];
		
		for (int i = 0; i < n; ++i) {
			if ('.' != dominoes[i]) {
				q.Enqueue(i);
				q.Enqueue(1);

				lastModified[i] = 1;

				if (dominoes[i] == 'L') {
					result[i] = -1;
				}
				else { // == 'R'
					result[i] = 1;
				}
			}
		}

		int maxSize = 0, cnt = 0;
		while (q.Count > 0) {
			++cnt;
			if (q.Count > maxSize) {
				maxSize = q.Count;
			}
			// every point in queue must be either be altered to L or R
			// Take one point out of the queue
			// alter all its affected points
			// And insert back all affected into queue.
			var position = q.Dequeue();
			var timePoint = q.Dequeue();

			if (position > 0 && (lastModified[position - 1] == timePoint + 1 || lastModified[position - 1] == 0) && result[position] < 0) {
				// L element not affected

				if (lastModified[position - 1] == 0) {
					q.Enqueue(position - 1);
					q.Enqueue(timePoint + 1);
				}
				
				--result[position - 1];
				lastModified[position - 1] = timePoint + 1;
			} else if (position < n - 1 && (lastModified[position + 1] == timePoint + 1 || lastModified[position + 1] == 0) && result[position] > 0) {

				if (lastModified[position + 1] == 0) {
					q.Enqueue(position + 1);
					q.Enqueue(timePoint + 1);
				}
				
				++result[position + 1];
				lastModified[position + 1] = timePoint + 1;
			}
		}

		string ret = "";

		foreach (int i in result) {
			if (i < 0)
				ret += "L";
			else if (i > 0)
				ret += "R";
			else
				ret += ".";
		}
		
		Console.WriteLine(maxSize);
		Console.WriteLine(cnt);
		
		return ret;
	}
}

public class Runner {
	public static void Main() {

		var r = new Random();
		
		string args = "";
		const int SIZE = 100000;
		for (int i = 0; i < SIZE; ++i) {
			switch (r.Next() % 3) {
				case 0:
					args += "L";
					break; 
				case 1:
					args += "R";
					break;
				case 2:
					args += ".";
					break;
			}
		}
		
		var s = new Solution();

		long start = DateTimeOffset.Now.ToUnixTimeMilliseconds();
		var ret = s.PushDominoes(args);
		long end = DateTimeOffset.Now.ToUnixTimeMilliseconds();
		
		Console.WriteLine("" + (end - start) + " ms");
	}
}
