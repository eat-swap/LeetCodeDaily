namespace int_0221;

public class Solution {
	public int MajorityElement(int[] nums) {
		var m = new Dictionary<int, int>();
		var n = nums.Length >> 1;
		foreach (var i in nums) {
			if (m.ContainsKey(i))
				++m[i];
			else
				m[i] = 1;
			if (m[i] > n)
				return i;
		}
		// Never reaches
		return 0;
	}
}

public class Runner {
	private static void Main() {
		// Tested in C++
	}
}
