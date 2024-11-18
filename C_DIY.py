from collections import Counter

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    t = int(data[0])  # Number of test cases
    idx = 1
    results = []
    
    for _ in range(t):
        n = int(data[idx])
        idx += 1
        a = list(map(int, data[idx:idx + n]))
        idx += n
        
        # Count frequencies
        freq = Counter(a)
        candidates = [x for x in freq if freq[x] >= 2]
        
        if len(candidates) < 2:
            # Not enough candidates to form a rectangle
            results.append("NO")
            continue

        # Sort candidates to process them in a fixed order
        candidates.sort()

        # Track the best rectangle with minimal ratio of side lengths
        best_ratio = float('inf')
        best_rect = None

        # Check all pairs of candidates
        for i in range(len(candidates) - 1):
            x1 = candidates[i]
            x2 = candidates[i + 1]

            # Ensure each number can form at least two sides
            if freq[x1] >= 4:
                # Degenerate rectangle using a single number
                best_rect = [x1, x1, x1, x1]
                break
            if freq[x2] >= 4:
                # Degenerate rectangle using a single number
                best_rect = [x2, x2, x2, x2]
                break
            
            if freq[x1] >= 2 and freq[x2] >= 2:
                side1 = abs(x1 - x2)
                ratio = side1  # Simplified ratio, side2 = 1 for effective calculation

                if ratio < best_ratio:
                    best_ratio = ratio
                    best_rect = [x1, x1, x2, x2]

        # Output results
        if best_rect:
            results.append("YES")
            x1, x2 = best_rect[0], best_rect[2]
            results.append(f"{x1} {x1} {x1} {x2} {x2} {x1} {x2} {x2}")
        else:
            results.append("NO")
    
    sys.stdout.write("\n".join(results) + "\n")
