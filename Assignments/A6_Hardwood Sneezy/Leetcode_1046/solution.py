class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        # Convert to a max-heap by negating the values
        max_heap = [-stone for stone in stones]
        heapq.heapify(max_heap)
        
        # Process stones until one or none are left
        while len(max_heap) > 1:
            # Extract the two heaviest stones
            stone1 = -heapq.heappop(max_heap)  # Largest stone
            stone2 = -heapq.heappop(max_heap)  # Second largest stone
            
            # If they are not equal, push the difference back
            if stone1 != stone2:
                heapq.heappush(max_heap, -(stone1 - stone2))
        
        # Return the weight of the last stone, or 0 if no stones left
        return -max_heap[0] if max_heap else 0
