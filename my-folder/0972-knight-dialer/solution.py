class Solution:
    def knightDialer(self, n: int) -> int:
        
        neighbors = {
            0:(4,6),
            1:(6,8),
            2:(7,9),
            3:(4,8),
            4:(0,3,9),
            5:(),
            6:(0,1,7),
            7:(2,6),
            8:(1,3),
            9:(2,4)
        }
        current_counts = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
        for _ in range(n-1):
            next_counts = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
            for src_key in range(10):
                for dst_key in neighbors[src_key]:
                    next_counts[dst_key] = (next_counts[dst_key] + current_counts[src_key]) % (10**9 + 7)
            current_counts = next_counts
        return sum(current_counts) % (10**9 + 7)

