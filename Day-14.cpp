class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = (hour==12)?0:hour;
        double res = abs(30*hour - 11*minutes/2.0);
     
        return (res>180)?(360-res):res;
    }
};
