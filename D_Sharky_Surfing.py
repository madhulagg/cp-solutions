import heapq

def min_power_ups_to_finish(n, m, L, hurdles, powerups):
    current_position = 1
    jump_power = 1
    powerup_idx = 0
    powerups_heap = []
    powerup_count = 0
    
    # Step 1: Process hurdles and power-ups
    for i in range(n):
        l, r = hurdles[i]
        
        # While the current position is within the hurdle range, check power-ups
        while current_position < l:
            # Collect all power-ups up to current_position
            while powerup_idx < m and powerups[powerup_idx][0] <= current_position:
                heapq.heappush(powerups_heap, -powerups[powerup_idx][1])  # Store power-ups in max-heap (negate values)
                powerup_idx += 1

            # Try to move forward
            if current_position + jump_power >= l:
                break
            
            # We can't jump far enough, so we need to use power-ups
            if not powerups_heap:
                return -1  # No more power-ups, and we cannot jump far enough
            
            # Collect the largest available power-up
            max_power_up = -heapq.heappop(powerups_heap)  # Get the max power-up
            jump_power += max_power_up
            powerup_count += 1
        
        # Now move to the next hurdle
        if current_position + jump_power < l:
            return -1  # If we can't even make it to the next hurdle
        
        # Update current position
        current_position = r + 1  # Jump after the current hurdle
    
    # Check if we can jump to the end
    while current_position < L:
        while powerup_idx < m and powerups[powerup_idx][0] <= current_position:
            heapq.heappush(powerups_heap, -powerups[powerup_idx][1])
            powerup_idx += 1
        
        if current_position + jump_power >= L:
            break
        
        if not powerups_heap:
            return -1
        
        max_power_up = -heapq.heappop(powerups_heap)
        jump_power += max_power_up
        powerup_count += 1
    
    return powerup_count

def solve():
    t = int(input())
    for _ in range(t):
        n, m, L = map(int, input().split())
        
        hurdles = [tuple(map(int, input().split())) for _ in range(n)]
        powerups = [tuple(map(int, input().split())) for _ in range(m)]
        
        result = min_power_ups_to_finish(n, m, L, hurdles, powerups)
        print(result)

