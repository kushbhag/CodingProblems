// Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


 


int main(){
    struct TreeNode seven = {7, NULL, NULL};
    struct TreeNode four = {4, NULL, NULL};
    struct TreeNode zero = {0, NULL, NULL};
    struct TreeNode eight = {8, NULL, NULL};
    struct TreeNode six = {6, NULL, NULL};
    struct TreeNode two = {2, &seven, &four};
    struct TreeNode five = {5, &six, &two};
    struct TreeNode one = {1, &zero, &eight};
    struct TreeNode three = {3, &five, &one};

    struct TreeNode *ans = lowestCommonAncestor (&three, &zero, &four);
    printf ("%d\n", ans->val);
}