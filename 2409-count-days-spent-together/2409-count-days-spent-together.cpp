class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int alicestartmonth = stoi(arriveAlice.substr(0, 2));
        int aliceendmonth = stoi(leaveAlice.substr(0, 2));
        int alicestartday = stoi(arriveAlice.substr(3, 2));
        int aliceendday = stoi(leaveAlice.substr(3, 2));

        int bobstartmonth = stoi(arriveBob.substr(0, 2));
        int bobendmonth = stoi(leaveBob.substr(0, 2));
        int bobstartday = stoi(arriveBob.substr(3, 2));
        int bobendday = stoi(leaveBob.substr(3, 2));

        vector<int> arr = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        auto getDay = [&](int month, int day) {
            int total = day;
            for (int i = 0; i < month - 1; i++) {
                total += arr[i];
            }
            return total;
        };

        int aliceStart = getDay(alicestartmonth, alicestartday);
        int aliceEnd = getDay(aliceendmonth, aliceendday);
        int bobStart = getDay(bobstartmonth, bobstartday);
        int bobEnd = getDay(bobendmonth, bobendday);

        int start = max(aliceStart, bobStart);
        int end = min(aliceEnd, bobEnd);

        if (start > end) return 0;

        return end - start + 1;
    }
};