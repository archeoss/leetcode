/*
    352. Data Stream as Disjoint Intervals

    Given a data stream input of non-negative integers a1, a2, ..., an,
   summarize the numbers seen so far as a list of disjoint intervals.

    Implement the SummaryRanges class:

    SummaryRanges() Initializes the object with an empty stream.
    void addNum(int value) Adds the integer value to the stream.
    int[][] getIntervals() Returns a summary of the integers in the stream
   currently as a list of disjoint intervals [starti, endi]. The answer should
   be sorted by starti.

    Example 1:

    Input
    ["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals",
   "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
    [[], [1], [], [3], [], [7], [], [2], [], [6], []]
    Output
    [null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7,
   7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

    Explanation
    SummaryRanges summaryRanges = new SummaryRanges();
    summaryRanges.addNum(1);      // arr = [1]
    summaryRanges.getIntervals(); // return [[1, 1]]
    summaryRanges.addNum(3);      // arr = [1, 3]
    summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
    summaryRanges.addNum(7);      // arr = [1, 3, 7]
    summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
    summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
    summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
    summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
    summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]
*/

class SummaryRanges {
public:
  vector<vector<int>> nums;
  // where new value should be added
  int ind;
  SummaryRanges() {}

  void addNum(int value) {
    if (nums.empty()) {
      nums.push_back({value, value});
      return;
    }

    // binary search to find the insert position
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (value > nums[r][1]) {
        ind = r + 1;
        break;
      }
      if (value < nums[l][0]) {
        ind = l;
        break;
      }
      // if value exists in any interval
      if (value >= nums[mid][0] && value <= nums[mid][1]) {
        ind = -1;
        break;
      } else if (value < nums[mid][0]) {
        r = mid - 1;
      } else if (value > nums[mid][1]) {
        l = mid + 1;
      }
    }
    // if the value exists in any interval then simply return.
    if (ind == -1) {
      return;
    }
    // we are looking for other intervals who can be merge into one
    bool flagi = false;
    bool flagj = false;
    // searching in the right of the insert position(ind to n-1)
    int j = -1;
    int lookFor = value;
    for (j = ind; j < nums.size() && lookFor + 1 == nums[j][0]; j++) {
      lookFor = nums[j][1];
      flagj = true;
    }
    // searching in the left of the insert position(ind-1 to 0)
    lookFor = value;
    int i = -1;
    for (i = ind - 1; i >= 0 && nums[i][1] + 1 == value; i--) {
      lookFor = nums[i][0];
      flagi = true;
    }

    if (!flagi)
      i = -1;
    else {
      i++;
    }
    if (!flagj)
      j = -1;
    else {
      j--;
    }
    // k is the value from where we start shrinking our array.
    int k;
    // if we dont have any colliding intervals with new value
    if (i == -1 && j == -1) {
      nums.push_back({value, value});
      for (int i = nums.size() - 1; i > ind; i--) {
        nums[i] = nums[i - 1];
      }
      nums[ind] = {value, value};
      ind = -1;
      return;
    } else if (i >= 0 && j == -1) {
      nums[i] = {nums[i][0], value};
      i++;
      k = ind;

    } else if (i == -1 && j >= 0) {
      nums[j] = {value, nums[j][1]};
      i = ind;
      k = j;
    } else if (i >= 0 && j >= 0) {
      nums[i] = {nums[i][0], nums[j][1]};
      i++;
      k = j + 1;
    }
    // shrinking the array after merging the intervals
    while (i < nums.size() && k < nums.size()) {
      nums[i++] = nums[k++];
    }
    int size = nums.size();
    while (i < size) {
      nums.pop_back();
      i++;
    }
    // assing ind = -1 for the next add Call
    ind = -1;
  }

  vector<vector<int>> getIntervals() { return nums; }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
