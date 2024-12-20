/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var mergeNodes = function(head) {
    let result = new ListNode();
    let itterator = head.next;
    let resultItterator = result;
    let val = 0;

    while (itterator != null){
        if (itterator.val == 0){
            resultItterator.val = val;
            if (itterator.next != null){
                let temp = new ListNode();
                resultItterator.next = temp;
                resultItterator = resultItterator.next;
            }
            val = 0;
        }
        else{
            val += itterator.val;
        }
        itterator = itterator.next;
    }
    return result;
};