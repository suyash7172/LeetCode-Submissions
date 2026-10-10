class Solution {
public:
    int myAtoi(string s) {
        int a = 0, f = 1, d = 0;
        int i = 0;

        // Skip leading spaces
        while(i < s.length() && s[i] == ' ')
            i++;

        // Handle optional sign
        if(i < s.length() && (s[i] == '+' || s[i] == '-'))
        {
            if(s[i] == '-')
                f = -1;
            i++;
        }

        // Convert digits
        for(int j = i; j < s.length(); j++) 
        {
            if(!isdigit(s[j]))
            {
                break;
            }
            else 
            {
                int digit = s[j] - '0';

                // Check for overflow
                if(a > (INT_MAX - digit) / 10) 
                {
                    return f == 1 ? INT_MAX : INT_MIN;
                }

                a = a * 10 + digit;
            }
        }

        return a * f;
    }
};