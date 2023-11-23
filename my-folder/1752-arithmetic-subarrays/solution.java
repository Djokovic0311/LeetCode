class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        int m = l.length;
        ArrayList<Boolean> res = new ArrayList<>();
        for(int i=0; i< m ;i++)
            res.add(isArithmetic(nums,l[i],r[i]));
        return res;
    }

    private boolean isArithmetic(int[] nums, int start, int end) {
        int[] arr = new int[end-start+1];
        int k = 0;
        for(int i = start; i <= end; i++) {
            arr[k++] = nums[i];
        }

        Arrays.sort(arr);
        int diff = arr[1]- arr[0];
        for(int i = 0; i < arr.length-1; i++) {
            if(arr[i+1] - arr[i] != diff)
                return false;
        }

        return true;
    }
}
