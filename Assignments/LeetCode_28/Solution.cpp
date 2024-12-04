class Solution {
public:
    int strStr(string haystack, string needle) {
        // Edge case: if needle is empty, return 0
        if (needle.empty()) return 0;

        // Edge case: if needle is longer than haystack, return -1
        if (needle.size() > haystack.size()) return -1;

        //loop
        for(int i = 0; i <= haystack.size() - needle.size(); i++){
            if(haystack.substr(i, needle.size()) == needle)
            return i;   //return index of the first occurance

        }
         return -1;
    }
};
