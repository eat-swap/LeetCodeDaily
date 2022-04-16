def build_max_n(n):
    ret = ''
    for i in range(n):
        ret += '9'
    return ret


# Get answer of n
def get_ans(n):
    half_max = int(build_max_n(n))
    half_min = 1 + int(build_max_n(n - 1))
    for i in range(half_max, half_min - 1, -1):
        i_full = int(str(i) + str(i)[::-1])
        ok, ans = False, -1
        for j in range(half_max, half_min - 1, -1):
            l = len(str(i_full // j))
            if l < n:
                continue
            if l > n:
                break
            if i_full % j == 0 and l == n:
                ok, ans = True, j
                break
        if ok:
            print(i_full)
            print(j)
            return


# Brute force brings miracles, table generation grants you 1st prize.
if __name__ == '__main__':
    for i in range(2, 9):
        get_ans(i)
        print()
