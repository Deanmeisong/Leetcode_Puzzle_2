class Solution:
    def nextClosestTime(self, time: str) -> str:
        s = set(time)
        hour = int(time[0:2])
        minute = int(time[3:5])
        while True:
            minute += 1
            if minute == 60:
                minute = 0
                hour = 0 if hour == 23 else hour+1
            time = "%02d:%02d" % (hour, minute)
            if set(time) <= s: return time
        return time