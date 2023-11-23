class Solution {
    public List<Integer> transformArray(int[] arr) {
        boolean changed = true;
        int[] temp = arr.clone();

        while (changed) {
            changed = false;
            for (int i = 1; i < arr.length - 1; i++) {
                if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                    temp[i]--;
                    changed = true;
                } else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                    temp[i]++;
                    changed = true;
                }
            }
            arr = temp.clone();
        }

        List<Integer> result = new ArrayList<>();
        for (int value : arr) {
            result.add(value);
        }

        return result;
    }
}
