#include <vector>
#include <iostream>
#include <set>
#include <queue>

/**
 * 1036. Escape a Large Maze
 * There is a 1 million by 1 million grid on an XY-plane, and the coordinates of each grid square are (x, y).
 * We start at the source = [sx, sy] square and want to reach the target = [tx, ty] square. There is also an array of blocked squares, where each blocked[i] = [xi, yi] represents a blocked square with coordinates (xi, yi).
 * Each move, we can walk one square north, east, south, or west if the square is not in the array of blocked squares. We are also not allowed to walk outside of the grid.
 * Return true if and only if it is possible to reach the target square from the source square through a sequence of valid moves.
 */

class Solution {
private:
	inline static int dX[4] = {0, 1, 0, -1};
	inline static int dY[4] = {1, 0, -1, 0};
public:
	// blocked -> m, map size -> n (10^6)
	// O(m^2 * log(m))
	static bool isEscapePossible(const std::vector<std::vector<int>>& blocked, const std::vector<int>& source, const std::vector<int>& target) {
		std::set<std::pair<int, int>> s;

		// O(m * log(m))
		for (const auto& i : blocked) {
			s.insert(std::make_pair(i[0], i[1]));
		}

		// bfs, from source
		{
			std::queue<std::pair<int, int>> q;
			std::set<std::pair<int, int>> vis;
			q.push(std::make_pair(source[0], source[1]));
			vis.insert(q.front());

			// iterate at most 100 * 100 = 10^4 times.
			// because 200 obstacles could block a 100 x 100 area
			// no! it is not a square, but a triangle sized 200 * 200 / 2 = 20000!
			// even when using borders.
			// O(m^2 * log(m))
			int i = 0;
			for (; i < 20002 && !q.empty(); ++i) {
				auto current = q.front();
				q.pop();

				// reached ???
				if (current.first == target[0] && current.second == target[1])
					return true;

				// O(log(m))
				for (int j = 0; j < 4; ++j) {
					auto next = std::make_pair(current.first + dX[j], current.second + dY[j]);
					if (next.first < 0 || next.second < 0 || next.first >= 1000000 || next.second >= 1000000 || vis.count(next) || s.count(next))
						continue;
					q.push(next);
					vis.insert(next);
				}

				// std::cout << "q.size = " << q.size() << std::endl;
				// std::cout << "vis.size = " << vis.size() << "\n\n";
			}

			// source is impossible to reach target!
			if (i < 20002)
				return false;
		}

		// bfs, from target
		{
			std::queue<std::pair<int, int>> q;
			std::set<std::pair<int, int>> vis;
			q.push(std::make_pair(target[0], target[1]));

			// ditto
			// O(m^2 * log(m))
			int i = 0;
			for (; i < 20002 && !q.empty(); ++i) {
				auto current = q.front();
				q.pop();

				// reached ???
				if (current.first == source[0] && current.second == source[1])
					return true;

				// O(log(m))
				for (int j = 0; j < 4; ++j) {
					auto next = std::make_pair(current.first + dX[j], current.second + dY[j]);
					if (next.first < 0 || next.second < 0 || next.first >= 1000000 || next.second >= 1000000 || vis.count(next) || s.count(next))
						continue;
					q.push(next);
					vis.insert(next);
				}
			}

			// target is impossible to reach source!
			if (i < 20002)
				return false;
		}

		// it is now impossible for obstacles to block all paths.
		return true;
	}
};

int main() {
	std::cout << Solution::isEscapePossible({{100004,100036},{100005,100037},{100006,100038},{100007,100039},{100008,100040},{100009,100041},{100010,100042},{100011,100043},{100012,100044},{100013,100045},{100014,100046},{100015,100047},{100016,100048},{100017,100049},{100018,100050},{100019,100051},{100020,100052},{100021,100053},{100022,100054},{100023,100055},{100024,100056},{100025,100057},{100026,100058},{100027,100059},{100028,100060},{100029,100061},{100030,100062},{100031,100063},{100032,100064},{100033,100065},{100034,100066},{100035,100067},{100036,100068},{100037,100069},{100038,100070},{100039,100071},{100040,100072},{100041,100073},{100042,100074},{100043,100075},{100044,100074},{100045,100073},{100046,100072},{100047,100071},{100048,100070},{100049,100069},{100050,100068},{100051,100067},{100052,100066},{100053,100065},{100054,100064},{100055,100063},{100056,100062},{100057,100061},{100058,100060},{100059,100059},{100060,100058},{100061,100057},{100062,100056},{100063,100055},{100064,100054},{100065,100053},{100066,100052},{100067,100051},{100068,100050},{100069,100049},{100070,100048},{100071,100047},{100072,100046},{100073,100045},{100074,100044},{100075,100043},{100076,100042},{100077,100041},{100078,100040},{100079,100039},{100080,100038},{100081,100037},{100082,100036},{100083,100035},{100082,100034},{100081,100033},{100080,100032},{100079,100031},{100078,100030},{100077,100029},{100076,100028},{100075,100027},{100074,100026},{100073,100025},{100072,100024},{100071,100023},{100070,100022},{100069,100021},{100068,100020},{100067,100019},{100066,100018},{100065,100017},{100064,100016},{100063,100015},{100062,100014},{100061,100013},{100060,100012},{100059,100011},{100058,100010},{100057,100009},{100056,100008},{100055,100007},{100054,100006},{100053,100005},{100052,100004},{100051,100003},{100050,100002},{100049,100001},{100048,100000},{100047,99999},{100046,99998},{100045,99997},{100044,99996},{100043,99995},{100042,99996},{100041,99997},{100040,99998},{100039,99999},{100038,100000},{100037,100001},{100036,100002},{100035,100003},{100034,100004},{100033,100005},{100032,100006},{100031,100007},{100030,100008},{100029,100009},{100028,100010},{100027,100011},{100026,100012},{100025,100013},{100024,100014},{100023,100015},{100022,100016},{100021,100017},{100020,100018},{100019,100019},{100018,100020},{100017,100021},{100016,100022},{100015,100023},{100014,100024},{100013,100025},{100012,100026},{100011,100027},{100010,100028},{100009,100029},{100008,100030},{100007,100031},{100006,100032},{100005,100033},{100004,100034}},
											{100043,100035},
											{999939,999987});
	return 0;
}
