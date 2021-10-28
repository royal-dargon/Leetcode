// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int n){
    return true;
}

class Solution {
public:
    int firstBadVersion(int n) {
        long int flagl = 1;
        long int flagr = n;
        if(n == 1) {
            return 1;
        }
        while(flagl <= flagr) {
            long int mid = flagl + flagr;
            mid = mid / 2;
            if(isBadVersion(mid) == true) {
                flagr = mid - 1;
            } else {
                flagl = mid + 1;
            }
        }
        return flagl;
    }
};