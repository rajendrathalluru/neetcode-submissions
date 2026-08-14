class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for (string& str : strs) {
            encoded += to_string(str.size()) + "#" + str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;

        while (i < s.size()) {
            // Find the '#' separating length and string
            int j = i;

            while (s[j] != '#') {
                j++;
            }

            // Convert length from string to integer
            int len = stoi(s.substr(i, j - i));

            // Move past '#'
            j++;

            // Extract exactly 'len' characters
            result.push_back(s.substr(j, len));

            // Move to the beginning of next encoded string
            i = j + len;
        }

        return result;
    }
};