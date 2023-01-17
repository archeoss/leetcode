/*
    2. Add Two Numbers

    You are given two non-empty linked lists representing two non-negative integers.
    The digits are stored in reverse order, and each of their nodes contains a single digit.
    Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.

    Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    Output: [8,9,9,9,0,0,0,1]
*/

// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        if l2.is_none() {
            return l1;
        }
        if l1.is_none() {
            return l2;
        }
        let mut l1_ref = &l1.unwrap();
        let mut l2_ref = &l2.unwrap();
        let mut num = l1_ref.val + l2_ref.val;
        let mut res = Box::new(ListNode::new(num % 10));
        let mut add = num / 10;
        let mut cur_node = &mut res;
        while let Some(node_a) = &l1_ref.next {
            let mut num = node_a.val + add;
            if let Some(node_b) = &l2_ref.next {
                num += node_b.val;
                l2_ref = &node_b;
            }
            cur_node.next = Some(Box::new(ListNode::new(num % 10)));
            cur_node = cur_node.next.as_mut().unwrap();
            add = num / 10;
            l1_ref = &node_a;
        }
        while let Some(node_b) = &l2_ref.next {
            let num = node_b.val + add;
            cur_node.next = Some(Box::new(ListNode::new(num % 10)));
            cur_node = cur_node.next.as_mut().unwrap();
            add = num / 10;
            l2_ref = &node_b;
        }
        if (1 == add) {
            cur_node.next = Some(Box::new(ListNode::new(add)));
        }

        Some(res)
    }
}
