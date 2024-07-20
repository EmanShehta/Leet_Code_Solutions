class Solution:
   def maximumCostSubstring(self, a: str, c: str, x: List[int]) -> int:
        y=[]
        for i in a:
            if i in c: y.append(x[c.index(i)])
            else: y.append(ord(i)-96)
        s=t=0
        for i in y:
            t=max(t,0)
            s=max(s,t)
            t+=i
        return max(s,t,0)