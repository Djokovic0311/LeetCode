class Solution {
    public int getNumberOfBacklogOrders(int[][] orders) {
        PriorityQueue<int[]> sell= new PriorityQueue<>((a,b)->(a[0]-b[0]));
        PriorityQueue<int[]> buy= new PriorityQueue<>((a,b)->(b[0]-a[0]));
        for(int [] order : orders){
            if(order[2]==0){
                int n = order[1];
                    while(n>0){
                        if(!sell.isEmpty() && sell.peek()[0] <= order[0]){
                            int[] val = sell.poll();
                            if((val[1]-n)>0) {
                                sell.add(new int[]{val[0], val[1]-n, val[2]});
                                n=0;   
                            } else {
                                n=n-val[1];
                            }
                        } else {
                            buy.add(new int[]{order[0], n, order[1]});
                            n=0;
                        }
                    }
            } else {
                int n = order[1];
                    while(n>0){
                        if(!buy.isEmpty() && buy.peek()[0] >= order[0]){
                            int[] val = buy.poll();
                            if((val[1]-n)>0) {
                                buy.add(new int[]{val[0], val[1]-n, val[2]});
                                n=0;   
                            } else {
                                n=n-val[1];
                            }
                        } else {
                            sell.add(new int[]{order[0], n, order[1]});
                            n=0;
                        }
                    }
            }
        }
        int res = 0, mod = 1000000007;
        for (int[] o : sell)
            res = (res + o[1]) % mod;
        for (int[] o : buy)
            res = (res + o[1]) % mod;
        return res;
    }
}
