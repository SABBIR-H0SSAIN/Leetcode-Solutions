# Author: Sabbir Hossain
# Problem Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses

class Solution(object):
    def reverseParentheses(self, s):
        """
        :type s: str
        :rtype: str
        """
        pairs=[0]*len(s)
        open_stack=[]
        
        for i in range(len(s)):
            if s[i] == '(':
                open_stack.append(i)
            elif s[i] == ')':
                j=open_stack.pop()
                pairs[i]=j
                pairs[j]=i
        
        i,direction,res = 0,1,[]
        
        while i < len(s):
            if s[i] == "(" or s[i] == ")":
               i=pairs[i]
               direction=-direction
            else:
                res.append(s[i])
            i+=direction
        return "". join(res)  