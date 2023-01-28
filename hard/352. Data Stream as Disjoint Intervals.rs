/*
    352. Data Stream as Disjoint Intervals

    Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers seen so far as a list of disjoint intervals.

    Implement the SummaryRanges class:

    SummaryRanges() Initializes the object with an empty stream.
    void addNum(int value) Adds the integer value to the stream.
    int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi]. The answer should be sorted by starti.

    Example 1:

    Input
    ["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
    [[], [1], [], [3], [], [7], [], [2], [], [6], []]
    Output
    [null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

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

struct SummaryRanges {
    arr: Vec<Vec<i32>>,
}

impl SummaryRanges {
    fn new() -> Self {
        SummaryRanges { arr: Vec::new() }
    }

    fn add_num(&mut self, target: i32) {
        let mut i = self.bin_search(target);

        // If arr is empty
        if i == -1 {
            self.arr.push(vec![target, target]);
            return;
        }
        let mut i = i as usize;

        // Next we check if number is included in 3 intervals
        if self.arr[i][0] <= target && target <= self.arr[i][1] {
            return;
        }
        if i > 0 && self.arr[i - 1][0] <= target && target <= self.arr[i - 1][1] {
            return;
        }
        if i < self.arr.len() - 1 && self.arr[i + 1][0] <= target && target <= self.arr[i + 1][1] {
            return;
        }

        // If target was used in modifying one of the current intervals we don't create a new one
        let mut was_used = false;

        // Current interval
        if self.arr[i][0] == target + 1 {
            self.arr[i][0] = target;
            was_used = true;
        } else if self.arr[i][1] == target - 1 {
            self.arr[i][1] = target;
            was_used = true;
        }

        // Previous interval (if exists)
        if i > 0 {
            i -= 1;
            if self.arr[i][0] == target + 1 {
                self.arr[i][0] = target;
                was_used = true;
            } else if self.arr[i][1] == target - 1 {
                self.arr[i][1] = target;
                was_used = true;
            }
            i += 1;

            // Merge intervals
            if self.arr[i][0] == self.arr[i - 1][1] {
                self.arr[i][0] = self.arr[i - 1][0];
                self.arr.remove(i - 1);
                i -= 1;
            }
        }

        // Next interval (if exists)
        if i < self.arr.len() - 1 {
            i += 1;
            if self.arr[i][0] == target + 1 {
                self.arr[i][0] = target;
                was_used = true;
            } else if self.arr[i][1] == target - 1 {
                self.arr[i][1] = target;
                was_used = true;
            }
            i -= 1;

            // Merge intervals
            if self.arr[i][1] == self.arr[i + 1][0] {
                self.arr[i][1] = self.arr[i + 1][1];
                self.arr.remove(i + 1);
            }
        }

        // If target wasn't used - we create new interval
        if !was_used {
            if i > 0 && self.arr[i - 1][0] > target {
                self.arr.insert(i - 1, vec![target, target]);
            } else if self.arr[i][0] > target {
                self.arr.insert(i, vec![target, target]);
            } else {
                self.arr.insert(i + 1, vec![target, target]);
            }
        }
    }

    fn get_intervals(&self) -> Vec<Vec<i32>> {
        self.arr.clone()
    }

    fn bin_search(&self, target: i32) -> isize {
        let (mut low, mut high) = (0isize, self.arr.len() as isize);
        let mut mid: isize = -1;
        while low < high {
            mid = (low + high) / 2;
            if self.arr[mid as usize][0] == target {
                return mid;
            }

            if target > self.arr[mid as usize][0] {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        mid
    }
}
