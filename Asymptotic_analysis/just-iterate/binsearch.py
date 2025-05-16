
def binsearch(nums, n):
    lo, hi = 0, len(nums)
    while hi > lo:
        mid = (lo + hi) // 2   # still in range [lo, hi)
        x = nums[mid]
        if x == n:
            return mid
        if n < x:
            hi = mid
        if n > x:
            lo = mid + 1
    return None


if __name__ == '__main__':
    a = (0, 1, 3, 4)
    b = (-5, -2, 0)
    cases = (
        # find in any position, even size
        (a, 0, 0),
        (a, 1, 1),
        (a, 3, 2),
        (a, 4, 3),
        # find in any position, odd size
        (b, -5, 0),
        (b, -2, 1),
        (b, 0, 2),
        # fail to find
        (a, 2, None),
        (b, -3, None),
    )
    for nums, n, exp in cases:
        assert binsearch(nums, n) == exp
    print('ok')
