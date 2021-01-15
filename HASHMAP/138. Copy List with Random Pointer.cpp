/*138. Copy List with Random Pointer
Add to List

Share
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
 

Example 1:

Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:

Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:

Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
Example 4:

Input: head = []
Output: []
Explanation: Given linked list is empty (null pointer), so return null.
Constraints:

-10000 <= Node.val <= 10000
Node.random is null or pointing to a node in the linked list.
Number of Nodes will not exceed 1000.*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// random is index, next for nex pointer 
// Key points: // need to create new node at every step!!! and use a map to keep track of copy!!
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node* ,Node* > mp;
        Node* cur = head;//node
        // copy all nodes first 
        //用map复制所有到node
        while(cur){
            // attention to the way to create new node
          Node* newNode = new Node(cur->val,NULL,NULL);  //create new node at every step 
          mp[cur] = newNode ;   //mymap.insert (it, std::pair<char,int>('b',300));  too complex
            // put newnode into map, so later we can use map to connect copied node
          cur = cur->next;// just used for copy nodes
        }
       // now need to connect all the copies nodes together 
        cur = head;// 复制完之后 把cur重新移到开头
       
       //把所有的node串起来，注意需要把一个node里的value和两个pointer都要分别串起来
       // mp[cur]->random curmap 到的此新node对应的下一个node就是 原cur->random 所map到的新node
        while(cur){//mp[cur->next]; pay attention to the way we copy the the node contend!![cur->next] vs [cur]
            mp[cur]->next= mp[cur->next];
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
            }
        return mp[head];//map[head]; corresponding to the head node of the copied list
    }
};
/*
     unordered_map nodeMap;
        Node* cur=head;
        while(cur!=NULL){
            nodeMap[cur]=new Node(cur->val,NULL,NULL);
            cur=cur->next;
        }
        cur=head;
        while(cur!=NULL){
            Node* temp=nodeMap[cur];
            temp->next=nodeMap[cur->next];
            nodeMap[cur]->next=nodeMap[cur->next];
            nodeMap[cur]->random=nodeMap[cur->random];
            
            cur=cur->next;
        }
        return nodeMap[head];
    }
	*/