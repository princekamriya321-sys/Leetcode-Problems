class Solution {
public:
    string smallestNumber(string num, long long t) {
        int a = 0, b = 0, c = 0, d = 0;
        while (t % 2 == 0) { t /= 2; a++; }
        while (t % 3 == 0) { t /= 3; b++; }
        while (t % 5 == 0) { t /= 5; c++; }
        while (t % 7 == 0) { t /= 7; d++; }
        if (t != 1) return "-1";

        int A = a + 1, B = b + 1, C = c + 1, D = d + 1;
        static const int dexp[10][4] = {
            {0,0,0,0}, {0,0,0,0}, {1,0,0,0}, {0,1,0,0}, {2,0,0,0},
            {0,0,1,0}, {1,1,0,0}, {0,0,0,1}, {3,0,0,0}, {0,2,0,0}
        };

        auto idx = [&](int x, int y, int z, int w) {
            return ((x * B + y) * C + z) * D + w;
        };

        int total = A * B * C * D;
        vector<int> minDigits(total, -1);
        int startIdx = idx(0, 0, 0, 0);
        minDigits[startIdx] = 0;
        queue<int> bfs;
        bfs.push(startIdx);
        while (!bfs.empty()) {
            int cur = bfs.front(); bfs.pop();
            int w = cur % D, tmp = cur / D;
            int z = tmp % C; tmp /= C;
            int y = tmp % B; tmp /= B;
            int x = tmp;
            for (int dg = 2; dg <= 9; dg++) {
                int nx = min(x + dexp[dg][0], a);
                int ny = min(y + dexp[dg][1], b);
                int nz = min(z + dexp[dg][2], c);
                int nw = min(w + dexp[dg][3], d);
                int ni = idx(nx, ny, nz, nw);
                if (minDigits[ni] == -1) {
                    minDigits[ni] = minDigits[cur] + 1;
                    bfs.push(ni);
                }
            }
        }

        auto feasible = [&](int x, int y, int z, int w, int L) {
            int md = minDigits[idx(x, y, z, w)];
            return md != -1 && md <= L;
        };

        auto buildSuffix = [&](int x, int y, int z, int w, int L) {
            string res;
            res.reserve(L);
            for (int pos = 0; pos < L; pos++) {
                for (int dg = 1; dg <= 9; dg++) {
                    int nx = max(x - dexp[dg][0], 0);
                    int ny = max(y - dexp[dg][1], 0);
                    int nz = max(z - dexp[dg][2], 0);
                    int nw = max(w - dexp[dg][3], 0);
                    if (feasible(nx, ny, nz, nw, L - pos - 1)) {
                        res.push_back('0' + dg);
                        x = nx; y = ny; z = nz; w = nw;
                        break;
                    }
                }
            }
            return res;
        };

        int n = num.size();
        vector<int> digs(n);
        for (int i = 0; i < n; i++) digs[i] = num[i] - '0';

        vector<bool> prefixValid(n + 1, true);
        vector<array<int,4>> prefixExp(n + 1, {0,0,0,0});
        bool zeroSeen = false;
        for (int i = 0; i < n; i++) {
            if (digs[i] == 0) zeroSeen = true;
            if (zeroSeen) {
                prefixValid[i+1] = false;
                prefixExp[i+1] = prefixExp[i];
            } else {
                prefixValid[i+1] = true;
                auto& e = dexp[digs[i]];
                auto& p = prefixExp[i];
                prefixExp[i+1] = {
                    min(p[0]+e[0], a), min(p[1]+e[1], b),
                    min(p[2]+e[2], c), min(p[3]+e[3], d)
                };
            }
        }

        if (prefixValid[n] &&
            prefixExp[n][0] == a && prefixExp[n][1] == b &&
            prefixExp[n][2] == c && prefixExp[n][3] == d) {
            return num;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (!prefixValid[i]) continue;
            auto& pe = prefixExp[i];
            int L = n - 1 - i;
            for (int dg = digs[i] + 1; dg <= 9; dg++) {
                auto& e = dexp[dg];
                int nx = min(pe[0]+e[0], a), ny = min(pe[1]+e[1], b);
                int nz = min(pe[2]+e[2], c), nw = min(pe[3]+e[3], d);
                int rx = a - nx, ry = b - ny, rz = c - nz, rw = d - nw;
                if (feasible(rx, ry, rz, rw, L)) {
                    return num.substr(0, i) + char('0'+dg) + buildSuffix(rx, ry, rz, rw, L);
                }
            }
        }

        // FIX: length must be at least the true minimum needed for the full target
        int minLenForTarget = minDigits[idx(a, b, c, d)];
        int L = max(n + 1, minLenForTarget);
        return buildSuffix(a, b, c, d, L);
    }
};