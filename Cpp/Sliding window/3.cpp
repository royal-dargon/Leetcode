class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int i;
        int lenth = s.size();
        if(lenth == 0) {
            return 0;
        }
        if(s == " ") {
            return 0;
        }
        int temp[26];
        // 表示将会进行如此次的窗口滑动
        for(i = 0;i < lenth;i ++) {
            memset(temp,0,sizeof(int)*26);
            // 用来表示窗口的最右端
            int flag = 1;
            int right = i;
            while(right < lenth) {
                int j,tmp;
                //for(j = i;j <= right;j ++) {
                //    temp[s[j] - 'a'] ++;
                //}
                temp[s[right] - 'a'] ++;
                for(tmp = 0;tmp < 26;tmp ++) {
                    if(temp[tmp] > 1) {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 0) {
                    break;
                }
                if(tmp == 26) {
                    right ++;
                }
            }
            if(flag == 0) {
                temp[s[i] - 'a'] --;
            }
            int res = right - i;
            cout << res << endl;
            if(res > max) {
                max = res;
            }
        }
        return max;
    }
};