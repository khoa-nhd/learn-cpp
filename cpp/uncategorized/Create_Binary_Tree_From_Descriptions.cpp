/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    #define maxN 100005
    struct node{
        int cha = -1;
        int phai = -1;
        int trai = -1;
    };
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        node a[maxN];
        TreeNode* head;
        for(int i = 0; i < descriptions.size(); ++i){
            if(descriptions[i][2]) a[descriptions[i][0]].trai = descriptions[i][1];
            else a[descriptions[i][0]].phai = descriptions[i][1];
            a[descriptions[i][1]].cha = descriptions[i][0];
        }
        queue<TreeNode*> q;
        for(int i = 0; i < maxN; ++i){
            if(a[i].cha == -1 && (a[i].phai != -1 || a[i].trai != -1)){
                head = new TreeNode(i);
                q.push(head);
            }
        }
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(a[curr->val].trai != -1){
                curr->left = new TreeNode(a[curr->val].trai);
                q.push(curr->left);
            }
            if(a[curr->val].phai != -1){
                curr->right = new TreeNode(a[curr->val].phai);
                q.push(curr->right);
            }
        }
        return head;
    }
};