# 퀵 정렬 개선 알고리즘
def sortColors(nums: list[int]) -> None:
    red, white, blue = 0, 0, len(nums)
    
    while white < blue:
        if nums[white] < 1:
            nums[red], nums[white] = nums[white], nums[red]
            white += 1
            red += 1
        elif nums[white] > 1:
            blue -= 1
            nums[white], nums[blue] = nums[blue], nums[white]
        else:
            white += 1