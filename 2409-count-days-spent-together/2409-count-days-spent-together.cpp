class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // Days in each month for a non-leap year
        vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        // Helper lambda to convert "MM-DD" to day of the year
        auto convertToDayOfYear = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            int totalDays = day;
            for (int i = 0; i < month - 1; ++i) {
                totalDays += daysInMonths[i];
            }
            return totalDays;
        };
        
        int aliceArrival = convertToDayOfYear(arriveAlice);
        int aliceLeave = convertToDayOfYear(leaveAlice);
        int bobArrival = convertToDayOfYear(arriveBob);
        int bobLeave = convertToDayOfYear(leaveBob);
        
        // The overlap starts on the later of the two arrival dates
        int latestArrival = max(aliceArrival, bobArrival);
        
        // The overlap ends on the earlier of the two leaving dates
        int earliestLeave = min(aliceLeave, bobLeave);
        
        // If latest arrival is before or on the earliest leave, they have overlapping days
        if (latestArrival <= earliestLeave) {
            return earliestLeave - latestArrival + 1;
        }
        
        return 0;
    }
};