// Alternate Link to question on Hackerrank
// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem?isFullScreen=true

void reversePrint(SinglyLinkedListNode* head) {
    if (head == NULL) {
        return;
    }
    reversePrint(head->next);
    cout << head->data << "\n";
}