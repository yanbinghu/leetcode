/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(NULL == head)
        return NULL;
    struct ListNode* pTemp = head;
    struct ListNode* pNode = NULL;
    struct ListNode* preNode = head;
    struct ListNode* temp = NULL;
    while(NULL != pTemp && NULL != pTemp->next)
    {
        /*发现相同，删除所有相关的*/
        if(pTemp->val == pTemp->next->val)
        {
            /*删除之后的相同值节点*/
            temp = pTemp->next;
            while(NULL != temp)
            {
                if(temp->val == pTemp->val)
                {
                    if(temp == pTemp->next)
                    {
                        pNode = temp->next;
                        free(temp);
                        pTemp->next = pNode;
                        temp = pNode;
                    }
                    else
                    {
                        pNode = temp->next;
                        free(temp);
                        temp = pNode;
                    }
                }
                else
                {
                    temp = temp->next;
                }
                
            }
            /*当前节点是头节点，删除头节点*/
            if(head == pTemp)
            {
                pNode = head;
                head = pTemp->next;
                free(pNode);
                preNode = head;
                pTemp = head;
            }
            else
            {
                pNode = pTemp->next;
                
                preNode->next = pTemp->next;
                //printf("delete aaaa %d\n",pTemp->val);
                free(pTemp);
                pTemp = pNode;
            }

        }
        else
        {

            preNode = pTemp;
            pTemp = pTemp->next;
        }
    }
    return head;
}