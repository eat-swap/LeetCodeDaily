namespace int_0222;

public class Solution {
	public int TitleToNumber(string columnTitle) {
		int ret = 0;
		foreach (char c in columnTitle)
			ret = (26 * ret) - 'A' + c + 1;
		return ret;
	}
}

public class Runner {
	public static void Main() {
		var s = new Solution();
		Console.WriteLine(s.TitleToNumber("ZY"));
	}
}