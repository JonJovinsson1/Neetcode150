/*Sorting*/
class Solution {
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
/* as pure anagrams, not inside larger strings, the first check is ensuring that both strings s&t are the same length. if s = "abc" & t = "abcd", length returns 3 & 4, making impure anagrams.
Function is then self explanitory, sort both strings and return the value of s == t, as a boolean.

time complexity O(n log n + m log m) (n=s,m=t)
space complexity O(1) or O(n+m) depending on the sorting algorithm.
*/

/*Hash Map*/
class Solution {
    bool isAnagram(string s, string t){
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> countS;
        unordered_map<char, int> countT;
        for(int i = 0; i<s.length();i++) {
            countS[s[i]]++;
            countT[s[i]]++;
        }
        return countS == countT;
    }
};
/* unordered_map visualisation for "apple"
countS[s[i]]++ Find the counter for the current letter. If it doesn't exist, start it at 0. Then, add 1 to it.
i = 0 ('a'):
Map is empty. Create slot 'a'. Set to 0. Add 1.
{'a': 1}
i = 1 ('p'):
Create slot 'p'. Set to 0. Add 1.
{'a': 1, 'p': 1}
i = 2 ('p'):
Slot 'p' already exists! Current value is 1. Add 1.
{'a': 1, 'p': 2}
i = 3 ('l'):
{'a': 1, 'p': 2, 'l': 1}
i = 4 ('e'):
{'a': 1, 'p': 2, 'l': 1, 'e': 1}

Time complexoty O(n+m) n=s,m=t
space complexity O(1) at most, 26 characters.
*/

/*Hash Table (using array)*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> count(26,0);
        for (int i = 0; i<s.length(); i++) {
            count[s[i]- 'a']++;
            count[t[i]- 'a']--; 
        }

        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }
        return true;
    }
};
/* while at first it looks like a highly specific solution to a very specific problem its actually applicable to many problems.
It can be used whenever you know the range of keys ahead of time. When you do, never use a hash map. 

Visual Walkthrough
Example: s = "rat", t = "tar"
Start: Vector is all zeros. [0, 0, 0, ...]
Loop 1 (i=0):
s[0] is 'r': Add 1 to index 17 ('r').
t[0] is 't': Subtract 1 from index 19 ('t').
State: r: +1, t: -1, others 0.
Loop 2 (i=1):
s[1] is 'a': Add 1 to index 0 ('a').
t[1] is 'a': Subtract 1 from index 0 ('a').
State: r: +1, t: -1, a: 0 (+1 and -1 cancelled out instantly).
Loop 3 (i=2):
s[2] is 't': Add 1 to index 19 ('t').
t[2] is 'r': Subtract 1 from index 17 ('r').
State:
'r' bucket: Was +1, now -1 = 0.
't' bucket: Was -1, now +1 = 0.
'a' bucket: 0.
Final Check:
Loop through the vector. Are they all 0? Yes. Return true.
Why is this better than the Map?
Speed: Accessing an array index [i] is faster than looking up a hash key in a map.
Space: An unordered_map has overhead. This vector is tiny and fits entirely in the CPU cache.
*/