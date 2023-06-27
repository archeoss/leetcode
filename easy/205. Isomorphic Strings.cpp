/*
    205. Isomorphic Strings

    Given two strings s and t, determine if they are isomorphic.
    Two strings s and t are isomorphic if the characters in s can be replaced to
   get t. All occurrences of a character must be replaced with another character
   while preserving the order of characters. No two characters may map to the
   same character, but a character may map to itself.

    Example 1:
    Input: s = "egg", t = "add"
    Output: true

    Example 2:
    Input: s = "foo", t = "bar"
    Output: false

    Example 3:
    Input: s = "paper", t = "title"
    Output: true
*/

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    if (s.size() != t.size())
      return false;

    bool res = true;
    map<int, int> replacesT;
    map<int, int> replacesS;
    for (int i = 0; res && i < s.size(); i++) {
      int chrS = s[i];
      int chrT = t[i];
      auto endT = replacesT.end();
      auto endS = replacesS.end();
      if (replacesT.find(chrT) != endT && replacesS.find(chrS) != endS) {
        if (replacesS[chrS] != chrT || replacesT[chrT] != chrS) {
          res = false;
        }
      } else if ((replacesT.find(chrT) == endT) !=
                 (replacesS.find(chrS) == endS)) {
        res = false;
      } else {
        replacesS[chrS] = chrT;
        replacesT[chrT] = chrS;
      }
    }

    return res;
  }
};
