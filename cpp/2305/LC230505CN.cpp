#include <vector>

class LC230505CN {
public:
	static int hardestWorker(int, const std::vector<std::vector<int>>&) noexcept;
};

int LC230505CN::hardestWorker(int, const std::vector<std::vector<int>>& logs) noexcept {
	int id = logs[0][0], time = logs[0][1];
	for (int i = 1; i < logs.size(); ++i) {
		if (int delta = logs[i][1] - logs[i - 1][1]; delta > time || (delta == time && logs[i][0] < id)) {
			time = delta;
			id = logs[i][0];
		}
	}
	return id;
}
