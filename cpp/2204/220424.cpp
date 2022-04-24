#include <string>
#include <unordered_map>
#include <utility>

struct PairHash {
	template<typename T1, typename T2>
	std::size_t operator()(const std::pair<T1, T2>& p) const {
		return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
	}
};

/**
 * 1396. Design Underground System
 * An underground railway system is keeping track of customer travel times between different stations. They are using this data to calculate the average time it takes to travel from one station to another.
 *
 * Implement the UndergroundSystem class:
 *
 * void checkIn(int id, string stationName, int t)
 * 	A customer with a card ID equal to id, checks in at the station stationName at time t.
 * 	A customer can only be checked into one place at a time.
 * void checkOut(int id, string stationName, int t)
 * 	A customer with a card ID equal to id, checks out from the station stationName at time t.
 * double getAverageTime(string startStation, string endStation)
 * 	Returns the average time it takes to travel from startStation to endStation.
 * 	The average time is computed from all the previous traveling times from startStation to endStation that happened directly, meaning a check in at startStation followed by a check out from endStation.
 * 	The time it takes to travel from startStation to endStation may be different from the time it takes to travel from endStation to startStation.
 * 	There will be at least one customer that has traveled from startStation to endStation before getAverageTime is called.
 * 	You may assume all calls to the checkIn and checkOut methods are consistent. If a customer checks in at time t1 then checks out at time t2, then t1 < t2. All events happen in chronological order.
 */

class UndergroundSystem {
private:
	std::unordered_map<int, std::pair<int, std::string>> checkInTable;
	std::unordered_map<std::pair<std::string, std::string>, std::pair<int, unsigned long long>, PairHash> travelTime;
public:
	UndergroundSystem() = default;

	void checkIn(int id, const std::string& s, int t) {
		checkInTable[id] = {t, s};
	}

	void checkOut(int id, const std::string& outSName, int tOut) {
		const auto& [tIn, inSName] = checkInTable[id];
		auto& [cnt, totalTime] = travelTime[{inSName, outSName}];
		++cnt;
		totalTime += tOut - tIn;
	}

	double getAverageTime(const std::string& startStation, const std::string& endStation) {
		const auto& [cnt, total] = travelTime[{startStation, endStation}];
		return double(total) / cnt;
	}
};
