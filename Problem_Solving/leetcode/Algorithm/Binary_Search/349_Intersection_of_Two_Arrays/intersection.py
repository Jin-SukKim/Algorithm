import bisect


class Solution:
    # brute-force는 O(n^2)이나 이진 검색을 활용하면 O(n log n)의 시간 복잡도가 된다.
    
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        results: Set = set()
        # 이진 검색을 위해 정렬
        nums2.sort()
        # 순차 반복 O(n)
        for n1 in nums1:
            # 이진 검색으로 일치 여부 판별 O(log n)
            i2 = bisect.bisect_left(nums2, n1)
            if len(nums2) > 0 and len(nums2) > i2 and n1 == nums2[i2]:
                results.add(n1)
                
        return results