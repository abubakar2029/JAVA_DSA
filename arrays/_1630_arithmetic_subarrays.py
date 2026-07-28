class Solution:
    def checkArithmeticSubarrays(
        self, nums: List[int], l: List[int], r: List[int]
    ) -> List[bool]:


        # slice the subarray, according to query
        # sort the subarray
        # check every two consecutive elements
        # if not put False there and break
        # if the pointer goes beyond the list length put True there

        answer = []
        for i1, i2 in zip(l, r):
            sub_arr = nums[i1 : i2 + 1]

            sub_arr.sort()

            isArthmetic = True
            diff = sub_arr[1] - sub_arr[0]
            for i in range(1, len(sub_arr) - 1):
                if sub_arr[i + 1] - sub_arr[i] != diff:
                    isArthmetic = False
                    break

            answer.append(isArthmetic)

        return answer
