/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        ListNode* temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }        
        int numNodes=len/k; 
        int extra=len%k;  
        int i=0;
        vector<ListNode*> res;
        temp=head;
        while(temp)
        {
            res.push_back(temp);
            //get the numNodes and make the last node next to NULL
            int currLen=1;
            while(currLen<numNodes)
            {
                temp=temp->next;
                currLen++;
            }
            if(extra>0 && len>k)
            {
                temp=temp->next;
                extra--;
            }
            ListNode* x=temp->next;
            temp->next=NULL;
            temp=x;
        }
        while(len<k)
        {
            res.push_back(NULL);
            len++;
        }
        return res;
    }
};
