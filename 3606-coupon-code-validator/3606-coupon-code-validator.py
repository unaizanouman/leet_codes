class Solution:
    def validateCoupons(self, code, businessLine, isActive):
        order = ["electronics", "grocery", "pharmacy", "restaurant"]
        rank = {b: i for i, b in enumerate(order)}
        
        valid = []
        
        for c, b, active in zip(code, businessLine, isActive):
            if not active:
                continue
            if b not in rank:
                continue
            if not c:
                continue
            
            # check alphanumeric or underscore only
            ok = True
            for ch in c:
                if not (ch.isalnum() or ch == "_"):
                    ok = False
                    break
            if not ok:
                continue
            
            valid.append((rank[b], c))
        
        valid.sort()
        return [c for _, c in valid]
