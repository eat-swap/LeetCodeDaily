#include <vector>
#include <numeric>

class LC240421 {
public:
    static bool validPath(int n, const std::vector<std::vector<int>>& edges, int source, int destination) noexcept;
};

class UFS {
private:
    std::vector<int> father;

public:
    UFS(int n) noexcept {
        this->father = std::vector<int>(n + 1);
        std::iota(this->father.begin(), this->father.end(), 0);
    }

    int find(int x) noexcept {
        return father[x] == x ? x : (father[x] = find(father[x]));
    }

    void merge(int x, int y) noexcept {
        father[find(x)] = find(y);
    }
};

bool LC240421::validPath(int n, const std::vector<std::vector<int>> &edges, int source, int destination) noexcept {
    UFS s(n);
    for (const auto& e : edges) {
        s.merge(e[0], e[1]);
    }
    return s.find(source) == s.find(destination);
}

using Solution = LC240421;
