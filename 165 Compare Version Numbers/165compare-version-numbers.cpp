class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i = 0, j = 0;
        int n1 = v1.length(), n2 = v2.length();
        
        while (i < n1 || j < n2) {
            long long num1 = 0;
            long long num2 = 0;

            // extract number from version1 until dot
            while (i < n1 && v1[i] != '.') {
                num1 = num1 * 10 + (v1[i] - '0');
                i++;
            }

            // extract number from version2 until dot
            while (j < n2 && v2[j] != '.') {
                num2 = num2 * 10 + (v2[j] - '0');
                j++;
            }

            // compare the current section
            if (num1 > num2) return 1;
            if (num1 < num2) return -1;

            // move past the dots
            i++;
            j++;
        }

        return 0;
    }
};
